#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec;
    
    cout << "初始状态:" << endl;
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;
    
    cout << "\n逐个添加元素，观察容量变化:" << endl;
    for(int i = 1; i <= 20; i++) {
        vec.push_back(i);
        cout << "添加第" << i << "个元素后 - size: " << vec.size() 
             << ", capacity: " << vec.capacity() << endl;
    }
    
    cout << "\n总结: vector容量增长模式:" << endl;
    cout << "0 -> 1 -> 2 -> 3 -> 4 -> 6 -> 9 -> 13 -> 19 -> 28 -> ..." << endl;
    cout << "大多数STL实现使用1.5倍或2倍的扩容策略" << endl;
    
    return 0;
}
