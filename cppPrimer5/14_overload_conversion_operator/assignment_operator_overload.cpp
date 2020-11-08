#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

class LOTTERY{
private:
int prize;
int blue;
int red;

public:
LOTTERY(int prize, int blue, int red):prize(prize), blue(blue), red(red){
    cout << "consturcter" << endl;
};
//1. 赋值运算符一般都是成员函数，且返回的是对象的引用
//2. 赋值运算符有，拷贝构造的运算符，移动构造运算符, 初始化列表运算符，参数不同
//3. initializer_list也是一种模板类型，必须要申明类型,且永远是常量值,定义再同名的头文件中。必须是一种类型，这个好像不太方便吧？？
LOTTERY& operator= (initializer_list<int> il)
{
    cout << il.size() << endl; 
    return *this;
}
};

int main(void)
{
    //其实调用的还是构造函数？？
    LOTTERY b={1,2,3};
    //有了这个值的才叫做赋值？？
    b={1,2,3};
}
