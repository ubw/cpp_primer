#include <iostream>

using namespace std;

//4. 引用折叠
template<typename T>
void f(T&& t){}

void g(int&& t){}

int main(void)
{
    //1. c++11 右值引用
    int &&rr = 1024;

    cout << rr << endl;

    //2. 右值引用不能绑定左值
    // cannot bind ‘int’ lvalue to ‘int&&’
    int &&rr2 = rr;

    //3. 右值引用也是一个变量,不能绑定到右值引用上,和2不是一个意思么
    // cannot bind ‘int’ lvalue to ‘int&&’
    int &&rr3 = rr;

    f(10);
    int x = 10;
    f(x);

    //5. cannot bind ‘int’ lvalue to ‘int&&’
    g(x);

}
