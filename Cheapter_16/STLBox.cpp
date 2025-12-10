#include <iostream>
#include <algorithm>
#include <iterator>

#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>

using namespace std;

template<class T>
void Show(const T & data){
    cout << "Show : ";
    for(const auto & elem : data){
        cout << elem << " ";
    }
    cout << endl;
}

template<class T>
void Init(T & data){
    cout << endl << "Init : ";
    for( auto & elem : data ){
        elem = rand() % 100;
        cout << "." ;
    }
    cout << "Success ! " << endl;
}

template<class T>
void ShowForEach(T & data){
    cout << data << "|";
}

void InitForQueue( queue<int> & data ,int num){
    cout << endl << "Init for queue : ";
    for( int i = 0; i < num; i++ ){
        int val = rand() % 100;
        data.push( val );
        cout << ".";
    }
    cout << "Success ! " << endl;
}

//序列容器 
//vector 自动扩容数组，不支持头插入
void vector_test(){
    cout << "vector test : ";
    vector<int> v1(10);
    Init(v1);

    copy( v1.begin() , v1.end() , ostream_iterator<int>(cout, " ") );
    cout << endl;
//双向
    for_each( v1.rbegin() , v1.rend() , ShowForEach<int> );
    cout << endl;
    Show(v1);
    cout << endl;
}

//deque 双端队列容器，支持头插入
void deque_test(){ 
    cout << "deque test : ";
    deque<int> d1(10);
    Init(d1);

    copy( d1.begin() , d1.end() , ostream_iterator<int>(cout, " ") );
    cout << endl;
    for_each( d1.rbegin() , d1.rend() , ShowForEach<int> );
//可在头插入
    d1.push_front(100);
    copy( d1.begin()+1 , d1.end()-1 , front_insert_iterator< deque<int> > ( d1 )  );
    cout << endl;
    Show(d1);
//双队列特性
    d1.pop_front();
    cout << endl;
    Show(d1);
    cout << endl << endl;
}

//list 链表容器 支持链表特供函数，适合插入删除操作多
void list_test(){
    cout << "list test : ";
    list<int> l1(10);
    list<int> l2(10);
    Init(l1);
    Init(l2);

    Show(l1);
    Show(l2);
//合并两个list，l2并入l1，要求两个list有序
//合并后l2为空
    l1.merge( l2 ); 
    Show(l1);
//删除值为20的元素
    l1.remove(20);
    Show(l1);
//排序
    l1.sort();
    Show(l1);
//l2 插入 next ( l1.begin() , 2) 之前
//l2为空
    l1.splice( next ( l1.begin() , 2) , l2 );
    Show(l1);
//压缩 相邻 的相同元素
    l1.unique();
    Show(l1);
    cout << endl << endl;
}

//queue 标准队列容器 功能性低
void queue_test(){
    cout << "queue test : ";
    queue<int> q1;
    InitForQueue(q1,20);
//标准队列不允许遍历,只允许基础队列操作
    //Show(q1);

}

//priority_queue 优先级队列容器 更大的会放在队列首(使用greater<class name>())
//stack 栈容器 后进先出

//关联容器 与序列无关，内部使用红黑树，排序，查找效率更高
void set_test(){
    cout << "set test : " << endl;
    ostream_iterator<string> Myout (cout, " | ");
    string s1[5] = { "hello" , "world" , "nihao" , "china" , "hello" };
    string s2[5] = { "hello" , "world" , "zhongguo" , "beijing" , "hello" };
    set <string> set1(s1,s1+5);
    set <string> set2(s2,s2+5);
    set <string> set3;
    // set1.insert(s2,s2+5);
//内部自动排序，且不允许重复
    copy( set1.begin() , set1.end() , Myout );                                          cout<<endl;
//并 交 差 集合 输出到输出流打印
    set_union( set1.begin() , set1.end() , set2.begin() , set2.end() , Myout );         cout<<endl;
    set_intersection( set1.begin() , set1.end() , set2.begin() , set2.end() , Myout );  cout<<endl;
    set_difference( set1.begin() , set1.end() , set2.begin() , set2.end() , Myout );    cout<<endl;
//两个集合的并集到 输出到set3
    set_union( set1.begin() , set1.end() , set2.begin() , set2.end() , 
                inserter( set3 , set3.begin() ) );                                      cout<<endl;
//upper_bound + lower_bound 输出自定义区间
    copy( set3.begin() , set3.end() , Myout );                                          cout<<endl;
    copy( set3.upper_bound("hello") , set3.lower_bound("zhongguo") , Myout );           cout<<endl;                       cout<<endl;

}

int main(){
    // vector_test();
    // deque_test();
    // list_test();
    // queue_test();
    // set_test();

    return 1;
}