#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> foo(){
    //1. 用标准库的函数 在动态内存中初始化一个对象，返回一个智能指针指向这个对象
    return make_shared<vector<int>>();
}

//1. c++11不支持函数参数的auto
void foo1(shared_ptr<vector<int>> p)
{
    cout << "enter int into vector which shared_ptr point:" << endl;
    int tmp;
    while(cin >> tmp)
    {
        p->push_back(tmp);
    }
}

void foo2(shared_ptr<vector<int>> p)
{
    cout << "what's in vecrtor:" << endl;
    for(auto i: *p)
    {
        cout << i << endl;
    }
}


int main(void)
{
    shared_ptr<vector<int>> sp = foo();

    foo1(sp);

    foo2(sp);
}
