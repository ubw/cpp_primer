#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int pool = 100000000;
int cnt = 0;

void* foo1(void*)
{
   cout <<"======hello pthread======="<<endl;
   cout << "======getpid():"<< getpid() << endl;
   cout << "======pthread_self(d):"<< pthread_self() << endl;
   while(pool > 0)
   {
       pool--;
       cnt++;
   }
   cout << "thread cnt" <<cnt << endl;;
   cout << "thread pool" <<pool << endl;;
    return 0;
}

int main(void)
{
   pthread_t pthd;
   /*1. 创建线程*/
   int ret = pthread_create(&pthd, nullptr, foo1, nullptr);
   

   cout << ret << endl;
   cout << pthd << endl;
   cout << "getpid():"<< getpid() << endl;
   cout << "pthread_self(d):"<< pthread_self() << endl;

   while(pool > 0)
   {
       pool--;
       cnt++;
   }
   cout << "cnt" <<cnt << endl;
   cout << "pool" <<pool << endl;

   sleep(1);
 
   return 0;
}
