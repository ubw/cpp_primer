#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, less<int>> priorityQ;

    priorityQ.emplace(1);
    priorityQ.emplace(9);
    priorityQ.emplace(4);
    priorityQ.emplace(2);
    priorityQ.emplace(3);
    priorityQ.emplace(44);
    priorityQ.emplace(33);
    priorityQ.emplace(22);
    priorityQ.emplace(11);


    for(int i = 0; i<2; i++)
    {
        
        cout << priorityQ.top() << endl;
        priorityQ.pop();
    }

    cout << priorityQ.top() << endl;
    

}
