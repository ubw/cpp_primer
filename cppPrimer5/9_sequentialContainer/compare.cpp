#include <iostream>

using namespace std;

int main(void)
{
    string s = "Hello string compare";
    string s1 = "Hello string compare";
    string s2 = "hello string compare";
    string s3 = "Hello";

    cout << s.compare(s1) << endl;
    cout << s.compare(s2) << endl;
    cout << s.compare(s3) << endl;
    cout << s2.compare(s3) << endl;
}

