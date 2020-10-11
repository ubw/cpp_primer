#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    string tmp;
    //0. 定义一个allocator对象，以及它可以为T类型 的元素分配内存
    allocator<string> a;
    //1. 分配原始的,未构造的内存
    string *s = a.allocate(100); 
    string *ts = s;
    int cnt = 0;
    while(cin >> tmp && cnt++ <=100 )
    {
       //2. 构造一个对象
       a.construct(ts++, tmp);
    }

    cout << "====" << cnt << "=====" << endl;

    for(int i = 0; i < cnt; i++)
    {
        cout << *(s+i) << " ";
    }

    //3. 调用析构函数
    while(ts != s)
        a.destroy(--ts);

    //4. 释放内存
    a.deallocate(s, 100);
}
