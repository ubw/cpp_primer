#include <iostream>
//1. pair数据结构定义在utility头文件中
#include <utility>

using namespace std;

pair<string, int> foo()
{
    //2. 返回两个参数
    return make_pair("hello associative container , hello utility, hello pair", 66);
}

int main(void)
{
    pair<string, int>{"hello", 5};

    auto tmp = foo();

    //3. pair的public 成员变量
    cout << tmp.first << endl;
    cout << tmp.second << endl;

    
}
