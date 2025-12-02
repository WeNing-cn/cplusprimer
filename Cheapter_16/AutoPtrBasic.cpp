#include <iostream>
#include <memory>
//智能指针指向的内存应该是堆内存。(new,malloc,class对象等分配的内存)

class Report{
    private:
        std::string str;
    public:
        Report(){std::cout << "Object created!\n";}
        Report(const std::string &s): str(s){std::cout << "Object created!\n";}
        ~Report(){std::cout << "Object deleted!\n";}
        void comment() const {std::cout << str << "\n";}
        friend std::ostream & operator<<(std::ostream & os,const Report & rr){
            os << rr.str;
            return os;
        }
};

std::unique_ptr<Report> getReport(){
    std::unique_ptr<Report> ptr(new Report("Using unique_ptr"));
    return ptr;
}

int main(){
//指针指向的对象被自动删除，堆空间的内存被释放，避免内存泄漏
    std::unique_ptr<Report> ps (new Report("Using unique_ptr"));
    ps->comment();

//对智能指针的赋值，构造。
    std::unique_ptr<Report> ptr;
    Report *p = new Report("Using raw pointer");
    Report *p1 = new Report("Using raw pointer");
    //ptr = p;                              X   类型不匹配
    //std::unique_ptr<Report> ptr1 = p1;    X   类型不匹配
    ptr = std::unique_ptr<Report>(p);//临时对象立即销毁
    std::unique_ptr<Report> ptr1(p1);//之后应手动销毁p1指针，避免空指针悬挂
    p1= nullptr;
//c++11后，可以使用std::move()函数转移所有权
    ptr= std::move(ptr1);
//unique_ptr支持数组类型
    std::unique_ptr<Report[]> ptr2(new Report[10]);
//unique_ptr支持shared_ptr.
    std::unique_ptr<Report> ptr3(new Report);
    std::shared_ptr<Report> sptr1;
    sptr1 = std::move(ptr3);
    //std::shared_ptr<Report> sptr2(ptr3);              X 存在了一段时间，不允许
    std::shared_ptr<Report> sptr2(getReport());//       X 立即销毁的临时对象，允许构造
    return 0;
}