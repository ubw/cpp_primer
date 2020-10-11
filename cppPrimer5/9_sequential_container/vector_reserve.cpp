#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vi;
    
    cout << "size:" << vi.size() << "capacity:" << vi.capacity();
    // 1. reserve至少分配需求空间一样的大小，可能更大
    vi.reserve(10);
    cout << "size:" << vi.size() << "capacity:" << vi.capacity();

    //2 查看本机vector动态扩容的量级
    for(int i = 0; i < vi.capacity(); i++)
    {
        vi.emplace_back(i);
        cout << "size:" << vi.size() << "capacity:" << vi.capacity() << endl;
    }

    vi.emplace_back(-1);
    cout << "size:" << vi.size() << "capacity:" << vi.capacity() << endl;
}
