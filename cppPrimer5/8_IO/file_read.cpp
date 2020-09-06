#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(void)
{
    //1. 读文件
    ifstream input("/home/jwchu/cppProject/cppPrimer5/8_IO/file_read.txt");

    string s;
    vector<string> vs;
    //2. 输入流读取每一行
    while(getline(input, s))
    {
        vs.push_back(s);
    }

    for(string tmp:vs)
    {
        cout << tmp << endl;
    }

    //3. 关闭文件流
    input.close();


    return 0;
}
