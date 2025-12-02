#include <iostream>
#include <iterator>  // 包含迭代器特性

class Node {
private:
    double data;
    Node *next;
    
public:
    // 构造函数
    Node(double d, Node* n = nullptr) : data(d), next(n) {}
    
    // 获取数据
    double getData() const { return data; }
    
    // 获取下一个节点
    Node* getNext() const { return next; }
    
    // 设置下一个节点
    void setNext(Node* n) { next = n; }
}; 

class Iterator {
private:
    Node *ptr;
    
public:
    // 迭代器特性定义（符合STL要求）
    using iterator_category = std::forward_iterator_tag;
    using value_type = double;
    using difference_type = std::ptrdiff_t;
    using pointer = double*;
    using reference = double&;

    // 构造函数
    Iterator(Node *p = nullptr) : ptr(p) {}

    // 解引用操作符
    double operator*() const { 
        if (ptr == nullptr) {
            throw std::runtime_error("Dereferencing null iterator");
        }
        return ptr->getData(); 
    }
    
    // 前置递增操作符
    Iterator& operator++() { 
        if (ptr != nullptr) {
            ptr = ptr->getNext();
        }
        return *this; 
    }
    
    // 后置递增操作符
    Iterator operator++(int) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }
    
    // 相等比较操作符
    bool operator==(const Iterator& other) const {
        return ptr == other.ptr;
    }
    
    // 不等比较操作符
    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }
    
    // 获取底层指针（用于调试）
    Node* getPtr() const { return ptr; }
};

// 示例使用函数
void demonstrateIterator() {
    // 创建链表: 1.0 -> 2.0 -> 3.0
    Node* node3 = new Node(3.0);
    Node* node2 = new Node(2.0, node3);
    Node* node1 = new Node(1.0, node2);
    
    // 使用迭代器遍历链表
    std::cout << "遍历链表: ";
    for (Iterator it = node1; it != Iterator(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 清理内存
    delete node1;
    delete node2;
    delete node3;
}

int main() {
    demonstrateIterator();
    return 0;
}
