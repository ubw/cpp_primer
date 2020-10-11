#include <iostream>
#include <vector>

using namespace std;

class A{
public:
    A(int i):foo(i)
    {
        cout << "A(int i)" << endl;
    };

private:
    int foo;
};

int main(void)
{
    vector<A> i;

    //1. 调整元素大小，如果元素是类类型，必须要提供默认构造函数
    //error: no matching function for call to ‘A::A()’
    i.resize(10);
}
