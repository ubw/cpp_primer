#include <iostream>
#include <vector>

using namespace std;

/*1. c++11能返回列表，只要用花括号括起来*/
vector<string> foo(void)
{
    return {"hello", "return", "list"};
}

int main(void)
{
    foo();
    
    /*2. 函数返回值直接做左值*/
    cout << foo().size() << endl;

    for(int i = 0; i < foo().size(); i++)
    {
        cout << foo()[i] << endl;
    }


    return 0;
}
