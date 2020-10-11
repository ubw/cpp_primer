#include<iostream>
#include<utility>

using namespace std;

int main (void)
{
    //1. c++11 move()返回一个右值引用
    int i = 1024;

    //避免冲突
    int &&rr = std::move(i);

    cout << rr << endl;

    //2. 执行完move之后，原来的变量只可以销毁或者重新赋值，如果使用，会有未定义的行为
    cout << i << endl;
}
