#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

void foo(deque<int> &di)
{
    cout << di.size() << endl;
     //capacity()只支持stirng和vector
    //cout << di.capacity() << endl;
    for(int i: di)
    {
        cout << i << "," ;
    }
    cout  << endl;

}

int main(void)
{
    deque<int> di(10);
    foo(di);
   
    // 1. fill() 写容器的算法，void返回值
    fill(di.begin(), di.end(), 11);
    foo(di);

    fill(di.begin(), di.end()+1, 12);
    foo(di);
    
    //2. fill_n(),还可以接受一个单迭代器，一个计数值，一个初始值
    //fill_n假定是安全的，如果超出计数值，为产生未定义的行为
    fill_n(di.begin(),  11, 13);
    foo(di);
  
    
}
