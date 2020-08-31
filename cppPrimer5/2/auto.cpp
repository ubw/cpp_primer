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

    /*2.引用作为auto变量的初始值，推断得到的类型是引用对象的类型，而非引用*/
    int &r =  j;
    auto test = r;
   cout<<"r   ：" <<&r<<endl;
   cout<<"test：" <<&test<<endl;
  
    /*3. 数组作为auto变量的初始值，推断得到的类型是指针，而非数组*/
    int array[10]{0,1,2,3,4,5,6,7,8,9};
    auto p = array;

    *p = 10;
    for(int i: array)
    {
        cout << i << endl;
    }
    

    return 0;
}
