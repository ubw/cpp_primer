#include <iostream>

using namespace std;

class BASE{
private:
    int blue;

public:
    virtual void foo(int a, int b=9){
         cout << "a:" << a << " b:" << b << endl;
    };
};

class DERIVED : public BASE{
private:
    int red;

public:
    void foo(int a, int b=1){
         cout << "a:" << a << " b:" << b << endl;
    }
};


int main(void)
{
    BASE b;
    DERIVED d;

    b.foo(1);
    d.foo(2);
 
    BASE *b1 = new DERIVED();
    //1. 虚函数如果参数是默认参数，参数会根据静态类型的方法决定,所以如果有默认参数，最好让两者一致。
    b1->foo(3);
    delete(b1);
}
