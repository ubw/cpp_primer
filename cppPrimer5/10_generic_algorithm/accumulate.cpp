#include <iostream>
//accumulate是定义在numeric头文件中 的
#include <numeric>
#include <vector>

using namespace std;

int main(void)
{
   vector<int>  vi{1,2,3,4,5,6,7,8,9};

   int ret = accumulate(vi.begin(), vi.end(), 0);
   cout << ret << endl;
   ret = accumulate(vi.begin(), vi.end(), ret);
   cout << ret << endl;

}
