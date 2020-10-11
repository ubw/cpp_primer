#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vi{1,1,2,2,3,4,5,4,5,6,6,7,7};
    int ret = 0;
    int first = vi[0];
    int second = vi[1];
    
    ret = first ^ second;
    for(int i = 2; i < vi.size(); i++)
    {
       ret = vi[i] ^ ret;
    }
     cout  << ret << endl;

}
