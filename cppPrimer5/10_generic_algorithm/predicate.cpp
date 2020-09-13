#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void foo(vector<string> &ls)
{
    cout << "size:" << ls.size() << ",capacity:" << ls.capacity() << endl;
    for(string s: ls)
    {
        cout << s << ",";
    }
    cout << endl;
}

//2. 第三个参数的定义是什么样的？
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(void)
{
    // list不能sort吗？？
    vector<string> ls{"apple","ibool","hello","ibool", "generic", "algorithm","third", "hello", "func", "predicate","param", "hello", "stable_sort"};

    sort(ls.begin(), ls.end());
    foo(ls);
    //3. 传入第三个参数，称之为谓词
    sort(ls.begin(), ls.end(), isShorter);
    foo(ls);
    stable_sort(ls.begin(), ls.end(), isShorter);
    foo(ls);
}
