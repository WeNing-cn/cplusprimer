#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#define NUM 11

using namespace std;

//迭代器就是一头一尾两个指针
void VecPrint(const vector<int> &vec){
    cout << "Vec : " ;
    for (auto pd = vec.begin() ; pd != vec.end() ; pd++)
        cout << *pd << " ";
    cout << endl;
}
//capacity()返回容器预留总空间，size()返回容器当前使用空间
inline void VecMemoPrint(const vector<int> &vec){
    cout << "VecCapacity : " << vec.capacity() << " | VecSize : " << vec.size() << endl;
}

void IntCutOne(int &i){
    i = i - 1;
}

int main(){
    vector<int> vec(NUM);
    vector<int> vec1(3,1);
    for ( int i = 0 ; i < NUM ; i++ )
        vec[i] = i;
//STL容器的储存方式是动态分配的连续空间（堆），而数组是静态分配的连续空间(栈)
//初始化有个数的vector不会预留空间
    VecMemoPrint(vec);
//reserve()预留空间
    vec.reserve(12);
    VecMemoPrint(vec);
//pushback()在vector容器最后添加对象
    vec.push_back(100);
    vec.push_back(101);
    VecPrint(vec);
//vector采用翻倍策略预留空间
    VecMemoPrint(vec);
//erase()删除指定范围内的元素，左闭右开
    vec.erase(vec.begin(),vec.begin()+5);
    VecPrint(vec);
//insert()使用模板
    vec.insert(vec.begin(),NUM);                       //插入一个数
    VecPrint(vec);
    vec.insert(vec.begin(),NUM,9);                     //插入num个9
    VecPrint(vec);
    vec.insert(vec.end(),vec1.begin(),vec1.end());     //插入一个区间
    VecPrint(vec);
//foreach()遍历区间并执行函数对象
    for_each(vec.begin(),vec.end(),IntCutOne);
    VecPrint(vec);
//random_shuffle()随机打乱区间内的元素顺序
    random_shuffle(vec.begin(),vec.end());
    VecPrint(vec);
//sort()对区间内的元素进行排序
//使用sort()时，必须保证区间内的元素可排序，否则会出错
//通常定义bool BetterThan(const Type &a,const Type &b)函数作为第三个参数传入
//  sort(vec.begin(),vec.end(),BetterThan);
    sort(vec.begin(),vec.end());
    VecPrint(vec);
//for循环全遍历,专为STL设计
    for( auto & i : vec )
        IntCutOne(i);
    VecPrint(vec);
//copy()拷贝区间内的元素到另一个区间
    cout << "Copy to Ostream : ";
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    return 0;
}