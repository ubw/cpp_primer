#include <iostream>
#include <pthread.h>
#include <unistd.h>


using namespace std;
struct foo{
    long pool;
    long count;
    pthread_mutex_t mutex;
};

struct foo test;

void* func(void*)
{
    cout << "thread :" << pthread_self() << endl;;
    while(test.pool > 0)
    {
        pthread_mutex_lock(&test.mutex);
        test.pool--;
        test.count++;
        if(test.pool <0)
        {
             cout << "test.pool< 0 :" << pthread_self() << endl;;
        }
        pthread_mutex_unlock(&test.mutex);
    }

    int ret = pthread_mutex_destroy(&test.mutex);
    if(ret != 0)
    {
         cout << "pthread_mutex_destroy" << pthread_self() << endl;;
    }
    return 0;
    
}




int main(void)
{
    test.pool = 228889999;
    test.count = 0;
    pthread_mutex_init(&test.mutex, NULL);


    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_create(&tid1, NULL, func, NULL);
    pthread_create(&tid2, NULL, func, NULL);
    pthread_create(&tid3, NULL, func, NULL);


    //sleep(5);
    pthread_join(tid1, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid2, NULL);
    cout << "foo::pool" << test.pool << endl;
    cout << "foo::count" << test.count << endl;

 
    return 0;

}
