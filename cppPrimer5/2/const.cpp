#include <iostream>

int main(void)
{
    /*顶层const,可以表示任意的对象是常量，或者指针本身是常量*/
    const int a = 100;
    /*底层const*/
    const int *p2 = &a;
    /*左边是底层，右边是顶层*/
    const int *const p3 = p2;


    /*p2,p3指向的对象类型相同，顶层部分const不影响*/
    p2 = p3; 


    /*不允许给只读变量复制，也就不能定义一个非常量指针和引用来试图改变该常量*/
    /*对象拷贝时候，顶层const往往不受什么影响，而底层const不能忽视*/

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
    
    return 0;
}
