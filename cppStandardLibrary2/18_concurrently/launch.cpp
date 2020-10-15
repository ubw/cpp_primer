#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int main(void)
{
    auto func = [](){
        for(int i = 0; i < 10; i++)
        {
            cout << "+" ;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    };

    auto func2 = [](){
        for(int i = 0; i < 10; i++)
        {
            cout << "-" ;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    };

    future<void> f(async(launch::async, func));
    future<void> f2(async(launch::async, func2));

    f.get();
    f2.get();

}
