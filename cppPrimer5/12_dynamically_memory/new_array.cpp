#include <iostream>
#include <memory>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(void)
{
    char* tmp1 = "hello dynamically memory";
    char* tmp2 = "hello new array";

    
    int size = strlen(tmp1) + strlen(tmp2) + 1;

    cout << size << endl;

    char* tmp = new char[size];
    strcpy(tmp, tmp1);
    strcpy(tmp+strlen(tmp1), tmp2);

    printf("%s\n", tmp);

    delete[] tmp;
    
    
}
