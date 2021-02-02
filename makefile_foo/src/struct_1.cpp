#include <iostream>

using namespace std;

int main(void)
{
    typedef struct {
        char a;
        double b;
    }s_test;

    s_test a;
 
    cout << sizeof(a) << endl;
}
