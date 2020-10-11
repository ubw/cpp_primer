// 参数绑定
#include <iostream>
#include <vector>
//bind()定义在functional头文件,placeholders也定义在functional头文件中
#include <functional>
#include <algorithm>

using namespace std;
//_n定义在placeholders的命名空间,必须要声明???
//1. using std::placeholders::_1;
//2. using namespace std::placeholders;
using namespace placeholders;


bool foo(int &i, int tmp)
{
    cout << i << endl;
    return i > tmp;
}

int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};

    //bind()只用了一个占位符，表示只接受单一参数
    find_if(vi.begin(), vi.end(), bind(foo, _1, 5));

    

}
