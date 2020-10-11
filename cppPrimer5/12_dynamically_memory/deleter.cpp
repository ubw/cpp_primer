#include <iostream>
#include <memory>

using namespace std;

void foo(string *)
{
    cout << "delete fuc foo" << endl;
}

int main(void)
{
    shared_ptr<string> sp(new string("hello dynamic memory, hello smart pointer, hello deleter"), [](string *s)->{
        cout << "deleter lambda func" << endl;
    });

    
}
