#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //1. list是链表，内存不连续，迭代器没有算数运算,vector好像也不支持啊
    list<int> li{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
    vector<int> vi{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};

    auto it = find(li.rbegin(), li.rend(), 0);
    auto it2 = find(vi.rbegin(), vi.rend(), 0);


    cout << *it << endl;
    cout << *(it.base()) << endl;

    //cout << (int )(it2 - vi.begin()) << endl;
}
