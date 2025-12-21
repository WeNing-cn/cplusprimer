#ifndef STLBASICFUN_H
#define STLBASICFUN_H
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
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

template<typename T>
std::vector<T> init_vecRandom(const int & size,const int & start,const int & end){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start, end);
    std::vector<T> vec(size);
    for(auto & v : vec)
        v = dis(gen);
    return vec;
}

template<typename T>
double ContainerSort_time( T & container ){
    auto start = std::chrono::steady_clock::now();
    sort( container.begin(), container.end() );
    auto end = std::chrono::steady_clock::now();
    return 
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

#endif // STLBASICFUN_H