#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void foo(vector<string> &vs)
{
    cout << "capacity" << vs.capacity() << ",size" << vs.size() << endl;
    for(string i: vs)
    {
        cout << i << ",";
    }
    cout << endl;
}

int main(void)
{
    vector<string> vs{"hello","generic","algorithm","hello","algorithm","sort","unique"};
    foo(vs);

    //1. sort()无返回值
    sort(vs.begin(), vs.end());
    foo(vs);

    //2.  unique() 返回的是不指向重复区域之后的迭代器
    auto it = unique(vs.begin(), vs.end());
    foo(vs);
    cout << *it << endl;

    vs.erase(it, vs.end());
    foo(vs);

    
}
