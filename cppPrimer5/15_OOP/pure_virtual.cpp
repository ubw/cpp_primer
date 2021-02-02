#include <iostream>
#include <memory>

using namespace std;

class BASE{
protected:
    int member;
public:
    //1. pure virtual函数，定义在虚函数后面=0，表示纯虚函数，有纯虚函数的类是抽象类，不能创建对象。
    virtual void foo() = 0;
    BASE():member(10){
        cout << "BASE()" << endl;
    }
};

//2. 纯虚函数可以在类的外面定义函数的实现
//3. 方法定义在里面和定义在类外面的区别？？定义和实现分开,没区别
//4. 成员函数和非成员函数的定义和区别？？有没有类名限定符号
//5. 纯虚函数和抽象方法的区别？？纯虚函数可以有实现，在类外定义，有实现就有调用这个实现了
void BASE::foo()
{
    cout << member << endl;
    cout << "BASE:foo()" << endl;
}

class DERIVED :public BASE{
public:
    void foo(){
        cout << "DERIVED:foo()" << endl; 
    }

    DERIVED(){
        cout << member << endl;
        cout << "DERIVED()" << endl;
    }
};

int main()
{
    shared_ptr<BASE> b(new DERIVED());
 
    b->foo();
    cout << "=========" << endl;
    b->BASE::foo();

}
