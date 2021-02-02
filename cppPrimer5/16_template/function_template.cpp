#include <iostream>

using namespace std;

//1. template关键字
//2. <>是模板参数列表 template parameter list
//3. 编译的时候会实例化具体的函数
template <typename T1>
int compare(const T1 &tmp1, const T1 &tmp2)
{
    return tmp1-tmp2;
}

int main(void)
{
    cout << compare(1, 2) << endl;;   
    cout << compare(1.22, 3.52) << endl;;   
}
