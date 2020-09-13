#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(void)
{
    int status;
    cout << "i'm father:" <<  getpid() << endl;
    /*1. 没有任何子线程出错返回*/
    pid_t pid = wait(&status);

    pid_t pid2 = fork();
    if(pid2 == 0)
    {
        cout << "i'm son:" <<  getpid() << endl;
        for(int i=0; i<1000000;i++)
        {
        }
        _exit(0);
    }

    int status2;
    /*2. 如果有子线程还在运行则阻塞*/
    pid_t pid2_2 =  wait(&status2);
    cout << pid2_2 << endl;
    /*3. 子线程的终止状态可以显示出来，有对应的宏*/
    cout << status2 << endl;
    cout << WIFEXITED(status2) << endl;
    cout << WIFSIGNALED(status2) << endl;
}
