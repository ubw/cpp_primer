#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string test = "cjw";

    for(char &i: test)
    {
        i = 'f';
    }

    cout << test << endl;
}
