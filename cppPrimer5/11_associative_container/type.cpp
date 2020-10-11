#include <iostream>
#include <map>
#include <set>

using namespace std;

//1. 关联容器定义的3个类型
int main(void)
{
   map<string, int>  mapStringInt;
   //2. 关键字类型
   map<string, int>::key_type keyType;
   //3. 值类型,map 为pair, set为Key
   map<string, int>::value_type valueType;
   //4. 映射值类型,map有，set无
   map<string, int>::mapped_type mapType;
}
