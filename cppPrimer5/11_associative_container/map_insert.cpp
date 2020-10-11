#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<string, int> msi;

    //1. 初始化列表
    msi.insert({"hi", 1});

    //2. make_pair
    msi.insert(make_pair("associative", 1));


    //3. 构造器,pair需要说明元素类型,返回的是一个pair类型的数据
    auto ret = msi.insert(pair<string, int>("container", 1));
    cout << ret.first->first << endl;;
    cout << ret.first->second << endl;
    cout << ret.second << endl;

    //4. 构造器
    ret = msi.insert(map<string, int>::value_type("container", 1));
    cout << ret.first->first << endl;;
    cout << ret.first->second << endl;
    cout << ret.second << endl;
    

  
   for(auto tmp: msi)
   {
        cout << tmp.first << "," << tmp.second << endl;
   }
}
