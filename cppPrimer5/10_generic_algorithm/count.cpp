#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9,1,2,3,3};
    list<string> ls{"hello","genric","hello","algorithm"};

    // 1. 泛型算法 count(), 前两个参数是迭代器范围，最后一个参数是找的值，返回次数
    int ret = count(vi.begin(), vi.end(), 3);
    // 2. 左闭右开
    int ret2 = count(vi.begin(), vi.end()-1, 3);
    int ret3 = count(ls.begin(), ls.end(), "hello");

    cout << ret << endl;
    cout << ret2 << endl;
    cout << ret3 << endl;
}
