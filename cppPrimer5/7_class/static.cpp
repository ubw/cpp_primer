#include <iostream>

using namespace std;

class StaticExample{
public:
    //1. 静态成员不能在类中初始化
    //error: ISO C++ forbids in-class initialization of non-const static member ‘StaticExample::
    //static int i = 4;
    static int j;
    //2. const静态成员可以在类中初始化
    const static int a = 5;
};

int StaticExample::j = 4;

int main(void)
{
    cout << StaticExample::j << endl;
    cout << StaticExample::a << endl;

    //3.如果要赋值给其他变量，需要定义这个的类的const static成员
    // static.cpp:(.text+0x47): undefined reference to `StaticExample::a'
    const int &i = StaticExample::a;

    return 0;

}
