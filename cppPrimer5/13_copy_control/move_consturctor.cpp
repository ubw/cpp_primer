#include <iostream>
// move 定义在utility中
#include <utility>

using namespace std;

class myClass{
private:
    int i;
    string s;

public:
    myClass(){
        cout << "default constructor"  << endl;
    }

    myClass(myClass &&m)
    {
        cout << "move constructor" << endl;
    }
};

int main(void)
{
   myClass m;
   myClass n = std::move(m);
   
}
