#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
    unordered_map<string, int> um;
    string tmp;

    while(cin >> tmp)
    {
        um[tmp]++;
    }

    for(int i = 0; i < um.bucket_count(); i++)
    {
        cout << "=====桶" << i << "=====" << endl;
        //桶i的首元素和尾元素
        for(auto it = um.begin(i); it != um.end(i); it++)
        {
            cout << it->first << endl;
            cout << it->second << endl;
        }
    }
}
