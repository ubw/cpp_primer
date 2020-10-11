#include <iostream>
#include <memory>

using namespace std;

void foo(shared_ptr<int> sp, shared_ptr<int> &ori)
{
    cout << ori.use_count() << endl;
}


int main(void)
{
    shared_ptr<int> sp = make_shared<int> (20);

    cout << *sp  << endl;
 
    foo(sp, sp);

    cout << sp.use_count() << endl;
    cout << *sp  << endl;
    cout << "=========" << endl;

    //1. 如果使用shared_ptr的get()的普通指针创建对象，则认为是独立的，不能形成正确的动态对象共享.会在函数中销毁
    //2. 不要普通指针和智能指针混用
    foo(shared_ptr<int> (sp.get()), sp);
    cout << sp.use_count() << endl;
    cout << *sp  << endl;
    cout << "=========" << endl;

}
