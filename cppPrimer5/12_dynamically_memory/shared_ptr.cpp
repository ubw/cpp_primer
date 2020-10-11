#include <iostream>
//0.智能指针shard_ptr, unique_ptr, weak_ptr需要的头文件
#include <memory>
#include <vector>

using namespace std;

int main(void)
{
    //1. c++11 模板类 智能指针
    shared_ptr<vector<int>> sm;

    vector<int> vi{1,2,3,4,5,6,7,8,9,10};

    //2.  初始化
    sm = make_shared<vector<int>>(vi);

    for(int i: *sm)
    {
        cout << i << endl;
    }
}
