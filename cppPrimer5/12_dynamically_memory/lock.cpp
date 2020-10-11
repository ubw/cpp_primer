#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    shared_ptr<string> sp(new string("hello shared_ptr; hello weak_ptr"));
    weak_ptr<string> wp(sp);
    
    cout << wp.use_count() << endl;
    //sp = nullptr;
    cout << wp.use_count() << endl;

    //1. weak_ptr如果过期了返回空指针，否则返回一个shared_ptr指向的是这块区间
    if(auto sp2 = wp.lock())
    {
        cout << "wp.lock() is not nullptr" << endl;
        cout << "wp.lock() return:" << *sp2 << endl;
    } else {
        cout << "wp.lock() is  nullptr" << endl;
    }
}
