#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    for(int i = 0; i<10; i++)
    {
        v.push_back(i);
    }

    for(auto &i : v)
    {
        if(i%2 == 1)
        {
            i *=2;
        }
    }

    for(auto it=v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
 

