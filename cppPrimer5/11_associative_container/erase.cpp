#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    multimap<string, string> mm;
    string tmp;

    while(cin >> tmp)
    {
        mm.insert({tmp, tmp});
    }

    for(auto it=mm.begin(); it != mm.end(); )
    {
        if(it->first == "hello")
        {
            it = mm.erase(it);
            continue;
        }
        it++;
    }

    //1. 关联容器删除元素，迭代器可以通过返回值拿到
    //2. 和之前为了准备面试题看的不同，这个和顺序容器是一致的
    for(auto p: mm) 
    {
        cout << p.first <<"," << p.second << endl;
    }

}
