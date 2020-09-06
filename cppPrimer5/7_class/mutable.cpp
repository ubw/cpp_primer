#include <iostream>
#include <string>

using namespace std;

class Screen{
public:
typedef string::size_type pos;
private:
    /*默认初始值 c++11特性*/
    pos width = 0;
    pos height = 0;
    string cursor;
    mutable int access_cnt = 0;

public:
    /*default是c++11的特性，默认的构造函数*/
    Screen() = default;
    Screen(pos r, pos h):width(r), height(h){};

public:
    pos getWidth() const {
    //error: increment of member ‘Screen::width’ in read-only object
    //width++;
    // 1.即使是read-only对象也是可以修改可变数据成员的，用mutable修饰
    access_cnt++;
    return width;
    }

    pos getHeight() const {return height;}
};

int main(void)
{
    Screen screen;
    cout << screen.getWidth() << endl;
}
