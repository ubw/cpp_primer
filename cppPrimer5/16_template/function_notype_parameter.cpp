#include <iostream>
#include <string.h>

using namespace std;

//1. 非类型模板参数
template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

int main(void)
{
    int ret = compare("ooa", "oob");
    ret = compare("ooa1", "oob1");

    cout << ret << endl;
}
