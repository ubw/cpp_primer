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

BASE(){
    cout << "BASE()" << endl;
}
virtual void foo() = 0;

};

class DERIVED : protected BASE{
public:
virtual void foo() override final{
    cout << mem_protected << "," << mem_public << endl;
}

BASE* foo1(){
   //4. 保护继承，在成员函数中派生类向基类的转换,普通指针可以
   BASE* b = new DERIVED();
   //5. 保护继承，为什么成员函数中也无法将派生类转为基类(智能指针)？？？？？
   //shared_ptr<BASE> b1(new DERIVED());
   return b; 
}

DERIVED(int a, int b, int c):BASE(a,b,c){
    cout << "DERIVED(a,b,c)" << endl;
}

DERIVED(){
    cout << "DERIVED()" << endl;
}

};

int main(void)
{
    //1 .error: ‘BASE’ is an inaccessible base of ‘DERIVED’
    //私有继承,保护继承无法将基类指针指向派生类
    shared_ptr<DERIVED> b(new DERIVED(1, 2, 3));    

    b->foo();


    //2. 私有继承，基类的public成员，变成了protected,外面不能访问
    //error: ‘int BASE::mem_public’ is inaccessible
    //cout << b->mem_public << endl;
    

    //3. 同1，保护继承，用户代码无法使用派生类到基类的转换
   //BASE* b1 = new DERIVED();
}
