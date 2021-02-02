#include <iostream>
#include <string.h>

using namespace std;

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

int main(void)
{
    int ret = compare("ooa", "oob");

    cout << ret << endl;
}
