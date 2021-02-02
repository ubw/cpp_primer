#include <iostream>
#include <memory>

using namespace std;

class BASE{
public:
    void foo(){
        cout << "BASE::foo()" << endl;
    }
    BASE(){
        cout << "BASE" << endl;
    }
};

class ABSTRACT_DERIVED : public BASE{
public:
    virtual void foo1() = 0;
    ABSTRACT_DERIVED(){
        cout << "ABSTRACT_DERIVED" << endl;
    }
};

class DERIVED : public ABSTRACT_DERIVED
{
public:
    void foo1(){
        cout << "DERIVED:foo1" << endl;
    }

    DERIVED(){
        cout << "DERIVED()" << endl;
    }
};

int main(void)
{
    shared_ptr<ABSTRACT_DERIVED> ptr(new DERIVED());
    ptr->foo1(); 
}
