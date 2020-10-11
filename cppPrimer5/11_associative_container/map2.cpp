#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(void)
{
    map<string, int> m;

   string tmp;
   while(cin >> tmp)
   {
      //1. 返回值是一个pari类型的，first是一个map中的迭代器，second是一个bool值
      //2. insert的值是pari,不是两个参数
      auto p = m.insert({tmp, 1});
      //3. 返回的类型不是指针
      if(!p.second)
          p.first->second++;
     
   }

   for(auto p2: m)
   {
       cout << p2.first  << "," << p2.second << endl;
   }

}
