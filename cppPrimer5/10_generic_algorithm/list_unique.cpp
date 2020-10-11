#include <iostream>
#include <string>
#include <list>

using namespace std;

void foo(list<string> ls)
{
    for(string str: ls)
    {
        cout << str << ",";
    }
    cout << endl;
}

int main(void)
{
    list<string> ls{"hello", "generic", "algorithm", "hello", "list", "special", "algorithm"};

    //1.  list, forward_list特殊的成员函数的算法，和泛型算法最大的不同是改变了容器内容
    ls.sort();
    foo(ls);

    ls.unique();
    foo(ls);
}
