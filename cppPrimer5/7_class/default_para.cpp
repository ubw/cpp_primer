#include <iostream>
#include <string>

using namespace std;

class A{
public:
    A(){};
    /*error: call of overloaded ‘A()’ is ambiguous*/
    //如果为所有实参都定义了默认值，其实也就是有了默认构造函数
    A(string s="hello",int i=10){};
private:
    string str;
    int    i;
};

int main(void)
{
    /*error: call of overloaded ‘A()’ is ambiguous*/
    A a;

    return 0;
}
