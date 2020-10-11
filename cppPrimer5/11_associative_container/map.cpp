#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<string, int> mp;
    string word;
    //1. ctrl+c 强制停止    ctrl+z 暂停    ctrl+d EOF

    while(cin >>  word)
    {
       for(int i = 0; i<word.size(); i++)
       {
           word[i] = tolower(word[i]);
           if(ispunct(word[i])) word.erase(i, 1);
       }
       //2. map的增加和修改
        ++mp[word];
    }

    cout << "=======" <<endl;

    for(auto p: mp)
    {
        cout << p.first << " " << p.second << endl;
    }
}
