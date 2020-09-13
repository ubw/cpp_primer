#include <iostream>

using namespace std;

int main(void)
{
    int a = 10,b = 20;
    //1. lambda是c++11的新特性
    //2. lambda是一个匿名的函数
    auto f = [](const int &i, const int &j){return i+j; };

    cout << f(a, b) << endl;

    //3. 值捕获, 值捕获的变量在创建时拷贝,之后的修改不会影响
    auto f3 = [a](){return a;};
    cout << f3() << endl;
    a = 99;
    cout << f3() << endl;

    //4. 引用捕获
    auto f4 = [&a](){return a;};
    cout << f4() << endl;
    a = 88;
    cout << f4() << endl;
    

}
