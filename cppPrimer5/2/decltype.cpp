#include <iostream>

using namespace std;
int getSize();

int main(void)
{
    /*类型申明符 decltype*/
    /*1.decltype分析表达式的类型，并不实际执行,所以虽然没有定义只有声明，编译不会报错*/
    decltype(getSize()) size = 0;

    /*decltype和auto不同，处理顶层const和引用的方式*/
    const int ci = 10;
    /*2.decltyp不会忽略顶层const*/
    /*error: uninitialized const ‘d’ [-fpermissive]*/
    //decltype(ci) d;

    /*3.decltyp处理引用,返回的是引用类型而不是引用的对象类型*/
    int i = 20;
    int &r = i;
    /*error: ‘dr’ declared as reference but not initialized*/
    //decltype(r) dr;

    /*4. decltype处理解引用，返回的也是引用类型*/
    int *p = &i;
    /*error: ‘r2’ declared as reference but not initialized*/
    //decltype(*p) r2;


    /*5. decltype(()) 双括号永远是引用类型，单括号要看括号里的是啥，如果是引用才是引用*/
    decltype((i)) r1 = i;
    cout <<"i :p"<<&i<<endl;
    cout <<"r1:p"<<&r1<<endl;

    /*6.  赋值产生引用的典型表达式，引用的类型就是左值的类型，因为decltype只是分析，赋值不会执行*/
    decltype(i=30) r2 = i;
    cout <<"i  :"<<i<<endl;
    cout <<"r2:&r2 :"<<&r2<<endl;

    /*7. 数组作为decltype初值，推断得到的类型也是数组*/
    int array[10]{0,1,2,3,4,5,6,7,8,9};
    decltype(array) array2 = {1,3,5,7,9,11,13,15,17,19};
    for(int i:array2)
    {
        cout << i << endl;
    }
  
    /*8. decltype 因为不会退化数组从而变成指针，sizeof也不会，除非他本身就是指针，比如说通过函数数组退化成了指针，但是写成数组的样式。所以如果decltype+数组想要变成指针或者引用，得另外加上*/
    decltype(array) &array8 = array;
    for(int i:array8)
    {
        cout <<"=-====8=====" <<  i << endl;
    }

    return 0;

}
