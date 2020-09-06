#include <iostream>
#include <typeinfo>
#include <cxxabi.h> //使用abi
#include <cstring>

using namespace std;

int main(void)
{
    /*1. 直接初始化*/
    string s1{"hello"};
    /*2. 拷贝初始化,如果初始值只有一个，两种方式都差不多*/
    string s4 = "hello1";
    /*如果用多个值进行初始化，直接初始化更好*/
    string s5(10, 'c');
    string s2 = s1+" world";

    /*3. string对象和字符字面值，字符串字面值混用时候，+的两侧至少有一个要是string对象*/
    /*error: invalid operands of types ‘const char [6]’ and ‘const char [6]’ to binary ‘operator+’
 * */
    //string s3 = "hello" + "world";

    //s1 + ,是string对象，所以再加上world可以编译通过
    string s6 = s1 +"," +"world";

    /*4. size_type是类string 配套定义的,是无符号的 */
    auto i = s2.size();
    decltype(s2.size()) j = s2.size();
    cout << i << endl;
    cout << typeid(i).name() << endl;
    cout << abi::__cxa_demangle(typeid(i).name(),0,0,0) << endl;
    cout << abi::__cxa_demangle(typeid(j).name(),0,0,0) << endl;


    /*5. string类型比c中的字符串更加方便*/
    string str1("hello world");
    string str2("hello cjw");
 
    cout << (str1 < str2) << endl;

    char * cstr1 = "hello world";
    char * cstr2 = "hello cjw";
    cout << strcmp(cstr1,cstr2) << endl;


    /*6. 兼容性c_str可以返回c风格的字符串*/
    const char *pstr = str1.c_str();
    cout << pstr << endl;

    return 0;

}
