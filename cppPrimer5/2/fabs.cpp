#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    double a = 1.1;
    double b = 1.100000000000001;
    if(a == b)
    {
        cout << "a==b" << endl;
    }

    cout << a-b << endl;
    if(a-b < 0.001 && a-b >= -0.0001)
    {
        cout << " 2：a==b" << endl;
    }

    cout << fabs(a-b) << endl;
    if(fabs(a-b) < 0.0001)
    {
        cout << "3: a==b" << endl;
    }

    return 0;
}
