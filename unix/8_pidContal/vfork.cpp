#include <iostream>
#include <unistd.h>

using namespace std;
int i = 0;
int main(void)
{
  
    cout << getpid() << endl;
    pid_t pid ;
    if((pid=vfork()) == 0)
    {
        i++;
        cout << "i'm son,vfork,so i run first" << getpid() << " i:" << i << endl;
        // 1. vfork必须要调用_exit()  退出,保证子进程先执行
        _exit(0);
    } else if(pid > 0) {
        //2. vfork,子进程是在父进程的空间执行的
        i++;
        cout << "i'm father:" << getpid() << ",my son:" << pid << " i:" << i <<  endl;
    }

    return 0;
}
