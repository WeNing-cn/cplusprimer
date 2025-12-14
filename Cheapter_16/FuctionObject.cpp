#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

class FuctionObject{
    private:
        int val;
    public:
        FuctionObject(int v): val(v){}

        int operator()(int x){
            return val + x;
        }
};

void FucObjTest(){
    FuctionObject add10(10);
    FuctionObject add20(20);

    cout << "add10(100): " << add10(100) << endl; // 输出110
    cout << "add20(100): " << add20(100) << endl; // 输出120
    cout << endl;
}

inline auto add100(int x){ return x + 100; };

void Transform(){
    vector<int> used = {1,2,3,4,5};
    vector<int> out = {3,3,3,3};
//use Function as Object /  to transform
//transform( it1 , it2 , it3 ,fun1 )
//range it1 to it2 use fun1 save to it3
    std::transform( used.begin() , used.end() , std::back_inserter(out) , add100 );
    for( auto & e : out)    cout << e << " ";                                           cout << endl;
//transform( it1 , it2 , it3 , it4 , fun1(x,y) )
//range it1 to it2 && it3 to it2(or not) use fun1 save to it3
//warning : out index not warning ED.-1414812752
    std::transform( used.begin(), used.end() , out.begin() ,
                    std::ostream_iterator<int>(cout, "|") , std::plus<int>() );         cout << endl;
//bind1st() is (x,y) -> fun1(value,y)
    std::transform( used.begin(), used.end() ,                         
                std::ostream_iterator<int>(cout, "|") , 
                std::bind1st( std::multiplies<double>() , 2.5 ) );                      cout << endl;
}

int main(){
    FucObjTest();
    Transform();
    
    return 0;
}