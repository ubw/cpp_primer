#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>

using namespace std;

template<typename T, typename U>
bool foo_find(T it_begin, T it_end, U value)
{
    //1. 需要两个知识点，需要指向首元素的迭代器，和尾后迭代器
    for( ;it_begin != it_end; it_begin++)
    {
        if (*it_begin == value)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    vector<int> vi{1,2,3,4,5};

    int ret = foo_find(vi.begin(), vi.end(), 3);
    cout << ret << endl;
    ret = foo_find(vi.begin(), vi.end(), 6);
    cout << ret << endl;

    list<string> lstr{"hello", "string", "2021"};

    ret = foo_find(lstr.begin(), lstr.end(), "hello");
    cout << ret << endl;
    ret = foo_find(lstr.begin(), lstr.end(), "hello1");
    cout << ret << endl;

    return 0;
}
