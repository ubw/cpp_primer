#include <iostream>
#include <stdio.h>


#define TEST(a,b) do \
{    \
    int  c = a; \
    a = b;    \
    b = c;    \
    printf("hello\n");  \
}while(0)

int main(void)
{
    int a = 1;
    int b = 2;
    TEST(a, b);

    printf("%d,%d\n", a, b);
}
