#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
    vector<string> vectorStr;
    string s("hello");
    
    /*vector*/
    /*1. vector插入需要调用函数push_back*/
    for(int i = 0; i < 10; i++)
    {
        char tmp = i + '0';
        vectorStr.push_back(s+tmp);
    }


    for(auto it=vectorStr.begin(); it != vectorStr.end(); it++)
    {
        cout << *it << endl;
    }
  
    auto beginIt = vectorStr.cbegin();
    auto endIt = vectorStr.cend();
 

    /*2. 迭代器iterator没有两两相加的运算,但是有减法的重载*/
    /*no match for ‘operator+’ (operand types are ‘__gnu_cxx::__normal_iterator<const std::basic_string<char>*, std::vector<std::basic_string<char> > >’ and ‘__gnu_cxx::__normal_iterator<const std::basic_string<char>*, std::vector<std::basic_string<char> > >’)*/
    //auto midId = (beginIt + endIt)/2;
    auto midId2 = beginIt + (endIt-beginIt)/2;

    //cout << *midId << endl;
    cout << *midId2 << endl;

    /*3. 可以用数组来初始化vector*/
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v3(begin(array), end(array));
    for(auto it=v3.begin(); it != v3.end(); it++)
    {
        cout << *it << endl;
    }
    
    return 0;
}
