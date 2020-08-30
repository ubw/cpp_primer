#include <iostream>

using namespace std;


int main(void)
{
    /*typedef修饰复合类型，注意不能错误替代原本的*/
    /*pInt 是指向int的指针，const pInt则是指向int的常量指针*/
    typedef int *pInt;
    int b = 10;
    const pInt cint = &b;

    cout << b <<endl;
    *cint = 20;
    cout << b <<endl;

    const int * cint2 = &b;
    /*assignment of read-only location ‘* cint2’*/
    //*cint2 = 30;


    return 0;
}
