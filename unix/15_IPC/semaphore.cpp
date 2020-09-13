#include <iostream>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t s;
int cnt = 0;

void* func_consumer(void *)
{
    int ret = sem_post(&s);
    while(cnt < 10000)
    {
        cout << pthread_self() <<  " ret: " << ret << " cnt:" << cnt << endl;
        cnt++;
        usleep(2000);
    }
    sem_wait(&s);
}

int main(void)
{
    // 1. 第二个参数表示的是如果为0是线程间的信号量，非0则是进程间的信号量
    //  第三个参数表示信号量初始值
    sem_init(&s, 0, 2);
    
    pthread_t tid[3];
    pthread_create(&tid[0], NULL, func_consumer, NULL);
    pthread_create(&tid[1], NULL, func_consumer, NULL);
    pthread_create(&tid[2], NULL, func_consumer, NULL);
    

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    sem_destroy(&s);
}
