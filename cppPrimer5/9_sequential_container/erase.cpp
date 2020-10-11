#include <iostream>
#include <deque>
#include <string>

using namespace std;

int foo(deque<int> container)
{
    for(auto i:container)
    {
        cout << i  << ",";
    }
    cout << endl;
}

int main(void)
{
    deque<int> id = {0,1,2,3,4,5,6,7,8,9};
    //1 后面删除一个
    id.pop_back();
    foo(id);
    
    //2 前面删除一个
    id.pop_front();
    foo(id);


    //3 删除第二个
    auto it = id.begin();

    //4 erase返回指向下一个的迭代器
    auto it3 = id.erase(++it);
    foo(id); 

     //5 删除范围，第二个到倒数第二个
     auto it4 = id.end();
     it4 = it4-1;
     // 6 再删除元素后，原来的迭代器就失效了
     //id.erase(it, it4);
     // 7 erase 删除范围第二个参数等于返回的参数，意味着，第二个参数是不删的
     auto it5 = id.erase(it3, it4);
     foo(id);

      // deque 不支持
     //id.erase(1,1);

     // 8. string& erase (size_t pos = 0, size_t len = npos);
     string str8 = "hello erase";
     str8.erase(1,1);
     cout << str8 << endl;
    
}

