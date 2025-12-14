#ifndef STLBASICFUN_H
#define STLBASICFUN_H
#include <iostream>
#include <random>
using namespace std;

template<  typename T >
void MySTL_Init( T & container ){
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(0, 99);

    for( auto & elem : container ){
        elem = dis(gen);
    }
    return;
}

template<  typename T >
void MySTL_Print(const T & container ){
    cout << " elements : ";
    for( const auto & elem : container ){
        cout << elem << " ";
    }
    cout << endl;
    return;
}

#endif // STLBASICFUN_H