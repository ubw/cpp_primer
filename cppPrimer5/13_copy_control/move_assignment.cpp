#include <iostream>
#include <utility>

using namespace std;

class myClass{
private:
    int i;
    string s;

public:
    myClass(){
        cout << "default constructor" << endl;
    }

    myClass& operator=(myClass &&m)
    {
        cout << "move assignment" << endl;
    }
};

int main(void)
{
    myClass m;
    
    myClass m1;

    m1 = move(m);

}
