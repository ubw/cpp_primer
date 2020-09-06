#include <iostream>

using namespace std;
using array_reference = int (&)[10];

auto foo3(array_reference p)->int (&)[10]
{
    for(int &i: p)
    {
        i = i+2;
    }

    return p;
}
