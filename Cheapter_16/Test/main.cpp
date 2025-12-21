/*
vector 适合查找，排序  不适合插入删除
list 适合插入删除  不适合查找，排序
于是将 list 的排序转化为vector在转回来，比较其时间差异
本算法适合于需要插入删除排序，但不适合频繁查找的场景
*/

#include "../STL_Basic_Fun.h"
#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <algorithm>
#define SIZE 1000000

int main(){
// a.
    std::vector<double> vec1 = init_vecRandom<double>(SIZE, 1, 10000);
    //MySTL_Print( vec1 );
// b.
    std::vector<double> vec2 = vec1;
    std::list<double> lst( vec1.begin(), vec1.end() );
    std::list<double> lst2( vec1.begin(), vec1.end() );
// c.
    cout << "vec2 sort : " << ContainerSort_time( vec2 ) << endl;
    auto start = std :: chrono :: steady_clock :: now();
    lst.sort();
    auto end = std :: chrono :: steady_clock :: now();
    cout << "lst sort : " 
         << std :: chrono :: duration_cast<std :: chrono :: milliseconds>(end - start).count()
         << endl;
// d.
    start = std::chrono::steady_clock::now();
    std::vector<double> vec3(lst2.begin(), lst2.end());
    cout << "sort" << endl;
    std::sort(vec3.begin(), vec3.end());
    lst2.resize( vec3.size() );
    cout << "copy" << endl;
    std::copy(vec3.begin(), vec3.end(), lst2.begin()); // 直接拷贝而不是插入
    end = std::chrono::steady_clock::now();
    cout << "lst2 sort : "
         << std :: chrono :: duration_cast<std :: chrono :: milliseconds>(end - start).count()
         << endl;
    return 0;
}