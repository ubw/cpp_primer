#include <iostream>
//back_inserter插入迭代器定义在interator头文件中
#include <iterator>
#include <vector>

using namespace std;

void foo(vector<int> &vi)
{
    cout << "size:" <<vi.size() << "capacity:" << vi.capacity() << endl;
    for(int i: vi)
    {
        cout << i << ","; 
    }

    cout << endl;
}

int main(void)
{
    vector<int> vi;
    foo(vi);

    //2. stl库函数不会使得容器改变大小，back_insert()仅仅是返回了尾后迭代器，改变容器大小的不是算法，而是后续的根据迭代器的操作
    auto it = back_inserter(vi);
    *it = 11;
    //1. 迭代器没有重载[] 符号
    //*it[1] = 12;
     foo(vi);
    *(++it) = 12;
     foo(vi);
}
