#include <iostream>
#include <vector>
#include <list>
//1. 绝大多数算法都定义在了algorithm中
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9,10};
    list<string> ls{"hello", "generic", "algorithm","hello", "cpp"};


    //2. 一般情况下算法不直接操作容器,而是用迭代器,因为泛型算法要和数据结构相分离
    //3. 迭代器范围左闭右开
    //4. 可以判断返回值是否等于第二个参数来判断是否成功
    auto ret = find(vi.begin(), vi.end()-1, 10);
    auto ret2 = find(vi.begin(), vi.end()-1, 11);
    cout << *ret << endl;
    cout << *ret2 << endl;

    //5. find_if()
    // find_if()只支持一元谓词
    //auto func = find_if(vi.begin(), vi.end(), [](int i, int sz){return i<sz;});
}
