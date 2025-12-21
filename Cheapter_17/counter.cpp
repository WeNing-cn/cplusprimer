#include <iostream>
#include <string>
int main(){
    std::string word,str;

    while((std::cin >> word) && word != "P"){
        str += word;
    }
    std::cout << "NUMS ： " << str.size() << std::endl;

    return 1;
}