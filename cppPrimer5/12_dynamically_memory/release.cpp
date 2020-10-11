#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    unique_ptr<string> up(new string("hello dynamically memory, hello smart pointer, hello unique_ptr, hello relese"));

    cout << *up << endl;


    //1. release 可以将调用的unique_ptr指针置为空指针
    auto p = up.release();
    
    
    if (up == nullptr)
    {
        cout << "up == nullptr" << endl;
    }
  
    //2.  release()的返回值是原来的内容

    cout << *p << endl;
    up = nullptr;
}
