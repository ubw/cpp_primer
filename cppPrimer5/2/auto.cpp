#include <iostream>

using namespace std;


int main(void)
{
    const int i = 10;
    /*类型说明符auto*/
    /*1.编译器分析类型,会忽略顶层const,需要的话得自己加*/
    auto j = i;


    j = 20;
    
    cout<<"i: "<<i<<endl;
    cout<<"j: "<<j<<endl;

    /*2.auto处理引用，其实是引用对象的类型，而非引用*/
    int &r =  j;
    auto test = r;
   cout<<"r   ：" <<&r<<endl;
   cout<<"test：" <<&test<<endl;
    

    return 0;
}
