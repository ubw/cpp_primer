#include <iostream>

using namespace std;

int main(void)
{
    /*1. 顶层const,可以表示任意的对象是常量，或者指针本身是常量*/
    const int a = 100;
    /*2. 底层const*/
    const int *p2 = &a;
    /*左边是底层，右边是顶层*/
    const int *const p3 = p2;


    /*p2,p3指向的对象类型相同，顶层部分const不影响*/
    p2 = p3; 


    /*不允许给只读变量复制，也就不能定义一个非常量指针和引用来试图改变该常量*/
    /*3. 对象拷贝时候，顶层const往往不受什么影响，而底层const不能忽视*/

    /*对一个顶层const取地址或者取引用变成了底层const，底层const不能忽略*/
    /*invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]*/
    int *p = &a;
    /*error: invalid initialization of reference of type ‘int&’ from expression of type ‘const int’
 * */
    int &r = a;

    /*对常量取地址是一种底层const*/
    const int *b = &a;
    /*所有的引用const修饰的，都是底层const*/
    const int &c = a;

    /*底层修饰的const限制不能忽略*/
    /*error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]*/
    int *b1 = b;
    /*error: invalid initialization of reference of type ‘int&’ from expression of type ‘const int’
 * */
    int &c1 = c;


    
    /*4.*/
    cout << "可以用字面值初始化一个const引用，但是不能用字面值初始化一个非const引用" << endl;
    const int &a4 = 42;
    /*invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’*/
    int &b4 = 42;

    /*5. 临时量*/
    double dval5 = 3.14;
    // invalid initialization of reference of type ‘int&’ from expression of type
    // int &r5 = dval5;
    const int &r5_1 = dval5;
    
    return 0;
}
