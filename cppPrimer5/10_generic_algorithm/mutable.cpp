#include <iostream>


using namespace std;

int main(void)
{
    int i = 10;
    //1. = 放在捕获列表中，表示值捕获
    //2. 值拷贝，lambda不会修改它的值，除非加上mutable关键字 
    auto func = [=]() mutable {return ++i;};


    cout << func() << endl;
}
