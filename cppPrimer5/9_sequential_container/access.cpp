#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vi = {10,9,8,7,6,5,4,3,2,1,0};

    cout << vi.front() << endl;
    cout << *vi.begin() << endl;
    cout << vi[0] << endl;
    cout << vi.at(0) << endl;
}
