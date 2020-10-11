#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    unique_ptr<string> up(new string("hello, dynamically memory; hello smart pointer; hello unique_ptr; hello reset"));

    cout << *up << endl;

    string *p1 = new string("hello ordenary pointer");
    string *p2;
    int *p3;

    
    // 1. reset 释放up,改为内置类型的指针内容p1
    up.reset(p1);


    cout << *up << endl;

    //2. p2不是空也不是nullptr??????
    if(p3 == nullptr)
    {
        cout << "p3 is nullptr" << endl;
    }

    cout << *p3 << endl;
    cout << *p2 << endl;
}
