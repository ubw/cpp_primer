#include <iostream>

using namespace std;

class BASE{
private:
    int blue;

public:
    //1. error: ‘void BASE::f1()’ marked final, but is not virtual
    //1. 必须要是virtual才能是final??书上的例子好像不是virtual??
    //void f1() final;
    //2. override/final 都是c++11的新特性
    virtual void f1() final;
    void f2();
};

class DERIVED : public BASE{
private:
    int prize;

public:
    //3. overriding final function ‘virtual void BASE::f1()’
    //     virtual void f1() final;
    //final表示是最后的，不能再继承或覆盖
    void f1();
    void f2();
};

int main(void)
{
    BASE b;
    DERIVED d;
}
