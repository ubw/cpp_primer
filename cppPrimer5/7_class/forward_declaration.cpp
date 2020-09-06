#include <iostream>

/*x中有为定义的类型，需要前向声明,可以用来修饰指针和引用，以及函数*/
class Y;

class X{
    Y* y;
    Y foo(Y tmp);
};

class Y{
    X x;
};

int main(void)
{
    X x;
    Y y;

    return 0;
}
