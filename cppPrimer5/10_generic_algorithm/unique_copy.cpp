#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


int main(void)
{
    vector<string> vs{"hello", "generic", "algorithm","algorithm", "hello", "unique_copy"};

    //list<string> ls;
    list<string> ls(10, "");

    //去重，第三个参数为目的的迭代器?
    //1. Segmentation fault
    //无法增加list的元素，所以无法插入,必须初始化
    //2. unique_copy只能删除就近相同的，意味着得先排序
    unique_copy(vs.begin(), vs.end(), ls.begin());
    for(string str: ls)
    {
        cout << str << ",";
    }
    cout << endl;

    
    //3. 调用back_inserter()就可以不需要初始化了？就可以增加元素了？？？会调用迭代器的特性？？？
    //插入迭代器
    list<string> ls2;
    unique_copy(vs.begin(), vs.end(), back_inserter(ls2));
    for(string str: ls2)
    {
        cout << str << ",";
    }
    cout << endl;


    
}
