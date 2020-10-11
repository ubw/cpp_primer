#include <iostream>

using namespace std;

//数组越界会产生未定义的行为
int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};


    cout << a[11] << endl;
}
