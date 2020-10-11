#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<string> vs{"hello", "generic", "algorithm", "hello", "reverse_itorator"};

    for(auto it=vs.rbegin(); it !=vs.rend(); it++)
    {
        cout << *it << endl;
    }
}
