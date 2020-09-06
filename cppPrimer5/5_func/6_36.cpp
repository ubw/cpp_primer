#include <iostream>

using namespace std;
using array_reference = int (&)[10];

extern array_reference foo2(array_reference p);
extern auto foo3(array_reference p)->int (&)[10];


int (&foo(int (&p)[10]))[10]
{
    for(int &i: p)
    {
        i = i+1;
    }

    return p;
}
//g++ -std=c++11 6_36.cpp trailing_return_type.cpp  using.cpp
int main(void)
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};

    int (&b)[10] = foo(a);


    for(int i: b)
    {
        cout << i << endl;
    }
    cout << "===========" << endl;

    array_reference c= foo2(a);
    for(int i: c)
    {
        cout << i << endl;
    }
    cout << "===========" << endl;

    auto d = foo3(a);
    for(int i: c)
    {
        cout << i << endl;
    }
  

    return 0;
}
