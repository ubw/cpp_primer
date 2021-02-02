#include <iostream>

using namespace std;

//类内成员初始化是c++11才有的，c++98不支持，意味着初始化很麻烦
class BASE{
private:
int private_base = 0;
protected:
int protected_base = 0;
public:
int public_base = 0;
friend class FOO;

int get_private_base(){
    return private_base;
}

BASE(int a, int b, int c):private_base(a),protected_base(b), public_base(c){}

//当制定了构造函数的时候，需要重新定义无参构造函数？
BASE(){}
};

class DERIVED:public BASE{
private:
int private_derived = 0;
protected:
int protected_derived = 0;
public:
int public_derived = 0;

//？？??????
DERIVED(){
//cout << this->private_base << endl;
cout << "DERIVED(), protected_base" <<  this->protected_base << endl;
cout << "DERIVED(), public_base" << this->public_base << endl;
}

};

class FOO{
public:
void foo1(BASE b){
    //1. X类的友元类Y(X类中声明friend class Y)可以在Y类中使用X类对象的私有成员
    cout << b.public_base << "," << b.protected_base << "," << b.private_base << endl;

}

void foo2(DERIVED d)
{
    //2. 友元不能继承，不可以访问X类的子类的私有成员,保护成员
    //cout << d.public_derived << "," << d.protected_derived << "," << d.private_derived << endl;
    cout << d.public_derived <<  endl;

    //3. 虽然不能访问子类的私有成员，但是可以通过子类访问父类的私有成员（该类是父类的友元因为)
    //子类需要指定调用的父类的构造函数，否则为什么是0,0,4?????类成员未初始化的关系。
    cout << d.public_base << "," << d.protected_base << "," << d.private_base << endl;
}
};

int main(void)
{
    FOO f;
    BASE b(1, 2, 3);
    f.foo1(b);

    DERIVED d;
    f.foo2(d);

    BASE b2 = d;

    cout << "test:" << b2.get_private_base()  << endl;
}
