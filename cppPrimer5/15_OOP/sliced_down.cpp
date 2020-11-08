#include <iostream>

using namespace std;

class LOTTERY{
protected:
int red;
int blue;

public:
virtual void to_string(){
    cout << "red:" << red  << "  "<< "blue:" << blue << endl;
}
LOTTERY(int red, int blue):red(red), blue(blue){}
};

class BIG_LOTTERY: public LOTTERY{
private:
int prize;

public:
virtual void to_string(){
    //1. 子类调用父类的方法
    LOTTERY::to_string();
    cout << "prize:" << prize << endl;
}
//class ‘BIG_LOTTERY’ does not have any field named ‘red’
//BIG_LOTTERY(int red, int blue):red(red), blue(blue), prize(0){};
BIG_LOTTERY(int red, int blue):LOTTERY(red, blue), prize(0){};

};

int main(void)
{
    LOTTERY a(1,2);
    //conversion from ‘LOTTERY’ to non-scalar type ‘BIG_LOTTERY’ requested
    //BIG_LOTTERY b = a;


    BIG_LOTTERY c(1, 2);
    //1. sliced_down切割。忽略了派生类的地方.
    LOTTERY d = c;
    d.to_string();
    
}
