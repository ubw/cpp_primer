#include <iostream>

using namespace std;

/*initializer_list c++11*/
/*1. 元素是常量不能改*/
int foo(const string str, initializer_list<int> il)
{
    /*要定义初始值，否则会有未定义的值*/
    int sum = 0;
    for(auto it = il.begin(); it != il.end(); it++)
    {
        sum += *it;
    }
    cout << str << sum << endl;
    return sum;
}

int main(void)
{
    foo("calc int sum:", {1,2,3,4,5,6,7,8,9,10});
    return 0;
}
