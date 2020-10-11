#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    shared_ptr<string> sp(new string("hello shared_ptr"));

    auto sp2 = sp;

    cout << sp.use_count() << endl;

    //1. 弱智能指针不占用use_count
    weak_ptr<string> wp(sp);

    cout << sp.use_count() << endl;
    cout << wp.use_count() << endl;
}
