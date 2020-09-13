#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    for_each(vi.begin(), vi.end(), [](int &i){cout << i << endl; i = i+1;});
    for_each(vi.begin(), vi.end(), [](int i){cout << i << endl; i = i+1;});

}
