#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v;

    for(int i = 0; i<10; i++)
    {
        v.push_back(i);
    }

    /*iterator 迭代器*/
    /*1. 通过标准库对象的begin(),end()方法，获得迭代器*/
    /*2. begin是指向第一个元素的迭代器，end是指向最后一个元素下一个位置的迭代器*/
    /*3. begin迭代器和end迭代器相等时候，表示指向同一个地方*/
    for(auto it=v.begin(); it != v.end(); it++)
    {
        *it = *it * *it;
    }

    for(int i:v)
    {
        cout << i << endl;
    }
    return 0;
}
