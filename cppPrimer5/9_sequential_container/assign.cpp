#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

int main(void)
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};


    vector<int> vi;
    forward_list<int> fi;

    // 1. assign允许赋值一个范围，左闭右开，容器类型可以不同，元素类型需要可以转换 
    vi.assign(a, a+9);
    fi.assign(a, a+9);

    for(int i:vi)
        cout << i << ",";

    cout << endl;

    for(int i:fi)
        cout << i << ",";


    cout << endl;
}
