#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    //1. explicit不能拷贝构造，只支持直接初始化
    //shared_ptr<int> sp = new int(1024);
    shared_ptr<int> sp(new int(1024));

    cout << *sp   << endl;
    //1. use_count()调试用的，可能比较慢，查看共享对象的智能指针数量
    cout << sp.use_count() << endl;
}
