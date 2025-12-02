#include <string>
#include <iostream>
//#include <vector>

using namespace std;

string* init();
void initout(string* & ptr,int size);
int main(){
    string* ptr=init();
    initout(ptr,10);
    return 1;
}

string * init(){
    string* ptr=new string[10];
    ptr[0] = string("1234567890123");
    ptr[1] = string(10,'@');
    ptr[2] = ptr[0] + ptr[1];
//从第15开始
    ptr[3] = string(ptr[2],15);
//从第2开始，到6
    ptr[4] = string( &ptr[3][2] , &ptr[3][6] );
    return ptr;
}
void initout(string* & ptr,int size){
    for( int i=0 ; i<size; i++ ){
        cout << "ptr["<<i<<"] : " << ptr[i] << endl;
    }
    cout << "ptr[0].find(""123"") : " <<    ptr[0].find("123") << endl;
    cout << "ptr[0].find(""123"",5) : " <<  ptr[0].find("123",5) << endl;
    cout << "ptr[0].find('7') : " <<        ptr[0].find('7') << endl;
//从第5开始，找ptr[2].substr(0,2)
    cout << "ptr[0].find(ptr[2],3) : " <<   ptr[0].find(ptr[2].substr(0,2),5) << endl;
    cout << "ptr[0].size() : " << ptr[0].size() << endl;
    cout << "ptr[0].capacity() : " << ptr[0].capacity() << endl  << endl;
    ptr[0] = ptr[0] + "123";
    cout << "ptr[0].size() : " << ptr[0].size() << endl;

    cout << "ptr[0].capacity() : " << ptr[0].capacity() << endl;
//ofstream类中，open（）方法必须以c风格字符串做对象，使用c_str（）方法转换
    cout << "ptr[0].c_str() : " << ptr[0].c_str() << endl;
    return;
}