#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue<int> queue_list;
    
    for(int i = 0; i < 10;i++)
    {
        queue_list.push(i);
    }

    cout << queue_list.size() << endl;
    cout << "back:" << queue_list.back() << "front:" << queue_list.front() << endl;

    //弹出元素
    queue_list.pop();
    cout << queue_list.size() << endl;
    cout << "back:" << queue_list.back() << "front:" << queue_list.front() << endl;

    
    
}
