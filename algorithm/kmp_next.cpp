#include <iostream>
#include <string.h>

using namespace std;

void get_next(char* p ,int* next)
{
    int i,j;
    i = 0;
    j = -1;
    next[0] = -1;

    while(i < strlen(p))
    {
        if(j == -1 || p[i] == p[j])  {++i; ++j; next[i] = j;}
        else j=next[j];
    }
}

int main(void)
{
    char* p= "helloh1lloKmp";
    int next[strlen(p)];

    get_next(p, next);

    int j = 0;
    for(int i: next)
    {
        cout << j++<<"  "<< i << endl;
    }
}
