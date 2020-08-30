#include <iostream>

int main(void)
{
    /*error: ‘wage’ was not declared in this scope,声明初始化的时候必须要用,隔开*/
    double salary = wage = 999.999;

    /*warning: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]*/
    /*g++ -std=c++11 2_9.cpp*/
    /*初始化列表的方式如果窄化了，会报警告*/
    int i = {3.14};
    int j{3.14};
    double ld = 3.1415926;
    int c = ld;
    int d(ld);
    int e{ld};
    int f = {ld};


    int a(3.14);
    int b = 3.14;
    return 0;
}
