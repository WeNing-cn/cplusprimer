#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

template <typename MYSTL>
MYSTL & init( MYSTL& v ){
    for(int i = 0; i < v.size(); i++)
        v[i] = i;
    return v;
}
template <typename MYSTL>
void STLPrint(MYSTL & s){
    copy( s.begin() , s.end() , ostream_iterator< string >(cout , " ") );
    cout << endl;
}

int main(){
    vector<int> v(20);
    v = init( v );
    string s1[4]={"s11","s12","s13","s14"};
    string s2[4]={"s21","s22","s23","s24"};
    vector<string> s3(4);
    deque<string> dq1;
    s3[1]="s31";
//copy()拷贝区间内的元素到另一个区间
//参数3是匿名迭代对象，表示输出到标准输出流cout，每个元素后面跟一个空格
    copy( v.begin(), v.end(), ostream_iterator<int>( cout, " " ) );
    cout << endl;
//rbegin(),rend()是其对应函数的反向版本---reverse_iterator
    copy( v.rbegin() , v.rend() , ostream_iterator<int>( cout, " | " ) );
    cout << endl;
//back_insert_iterator< ClassSTL T >(name) 迭代器，将元素插入到STL容器ClassSTL name的尾部
//front_insert_iterator< ClassSTL T >(name) 迭代器，将元素插入到STL容器ClassSTL name的头部
//insert_iterator< ClassSTL T >(name,pos) 迭代器，将元素插入到STL容器ClassSTL name的pos位置
//vector不支持front_insert_iterator插入方法
//bii基于原容器是否支持pushback
//iii基于原容器是否支持pushfront
    copy( s1 , s1+4 , back_insert_iterator< vector<string> > ( s3 ) );
    copy( s2 , s2+4 , insert_iterator< vector<string> > ( s3 , s3.begin() ) );
    copy( s3.begin() , s3.end() , front_insert_iterator< deque<string> > ( dq1 ) );

    STLPrint(s3);
    STLPrint(dq1);
    return 0;
}
