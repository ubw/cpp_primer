#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str("hello world 901225!");

    /*范围for循环*/
    /*非引用是无法改变对象的值的*/
    for (char c : str){
        if(isalpha(c)){
            c = 'X';
        }
    }


    cout << str << endl;

    return 0;
}
