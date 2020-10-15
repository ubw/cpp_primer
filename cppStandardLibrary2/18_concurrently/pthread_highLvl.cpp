#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int func1()
{
    for(int i = 0; i < 10; i++)
    {
        cout.put('+').flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return 0;
}

int func2()
{
    for(int i = 0; i < 10; i++)
    {
        cout.put('-').flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return 0;
}


//编译需要加上-pthread库
int main(void)
{
    //1. async尝试启动func1于后台,
    future<int> f1(async(func1));
    future<int> f2(async(func2));


    f2.get();
    f1.get();
    return 0;
}
