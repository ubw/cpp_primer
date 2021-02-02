#include <iostream>
#include <memory>

using namespace std;

class BASE{
public:
    int foo(){
        cout << "BASE" << endl;
    }

    virtual void foo1()
    {
        cout << "virtial BASE:foo1()" << endl;
    }

    void foo2()
    {
        cout << "BASE:foo2()" << endl;
    }

    virtual void foo3()
    {
        cout << "virtial BASE:foo3()" << endl;
    }

};

class DERIVED : public BASE
{
public:
    
//3. c++中因为隐藏的关系子类无法重载父类的方法？像java那样写的话
//隐藏：内层作用域的方法将隐藏外层作用域的方法
    void foo1(int i)
    {
        cout << "DERIVED:foo1(int)" << endl;
    }

    void foo2()
    {
        BASE::foo2();
        cout << "DERIVED:foo2()" << endl; 
    }

    using

};

class DERIVED2 : public DERIVED
{
    void foo1()
    { 
        cout << "DERIVED2:foo1()" << endl;
    }
};

int main(void)
{
    //1. 派生类是属于基类作用域的，如果找不到某个函数，往基类去找
    DERIVED2 d2;
    d2.foo();

    //2. 隐藏了基类的同名函数
    //2.1 同名，虚函数，参数列表不同
    //d2.foo1();
    //2.2 同名，非虚函数,参数列表同
    d2.foo2();

   //4. 隐藏，有但是不能用，其子类依然可以继承被父类隐藏的方法
   shared_ptr<BASE> pb(new BASE());
   shared_ptr<DERIVED2> pd2(new DERIVED2());
   shared_ptr<BASE> p;

   cout << "pb use_cout:" << pb.use_count() << endl;
   cout << "pd2 use_cout:" << pd2.use_count() << endl;
   cout << "p use_cout:" << p.use_count() << endl;
   p = pb;    
   p->foo1();
   p = pd2;
   p->foo1();
   cout << "b use_cout:" << pb.use_count() << endl;
   cout << "d2 use_cout:" << pd2.use_count() << endl;
   cout << "p use_cout:" << p.use_count() << endl;


}
