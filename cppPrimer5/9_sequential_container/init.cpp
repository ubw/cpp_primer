#include <iostream>
#include <vector>
#include <forward_list>
#include <deque>
#include <list>
#include <string>
#include <array>

using namespace std;

int main(void)
{
    vector<const char*> vc{"hello","sequetial","container"};

    //1. c++11新特性 ，单向链表 forward_list
    // error: no matching function for call to ‘std::forward_list<std::basic_string<char> >::forward_list(std::vector<const char*>&)
    //2.  初始化拷贝，必须容器相同，元素相同
    // forward_list<string>  fs(vc);

    //3. 传递迭代器参数来拷贝范围的时候，就不要求容器相同了，元素只要能转也可以。
    forward_list<string> fs(vc.begin(), vc.end());

    for(string s: fs)
    {
        cout << s << endl;
    }

    //4. 只有顺序容器支持的构造函数 ----和大小相关 ---array不支持
    deque<int> di(10,100);
    for(int i:di)
    {
        cout << i << endl;
    }
   
    //5. array的大小是它类型的一部分
    // 初始化如果小于元素个数，只有前面的部分被初始化
    array<double, 10> price = {42};
    // 和内置数组不同，array允许赋值
    array<double, 10> price2 = price;
    for(double tmp: price2)
    {
        cout << tmp << endl;
    }
    

}
