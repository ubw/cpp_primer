#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    unordered_map<string, int> um;
    //1. 顺序型容器和关联型容器索引访问的区别，关联型会插入如果没有的话
    um["hello"];

    for(auto p: um)
    {
        cout << p.first << endl;
        cout << p.second << endl;
    }


}
