#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>

using namespace std;

int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    
    int array[9];
 
    list<int> li;


    //1. 第一二个参数表示源端的范围，第3个参数赋值之后插入在前还是后面??
    copy(vi.begin(), vi.end(), array);

    for(int i: array)
    {
        cout << i << ",";
    }
    cout <<  endl;

    //2. front_insertor
    copy(vi.begin(), vi.end(), front_inserter(li));
    for(int i: li)
    {
        cout << i << ",";
    }
    cout <<  endl;
    
}
