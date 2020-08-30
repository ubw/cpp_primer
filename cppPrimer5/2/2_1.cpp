#include <iostream>

using namespace std;

int main(void)
{
    short a;
    int   b;
    long  c;
    long long d;


    /*float 1位符号位，8位指数位，23位尾数位*/
    /*double 1位符号位，11位指数位，52位尾数位*/
    /*小数部分表示 : 可以这样:首先将一个小数如:235.725的小数部分取出，即：0.725,将其乘以进制数二进制就乘以2后得到1,如此往复*/
    float e;
    double f;

    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(d)<<endl;
    cout<<sizeof(e)<<endl;
    cout<<sizeof(f)<<endl;

    return 0;

}
