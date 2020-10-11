#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    set<string> ss;

    //1. 以初始化列表的方式插入
    ss.insert({"Hello", "associative", "container", "insert"});

    vector<string> vs{"Hi", "set", "map"};
    //2. 以迭代器的方式增加
    ss.insert(vs.begin(), vs.end());

    for(auto tmp: ss)
    {
        cout << tmp << endl;
    }

}
