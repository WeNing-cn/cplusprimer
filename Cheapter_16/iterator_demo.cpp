#include <iostream>

class Node {
public:
    double data;
    Node* next;
    
    Node(double d) : data(d), next(nullptr) {}
};

class Iterator {
    Node* ptr;
public:
    Iterator(Node* p) : ptr(p) {}
    Iterator() : ptr(nullptr) {}

    double operator*() { 
        std::cout << "解引用: ptr指向节点数据=" << ptr->data << std::endl;
        return ptr->data; 
    }
    
    Iterator& operator++() { 
        std::cout << "前置递增: ptr从" << ptr->data << "移动到";
        ptr = ptr->next;
        if(ptr) std::cout << ptr->data;
        else std::cout << "nullptr";
        std::cout << std::endl;
        return *this; 
    }
    
    Iterator operator++(int) {
        std::cout << "后置递增开始: 创建temp副本，当前ptr指向" << ptr->data << std::endl;
        Iterator temp = *this; // 保存当前状态
        ptr = ptr->next;       // 移动到下一个节点
        std::cout << "后置递增结束: 当前ptr指向" << (ptr ? std::to_string(ptr->data) : "nullptr") 
                  << ", 返回temp(指向" << temp.ptr->data << ")" << std::endl;
        return temp;           // 返回递增前的状态
    }
    bool operator!=(const Iterator& other) { return ptr != other.ptr; }
};

int main() {
    // 创建链表: 1.0 -> 2.0 -> 3.0 -> 4.0
    Node* head = new Node(1.0);
    head->next = new Node(2.0);
    head->next->next = new Node(3.0);
    head->next->next->next = new Node(4.0);
    
    std::cout << "=== 使用后置递增的for循环 ===" << std::endl;
    for(Iterator it = head; it != Iterator(nullptr); it++) {
        std::cout << "循环体: 处理节点数据=" << *it << std::endl;
        std::cout << "-------------------" << std::endl;
    }
    
    // 清理内存
    Node* current = head;
    while(current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
