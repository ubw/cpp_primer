#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//./a.out "./file_read.txt" "./file_write.txt"
int main(int argc, char *argv[])
{
    

    ifstream inFile(argv[1], fstream::in);
    if(!inFile)
    {
        cout << "inFile failed" << endl;
    }
    //1. 定义输出文件流，非截断
    ofstream outFile(argv[2], fstream::app);
    if(!outFile)
    {
        cout << "outFile failed" << endl;
    }

    string tmp;
    while(getline(inFile, tmp))
    {
        for(char c:tmp)
        {
            outFile << (char)toupper(c);
            cout << (char)toupper(c) << endl;
        }
        outFile << endl;
    }

    outFile.close();
    inFile.close();


    return 0;
}
