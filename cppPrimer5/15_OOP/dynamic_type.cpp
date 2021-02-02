#include <iostream>

using namespace std;

class BASE{
private:
int red;
int blue;

public:
virtual void foo(){
    cout << "base" << endl;
};
};

class DERIVED: public BASE{
private:
int tmp;

public:
virtual void foo(){
    cout << "derived" << endl;
}
};

int main(void)
{
    //1. 如果是一个普通对象，既不是引用也不是指针。是没有动态绑定的。
    BASE b = BASE();
    BASE c();
    BASE d = DERIVED();
    DERIVED d1 = DERIVED();

    b.foo();
    d.foo();
    //2. 为什么BASE c()，c这个对象就不行呢？？？
    //error: request for member ‘foo’ in ‘c’, which is of non-class type ‘BASE()’
    //因为调用无参构造函数不需要加()，如果是有参的加上括号就行了
    //c.foo();


    BASE &rb = b;
     //3 rd 是一个引用，但是为什么没有多态呢？??因为D并不是派生类，是基类，对派生类做切割了
    BASE &rd = d;
    BASE &rd2 = d1;
    //invalid initialization of non-const reference of type ‘BASE&’ from an rvalue of type ‘DERIVED*’
    //BASE &rd2 = new DERIVED();
    BASE *pd = new DERIVED();

    rb.foo();
    rd.foo();
    rd2.foo();
    pd->foo();
}
