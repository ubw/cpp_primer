#include <iostream>
#include <memory>

using namespace std;

class BASE{
private:
int mem_private;

protected:
int mem_protected;

public:
int mem_public;
BASE(int a, int b, int c):mem_private(a),mem_protected(b), mem_public(c){
    cout << "BASE(a,b,c)" << endl;

}
virtual void foo() = 0;
//默认构造函数
BASE() = default;

};

class DERIVED : private BASE{
public:
virtual void foo() override final{
    cout << mem_protected << "," << mem_public << endl;
}

//2. 无论D如何继承自B，D的成员函数和友元都能用多态
void foo1(){
    BASE *b = new DERIVED();
}

DERIVED(int a, int b, int c):BASE(a,b,c){
    cout << "DERIVED(a,b,c)" << endl;
}

DERIVED(){
    DERIVED(0,0,0);
}
};

class DERIVED_LVL2  : private DERIVED{
public:
void foo2(){
    //3. 如果D继承B是私有继承，则D的派生类不能用多态。
    BASE *b = new DERIVED();
}
};

int main(void)
{
    //error: ‘BASE’ is an inaccessible base of ‘DERIVED’
    //1. 用户代码中，私有继承,保护继承无法将基类指针指向派生类.
    //即用户代码中，非共有继承不能用多态。
    //shared_ptr<BASE> b(new DERIVED(1,2,3));
    

    shared_ptr<DERIVED> d(new DERIVED(1, 2, 3));    
    d->foo();

    //2. 私有继承，基类的public成员，变成了private,外面不能访问
    //error: ‘int BASE::mem_public’ is inaccessible
    //cout << d->mem_public << endl;

    d->foo1();

    DERIVED_LVL2 d2;
    d2.foo2();
}
