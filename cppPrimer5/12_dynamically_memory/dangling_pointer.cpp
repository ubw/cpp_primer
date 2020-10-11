#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    shared_ptr<string> sp(new string("hello dynamically memory, hello smart pointer"));

    string *p = sp.get();

    //1. 空悬指针，get()的使用应该确保不会delete(),一旦delete(),这个sp就是一个空悬指针了
    delete(p);
    //2. Segmentation fault
    cout << *sp << endl;
}
