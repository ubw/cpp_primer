#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main(void)
{
    map<string, int> map {{"hello", 1}, {"associative", 2}, {"container", 3}};
    
    //1. value_type的值的引用,按key的字典序排列 
    for(auto it=map.begin(); it != map.end(); it++)
    {
        cout << it->first << "," << it->second << endl;
    }

    //2. it是key是const的
    //auto it = map.begin();
    //3. 为什么要打全?
    std::map<string, int>::iterator it = map.begin();
    //it->first = "hello1";
    it->second++;
    for(auto it=map.begin(); it != map.end(); it++)
    {
        cout << it->first << "," << it->second << endl;
    }
}
