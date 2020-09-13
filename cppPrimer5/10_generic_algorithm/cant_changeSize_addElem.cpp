#include <iostream>
#include <vector>

using namespace std;

//算法是通过迭代器的
//1. 不能修改容器的大小，back_inserter()类似的是通过迭代器修改的，而非算法本身
//2. 不能增加或者删除容器本身元素，只能修改元素而已从
int main(void)
{
    vector<int> vi;
    cout << "capacity:" << vi.capacity() << ",size:" <<vi.size() << endl;

    vi.reserve(10);
    cout << "capacity:" << vi.capacity() << ",size:" <<vi.size() << endl;

    //无法修改容器内容，因为算法无法增加元素，虽然容量增加但是没有用
    fill_n(vi.begin(), 10, 2);
    cout << "capacity:" << vi.capacity() << ",size:" <<vi.size() << endl;
    for(int i:vi)
    {
        cout << i << endl;
    }
   
}
