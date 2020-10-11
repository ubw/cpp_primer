#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
    unique_ptr<string> up(new string("hello dynamically memory, hello unique_ptr"));


    //1. unique_ptr不支持普通的赋值和拷贝
    //unique_ptr<string> up2(up);
    //unique_ptr<string> up2 = up;

    //2. 但是可以用普通指针初始化它
    string *p = new string("hello unique_ptr");
    unique_ptr<string> up3(p);

    cout << *up3 << endl;
}
