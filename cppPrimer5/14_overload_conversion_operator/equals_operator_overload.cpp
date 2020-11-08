#include <iostream>
#include <string>

using namespace std;

class LOTTERY{
private:
    string prize;
    int    blue;
    int    red;

public:
    friend bool operator==(LOTTERY a, LOTTERY b);
    LOTTERY(string prize, int blue, int red):prize(prize),blue(blue),red(red){};
};

bool operator== (LOTTERY a, LOTTERY b)
{
    if(a.prize == b.prize && a.blue == b.blue && a.red == b.red)
    {
        return true;
    }

    return false;
}

int main(void)
{
    LOTTERY a("level 1", 1, 2);
    LOTTERY b("level 1", 1, 2);
    LOTTERY c("level 1", 2, 2);

    cout << (a == b) << endl;
    cout << (b == c) << endl;

}
