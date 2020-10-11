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
    //为什么比较不相同？
    if(test == "cjw")
    {
        cout << "test == cjw" << endl;
    }
}
