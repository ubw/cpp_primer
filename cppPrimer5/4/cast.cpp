#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    double i = 10.25;
    /*1. 和c语言风格的强转一致*/
    double point = static_cast<int> (i)/3;

    cout << point << endl;


    char* cstr = "hello cast";
    const char *p = cstr;
    /*error: invalid static_cast from type ‘const char*’ to type ‘char*’*/
    //char *p2 = static_cast<char*> (p);
    //2. 只有const_cast可以去掉底层const,只能对常量使用
    char *p3 = const_cast<char*>(p);
    
    return 0;
}
