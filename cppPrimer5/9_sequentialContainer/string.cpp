#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(void)
{
    char *cstr = "Hello String";

    /*1. string赋值  ----char**/
    string s(cstr, strlen(cstr));

    cout << cstr << endl;
    cout << s << endl;
    
    /*2. string赋值   -----string*/
    string s2(s, 6, 5);
    cout << s2 << endl;

    /*3. string截取*/
    string s3 = s.substr(0, 5);
    cout << s3 << endl;

    /*4. string追加*/
    s3.append(s2,2, 2);

    cout << s3 << endl;
}
