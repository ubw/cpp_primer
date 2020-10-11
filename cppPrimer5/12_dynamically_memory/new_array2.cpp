#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(void)
{
    string s1 = "hello dynamically memory!";
    string s2 = "hello new array!";

    int size = s1.size() + s2.size() + 1;

    cout << size << endl;

    char *p = new char[size];
    //string 的c_str()方法
    strcpy(p, s1.c_str());
    strcpy(p+s1.size(), s2.c_str());

    printf("%s\n", p);
    
    delete[] p;
}
