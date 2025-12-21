#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

void CoutBasic(){
    std::ostream & Myout =  std::cout;
//由于cout本身的缓冲区难以调用，直接输出到终端或文件
//所以这里通过重定向缓冲区的方式实现对cout的缓冲区操作
    std::streambuf * old = Myout.rdbuf();
    std::stringstream ss;
//重定向缓冲区到字符串流对象ss
    Myout.rdbuf(ss.rdbuf());
    Myout << "This is a test \n";
//恢复原来的缓冲区以输出到终端查看
    Myout.rdbuf(old);
    Myout << ss.str();
    Myout.rdbuf(ss.rdbuf());
//使用endl push缓冲区，无法删除缓冲区内容，机理与内存声明机制相同
    Myout << "   This is a test \n"<<std::endl;
    Myout.rdbuf(old);
    Myout << ss.str();

//put    write
    Myout.put('A').put('B').put('C').put('\n');
    Myout.write("This is a test write\n",10);
}

void CoutPosition(){
    float fnum = 999.12 ;
    int inum = 1992;
    std::ios_base::fmtflags oldFlags = std::cout.flags();
//设置cout文本化字段的宽度为100，默认右对齐，空白处填充'-'
//width() 和 fill() 只能影响下一个输出操作 。 cpp特性
    std::cout.width(100);
    std::cout.fill('-');
// 10 16 8 
//进制转换对浮点数无效
    std::cout << std::dec << inum << std::endl;
    std::cout << std::hex << inum << std::endl;
    std::cout << std::oct << inum << std::endl;
// setf() 添加格式标志，不会修改当前位为1的标志位 只会0-1
// 两个参数的重载版本更规范，因为它明确了修改的字段
    std::ios_base::fmtflags AdjustLeft_Show0X = 
            std::cout.setf( std::ios_base::showbase |
                            std::ios_base::left , std::ios_base::adjustfield );
    std::ios_base::fmtflags SCI = 
            std::cout.setf( std::ios_base::scientific,std::ios_base::floatfield |
                            AdjustLeft_Show0X );
    std::cout.setf(SCI);
    std::cout << "SCI : ";
    std::cout << fnum << std::endl;
// unsetf() 清除指定的格式标志位 只会1-0    
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << "UNSCI : ";
    std::cout << fnum << std::endl;
// flags() 重新读取所有格式标志
    std::cout.flags(oldFlags);
    std::cout << "oldFlags : ";
    std::cout << fnum << std::endl;
//iomanip 头文件中定义了一些格式化操作符 特别利于分列
    for( int i = 2 ; i < 10 ; i++ ){
        double sqr = sqrt( static_cast<double>(i) );
        std::cout << 
std::setw(5) << std::setfill(' ') << std::left << i <<
std::setw(10) << std::setfill('*') << std::left << sqr 
<< std::endl;
    }
}

void CheckState( const std::iostream::iostate & state ){
    if (state == std::ios::goodbit) {
        std::cout << "goodbit (no error)" << std::endl;
    } else {
        if (state & std::ios::failbit) {
            std::cout << "failbit ";
        }
        if (state & std::ios::badbit) {
            std::cout << "badbit ";
        }
        if (state & std::ios::eofbit) {
            std::cout << "eofbit ";
        }
        std::cout << std::endl;
    }
}

void CinBasic(){
    using std::cin;
    using std::cout;
    using std::endl;

    int num1 = 0 , num2 = 0 , num3 = 0; 
    std::vector<std::string> strs(10);
    char charStr[20];
    std::string strInto = "   aaa"; 
// // 8 16 10 录入
//     cin >> std::oct >> num1;
//     cin >> std::hex >> num2;
//     cin >> std::dec >> num3;
//     cout    << "NUM1 : " << num1 << endl 
//             << "NUM2 : " << num2 << endl
//             << "NUM3 : " << num3 << endl;
// //连续不同类型的输入
//     cin >> charStr >> strs[0] >> num2;
//     cout    << "CHARSTR : " << charStr << endl
//             << "STRS[0] : " << strs[0] << endl
//             << "NUM2 : " << num2 << endl;
//rdstate() 返回流状态
//clear() 清除流状态，可以指定要清除的状态位
//clear( a ) 将状态设置为a
//setstate( a ) 将状态位a设置为1
    std::iostream::iostate state = cin.rdstate();
    CheckState(state);
    cin.clear(std::ios::failbit);
    state = cin.rdstate();
    CheckState(state);
    cin.setstate(std::ios::eofbit);
    state = cin.rdstate();
    CheckState(state);
    cin.clear();
    state = cin.rdstate();
    CheckState(state);
//exceptions() 会将错误抛出为异常
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    try{
    //此处错误会被抛出
        cin >> strInto;
    }catch( std::ios_base::failure & err ){
        cout << "Exception caught : " << err.what() << endl;
    }
    /*
    ...
    // 重置位后才能继续使用cin
    cin.clear();
    cin >> strInto ;
    */


}

void IStreamFuncitons(){
    using std::cin;
    using std::cout;
    using std::endl;

    //cin.get() 文件尾返回false     cin.get(char a) 文件尾返回EOF
    /*
    get(void) 函数用于提取单字符，包括空白字符（如空格、制表符和换行符）。
            它不会跳过空白字符
    get()     函数返回提取的字符，如果到达文件末尾，则返回EOF。
    >>        运算符用于提取非空白字符，并跳过空白字符。
            它返回流对象本身，可以用于链式调用。
    */
    char word;
    std::stringstream ss("This is a test\n of get function\n");
    cin.rdbuf( ss.rdbuf() );
    do{
        cin.get(word);
        cout << word;
    }while( ! cin.eof() );
    
}

int main(){
    // CoutBasic();
    // CoutPosition();
    // CinBasic();
    IStreamFuncitons();
    return 1;
}