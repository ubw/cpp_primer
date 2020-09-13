#include <iostream>
#include <unistd.h>

using namespace std;
int i = 0;

int main(void)
{
    auto pid = getpid();

    cout << pid << endl;

    auto pid1 = fork();
    if(pid1 == 0)
    {
        i++;
        cout << "i'm son:" << getpid() << " i:" << i << endl;
    }else {
        i++;
        cout << "i'm father:" << getpid() << "my son:" << pid1 << " i:" << i << endl;
    }

}
