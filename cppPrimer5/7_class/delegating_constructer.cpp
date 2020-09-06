#include <iostream>
#include <string>

using namespace std;

class Book{
public:
    Book(int p, string str,int buyNum=1):price(p),id(str),num(buyNum){
        cout << "default construct,price:" << price <<" id:" <<  str <<" num:" << num << endl;
    }
    //warning: delegating constructors only available with -std=c++11 
    //1. 委托构造函数，c++11的新特性
    Book(string str):Book(100,str){
        cout << "delegating construct, price:" << price << " id:" << str << " num:" << num << endl;
    }
private:
    int price;
    string id;
    int num;
};


int main(void)
{
    Book *a = new Book("c++ primer");
    delete(a);

    return 0;
}
