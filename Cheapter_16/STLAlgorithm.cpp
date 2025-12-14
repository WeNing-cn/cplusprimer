#include <iostream>
#include "STL_Basic_Fun.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <valarray>

using namespace std;

void ReplaceTest(){
    cout << "=== Replace Test ===" << endl;
    vector<int> vec(10);
    ostream_iterator< int > Myout( cout , " | ");
    MySTL_Init( vec );
    MySTL_Print( vec );
//normal Replace
    replace( vec.begin(), vec.end(), vec[0], 999 );
    MySTL_Print( vec );
    replace( vec.begin(), vec.end(), 999 , 888 );
    MySTL_Print( vec );
//replace_copy
    replace_copy( vec.begin(), vec.end(), Myout, 888, 777 );    cout << endl;
//replace_if
    replace_if( vec.begin(), vec.end(),
                []( int val ){ return val % 2 == 0; }, -1 );
    MySTL_Print( vec );
//replace_copy_if
    replace_copy_if( vec.begin(), vec.end(),
                     Myout,
                     []( int val ){ return val % 2 != 0; }, -2 );
    cout << endl;
}

void StringTest(){
    cout << "=== String Test ===" << endl;
    string str = "hello world, welcome to china";
    sort( str.begin(), str.end() );
    cout << " sorted string : " << str << endl;
    //while(1){
        next_permutation( str.begin(), str.end() );
        cout << " next_permutation : " << str << endl;
    //}
    cout << endl;
    return;
}

void ValArrayTest(){
    cout << "=== ValArray Test ===" << endl;
    valarray<int> va1(10);
    valarray<int> va2(10);
    MySTL_Init( va1 );
    MySTL_Init( va2 );
    cout << " valarray 1 : ";   MySTL_Print( va1 );
    cout << " valarray 2 : ";   MySTL_Print( va2 );

    valarray<int> va3 = va1 + va2;
    cout << " valarray 3  : ";   MySTL_Print( va3 );
    va3 = sqrt( va3 );
    cout << " valarray 3 sqrt : ";   MySTL_Print( va3 );
// slice make 1 dimensional to 2 dimensional
    valarray<int> va4 = va2[ slice( 0, 2, 1 ) ];
    cout << " valarray 4 slice() : ";   MySTL_Print( va4 );
    va4 = va2[ slice( 2, 2, 1 ) ];
    cout << " valarray 4 slice() : ";   MySTL_Print( va4 );
    va4 = va2[ slice( 4, 2, 1 ) ];
    cout << " valarray 4 slice() : ";   MySTL_Print( va4 );
    va4 = va2[ slice( 6, 2, 1 ) ];
    cout << " valarray 4 slice() : ";   MySTL_Print( va4 );
    va4 = va2[ slice( 8, 2, 1 ) ];
    cout << " valarray 4 slice() : ";   MySTL_Print( va4 );
}

int main(){
    // ReplaceTest();
    // StringTest();
    ValArrayTest();
    return 0;
}