#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v;

    cout << v.capacity() << endl;
    v[0] = 1;

    cout << v[0] << endl;
}
