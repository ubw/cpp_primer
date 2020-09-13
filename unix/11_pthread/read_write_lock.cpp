#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

long pool = 88889999;
long cnt = 0;

void* func_read(void *)
{
        while(pool > 0)
        {
        //cout << __func__<< " pool:"<< pool << endl;
        //没有这个线程不让出来？
        usleep(10);
        }
}

void* func_write(void *)
{
        while(pool > 0)
        {
        --pool;
        ++cnt;
        //cout << __func__<< " pool:"<< --pool << endl;
        //cout << __func__<< " cnt:"<< ++cnt << endl;
        usleep(20);
        }
}

int main(void)
{
    pthread_t   tid[8];

    for(int i=0; i<8; i++)
    {
        if(i <=5 && i%2==0)
        {
            pthread_create(tid+i,NULL,func_write,NULL);
        }else {
            pthread_create(tid+i,NULL,func_read,NULL);
        }
    }

    for(int i=0; i<8; i++)
    {
        pthread_join(tid[i], NULL);
    }
        cout << __func__<< " pool:"<< pool << endl;
        cout << __func__<< " cnt:"<< cnt << endl;
    
}
