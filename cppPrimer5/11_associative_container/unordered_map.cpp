#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//1. c++11增加了4个无序的容器，即容器不按字典序排列元素
int main(void)
{
    unordered_map<string, int> um;
    string tmp;

    while(cin >> tmp)
    {
        um[tmp]++;
    }

    for(auto tmp: um)
    {
        cout << tmp.first << "," << tmp.second << endl;
    }
}
