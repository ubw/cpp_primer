#include <iostream>
#include <vector>

using namespace std;

int foo(vector<int> vi)
{
   for(int i: vi)
   {
       cout << i << ",";
   }

   cout << endl;
}

int main(void)
{
   vector<int> vi = {1,2,3,4,5,6,7,8,9}; 
  
   auto it = vi.end(); 

   for(int i=10; i < 15; i++)
   {
       //1. 因为迭代器会失效，不能再用插入操作之前的迭代器
       //insert是在这个迭代器之前插入元素，返回指向新元素的迭代器
       it = vi.insert(it, i);
       it++;
       //2. emplace是c++11引入的，和insert对应
       it = vi.emplace(it, i);
       it++;
      
   }
   foo(vi);


   //3. emplace_back和push_back对应
   //   emplace_front和push_front对应
   //   insert,push_back.push_front是将对象拷贝到容器中
   //   emplace是将参数传递给构造函数，直接在容器的内存空间构造元素
   vi.emplace_back(-1);
   //4. vector不支持头插入
   //vi.emplace_front(-1);
   foo(vi);

   return 0;
   
}
