#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int i = 1;
    char c = *((char*)&i);
    char *c1 = (char*)&i;


   cout << c << endl;
   printf("%d\n", c);
   cout << *((&c)+1) << endl;
   cout << *(c1) << endl;
   cout << *(c1+1) << endl;
   cout << *(c1+2) << endl;
   cout << *(c1+3) << endl;

   union
   {
        int i;
        char c;
   }un;
   un.i = 1;
   
   cout << un.c << endl;

   return 0;
}


