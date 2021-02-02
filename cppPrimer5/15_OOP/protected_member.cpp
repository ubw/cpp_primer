#include <iostream>
#include <memory>

using namespace std;

class BASE{
protected:
int blue;

public:
BASE():blue(1){
    cout << "BASE()" << endl;
};

};

class DERIVED:public BASE{
public:
    //1. 派生类对象只可以通过派生类对象来访问基类对象的protected成员
    //2. 派生类对象不能通过基类对象来访问基类对象的protected成员
    //void foo(BASE b){
    void foo(DERIVED d){
        cout << d.blue << endl;
    }
};

int main(void)
{
    shared_ptr<DERIVED> sp(new DERIVED());
    BASE b;
    DERIVED d;

    //sp->foo(b);
    sp->foo(d);
}
