#include <iostream>

using namespace std;

class BASE{
private:
int blue;

public:
void foo(){
    cout << "base" << endl;
}
};

class DERIVED:public BASE{
private:
int red;
public:
void foo(){
    //1. 回避函数，利用作用域运算符可以做到这点
    this->BASE::foo();
    cout << "DERIVED" << endl;
}
};

int main(void)
{
    DERIVED *d = new DERIVED();
    d->foo();
    d->BASE::foo();
    delete(d);

}
