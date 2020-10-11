#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s = "hello string find";
    string oldValue = "str";


    //2. string find搜索操作,返回的是下标
    cout << s.find(oldValue) << endl;
    cout << s.find("ing") << endl;
    cout << s.find("AB") << endl;
    // 1. string::npos 表示为没能匹配到
    if(s.find("AN") == string::npos)
    {
        cout << "s.find('AB') npos" << endl;
    }
    
}
