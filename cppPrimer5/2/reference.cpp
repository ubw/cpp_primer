#include <iostream>
using namespace std;
int main(void)
{
    int i = 10, &j = i;

    /*a并不是一个指向引用的指针，因为j已经和i绑定了，所以其实指向的是一个int型变量的指针*/
    int *a = &j;

    cout <<"a : "<< a <<  " *a:"<< *a << endl;


    /*error: cannot declare pointer to ‘int&’*/
    /*不能定义一个指向引用的指针*/
    int &*b = &j;
    
    return 0;
}
