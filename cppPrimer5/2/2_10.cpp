#include <iostream>

using namespace std;

std::string global_str;
int global_int;

int main(void)
{
    std::string local_str;
    int local_int;

    /*string接受无参数的初始化方法，无论定义在哪都是空串，全局变量int未被初始化则定义默认为0，局部变量则是一个奇异值*/
    cout <<"1:global_str " << global_str << endl;
    cout <<"2:global_int " <<  global_int << endl;
    cout <<"3:local_str " <<  local_str << endl;
    cout <<"4:local_int " <<  local_int << endl;

    return 0;

}
