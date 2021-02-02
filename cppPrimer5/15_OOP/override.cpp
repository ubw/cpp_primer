#include <iostream>

using namespace std;

class BASE{
private:
int b;

public:
void foo1();
virtual void foo2();
};

class DERIVED: public BASE{
private:
int d;

public:
//c++11 override 会检查是否可以重写基类的方法，不行的话会报错
//1. error: ‘void DERIVED::foo1()’ marked override, but does not override
// void foo1() override;
void foo1() override;
//2.  error: ‘void DERIVED::foo2(int)’ marked override, but does not override
// void foo2(int i) override;
void foo2(int i) override;
};


int main()
{
    BASE b;
    DERIVED d;
}
