#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


int main(void)
{
    list<string> ls{"hello", "generic", "algorithm", "hello", "insert", "iterator"};

    list<string> ls2;

    copy(ls.begin(), ls.end(), front_inserter(ls2));

    for(string str: ls2)
    {
        cout << str << ",";
    }
    cout <<  endl;
}
