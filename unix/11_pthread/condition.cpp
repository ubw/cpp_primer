#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex;
pthread_cond_t cond;

int pool = 0;
int cnt = 0;

void* func_producer(void*)
{
    cout << "producer" << endl;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(cnt < 10000)
        {
            cnt++;
            pool++;
            cout << "producer: pool" <<pool <<" cnt" << cnt << endl;
        }
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        usleep(2000);
    }
    // 进程的退出函数，不能这么用
   // _exit(0);
}

void* func_consumer(void*)
{
    cout << "consumer" << endl;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        1. 要把pthread_cond_wait放在循环中，避免虚假唤醒 
        while(pool > 0)
        {
            pthread_cond_wait(&cond, &mutex);
            pool--;
            cout << "consumer: pool" <<pool <<" cnt" << cnt << endl;
        }
        pthread_mutex_unlock(&mutex);
        usleep(2000);
    }
}

int main(void)
{
    pthread_t pid1;
    pthread_t pid2;
    pthread_t pid3;
    pthread_t pid4;

    //1.init
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    int ret = pthread_create(&pid1, NULL, func_producer, NULL);
    if(ret < 0)
    {
        cout << "create pid1 error" << endl;
    }

    ret = pthread_create(&pid2, NULL, func_consumer, NULL);
    ret = pthread_create(&pid3, NULL, func_consumer, NULL);
    ret = pthread_create(&pid4, NULL, func_consumer, NULL);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid2, NULL);

    // destory
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

}
