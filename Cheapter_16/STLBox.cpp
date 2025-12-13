#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>  // For modern random number generation

#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

template<typename T1,typename T2>
ostream & operator<<(ostream & os,const pair <T1 , T2> & p){
    os << "{" << p.first << " : " << p.second << "}";
    return os;
}

template<class T>
void Show(const T & data){
    cout << "Show : ";
    for(const auto & elem : data){
        cout << elem << " ";
    }
    cout << endl;
}

template<class T>
void Init(T & data) {
    cout << endl << "Init : ";
    
    // Modern C++ random number generation
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 99);
    
    for (auto & elem : data) {
        elem = dis(gen);
        cout << ".";
    }
    cout << "Success !" << endl;
}

template<class T>
void PrintElement(const T & data) {
    cout << data << "|";
}

void InitForQueue(queue<int> & data, int num) {
    cout << endl << "Init for queue : ";
    
    // Modern C++ random number generation
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 99);
    
    for (int i = 0; i < num; i++) {
        int val = dis(gen);
        data.push(val);
        cout << ".";
    }
    cout << "Success !" << endl;
}

// Sequence containers
// vector: automatically expanding array, does not support front insertion
void vector_test() {
    cout << "vector test : ";
    vector<int> v1(10);
    Init(v1);

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // Bidirectional iteration
    for_each(v1.rbegin(), v1.rend(), PrintElement<int>);
    cout << endl;
    Show(v1);
    cout << endl;
}

// deque: double-ended queue container, supports front insertion
void deque_test() { 
    cout << "deque test : ";
    deque<int> d1(10);
    Init(d1);

    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for_each(d1.rbegin(), d1.rend(), PrintElement<int>);
    
    // Can insert at front
    d1.push_front(100);
    copy(d1.begin() + 1, d1.end() - 1, front_insert_iterator<deque<int>>(d1));
    cout << endl;
    Show(d1);
    
    // Double-ended queue特性
    d1.pop_front();
    cout << endl;
    Show(d1);
    cout << endl << endl;
}

// list: linked list container, supports list-specific functions, suitable for frequent insert/delete operations
void list_test() {
    cout << "list test : ";
    list<int> l1(10);
    list<int> l2(10);
    Init(l1);
    Init(l2);

    Show(l1);
    Show(l2);
    
    // Merge two lists, l2 into l1, requires both lists to be sorted
    // After merge, l2 becomes empty
    l1.merge(l2); 
    Show(l1);
    
    // Remove elements with value 20
    l1.remove(20);
    Show(l1);
    
    // Sort
    l1.sort();
    Show(l1);
    
    // Insert l2 before position next(l1.begin(), 2)
    // l2 is empty
    l1.splice(next(l1.begin(), 2), l2);
    Show(l1);
    
    // Remove consecutive duplicate elements
    l1.unique();
    Show(l1);
    cout << endl << endl;
}

// queue: standard queue container, limited functionality
void queue_test() {
    cout << "queue test : ";
    queue<int> q1;
    InitForQueue(q1, 20);
    
    // Standard queue does not allow traversal, only basic queue operations
    // Show(q1);
}

// priority_queue: priority queue container, larger elements go to front (use greater<class name>())
// stack: stack container, last-in first-out

// Unordered associative containers (hash tables)
// unordered_set: hash-based set, no ordering, faster lookup than set
void unordered_set_test() {
    cout << "unordered_set test : " << endl;
    unordered_set<string> uset1 = {"apple", "banana", "cherry", "date", "elderberry"};
    unordered_set<string> uset2 = {"cherry", "date", "fig", "grape", "honeydew"};
    
    cout << "uset1: ";
    for (const auto& elem : uset1) {
        cout << elem << " ";
    }
    cout << endl;
    
    cout << "uset2: ";
    for (const auto& elem : uset2) {
        cout << elem << " ";
    }
    cout << endl;
    
    // Insert
    uset1.insert("fig");
    cout << "After inserting 'fig': ";
    for (const auto& elem : uset1) {
        cout << elem << " ";
    }
    cout << endl;
    
    // Find
    auto it = uset1.find("banana");
    if (it != uset1.end()) {
        cout << "Found 'banana' in uset1" << endl;
    }
    
    // Bucket interface (hash table specific)
    cout << "Bucket count: " << uset1.bucket_count() << endl;
    cout << "Load factor: " << uset1.load_factor() << endl;
    cout << endl;
}

// unordered_map: hash-based map, no ordering, faster lookup than map
void unordered_map_test() {
    cout << "unordered_map test : " << endl;
    unordered_map<string, int> umap1 = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35},
        {"David", 40}
    };
    
    // Insert using emplace (modern C++)
    umap1.emplace("Eve", 28);
    
    // Range-based for loop
    for (const auto& [name, age] : umap1) {
        cout << name << ": " << age << endl;
    }
    
    // Access elements
    cout << "Alice's age: " << umap1["Alice"] << endl;
    
    // Check if key exists (using find for compatibility with C++11/14/17)
    if (umap1.find("Bob") != umap1.end()) {
        cout << "Bob exists in the map" << endl;
    }
    
    // Modify value
    umap1["Charlie"] = 36;
    cout << "Updated Charlie's age: " << umap1["Charlie"] << endl;
    
    // Iterate with structured binding (C++17)
    cout << "All entries:" << endl;
    for (const auto& [key, value] : umap1) {
        cout << "  " << key << " -> " << value << endl;
    }
    cout << endl;
}

// stack: last-in first-out container
void stack_test() {
    cout << "stack test : " << endl;
    stack<int> s1;
    
    // Push elements
    for (int i = 1; i <= 5; i++) {
        s1.push(i * 10);
        cout << "Pushed: " << i * 10 << endl;
    }
    
    cout << "Top element: " << s1.top() << endl;
    cout << "Stack size: " << s1.size() << endl;
    
    // Pop elements
    while (!s1.empty()) {
        cout << "Popped: " << s1.top() << endl;
        s1.pop();
    }
    cout << endl;
}

// Associative containers: order-independent, internally use red-black tree, efficient for sorting and lookup
// set: one-to-one collection, automatically sorted, no duplicates allowed
void set_test() {
    cout << "set test : " << endl;
    ostream_iterator<string> Myout(cout, " | ");
    string s1[5] = { "hello", "world", "nihao", "china", "hello" };
    string s2[5] = { "hello", "world", "zhongguo", "beijing", "hello" };
    set<string> set1(s1, s1 + 5);
    set<string> set2(s2, s2 + 5);
    set<string> set3;
    // set1.insert(s2, s2 + 5);
    
    // Internally automatically sorted, no duplicates allowed
    copy(set1.begin(), set1.end(), Myout);
    cout << endl;
    
    // Union, intersection, difference sets output to output stream
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), Myout);
    cout << endl;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), Myout);
    cout << endl;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), Myout);
    cout << endl;
    
    // Union of two sets output to set3
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), 
              inserter(set3, set3.begin()));
    cout << endl;
    
    // upper_bound + lower_bound output custom range
    copy(set3.begin(), set3.end(), Myout);
    cout << endl;
    copy(set3.upper_bound("hello"), set3.lower_bound("zhongguo"), Myout);
    cout << endl;
    cout << endl;
}

// multimap: one-to-many collection
void map_test() {
    cout << "map test : " << endl;
    ostream_iterator<pair<const int, string>> MyMulimapOut(cout, " | ");
    multimap<int, string> mmap1;
    
    mmap1.insert(pair<int, string>(1, "one"));
    mmap1.insert(pair<int, string>(2, "two"));
    mmap1.insert(pair<int, string>(1, "first"));
    mmap1.insert(pair<int, string>(3, "three"));
    mmap1.insert(pair<int, string>(4, "four"));
    mmap1.insert(pair<int, string>(5, "five"));
    
    for (const auto & elem : mmap1) {
        cout << elem << " " << endl;
    }
    
    // count(x): find number of elements with key x
    cout << mmap1.count(1) << endl;
    
    // equal_range(x): find range of all elements with key x, returns pair of iterators
    pair<multimap<int, string>::iterator,
         multimap<int, string>::iterator> range = mmap1.equal_range(1);
    for (auto it = range.first; it != range.second; it++)
        cout << *it << " ";
    
    // upper/lower_bound(x): find first/last element with key x (next position)
    cout << endl;
    auto lower = mmap1.lower_bound(2);
    auto upper = mmap1.upper_bound(5);
    for (auto it = lower; it != upper; it++)
        cout << *it << " ";
    cout << endl;
}
int main() {
    //Uncomment to run all tests
    vector_test();
    deque_test();
    list_test();
    queue_test();
    set_test();
    map_test();
    
    //Modern C++ container tests
    unordered_set_test();
    unordered_map_test();
    stack_test();

    return 0;  // Return 0 for successful execution
}
