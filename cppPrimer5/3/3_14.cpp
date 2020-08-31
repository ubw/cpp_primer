#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> v;
    for(int i=0; i<100;i++)
    {
        v.push_back(i);
    }

    for(auto i:v)
    {
        cout << i << endl;
    }
    return 0;

}
