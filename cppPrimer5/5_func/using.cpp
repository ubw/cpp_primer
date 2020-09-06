#include <iostream>

/*error: creating array of references*/
/*[]的优先级高，不能这么写把？*/
using array_reference = int (&)[10];


array_reference foo2(array_reference p)
{
    for(int &i: p)
    {
        i = i+2;
    }

    return p;
}

