#include <iostream>

int foo()
{
    return 0;
}


/*c++11允许定义特殊的constexprt函数，这种函数应该足够简单可以在编译的时候就能计算得到结果*/
constexpr int foo1()
{
    return 0;
}


constexpr int foo2(int b)
{
    if (b >0){
        return 1;
    }
    return 0;
}

int main(void)
{
    /* 常量表达式,提示编译器检查，这个值或者函数在编译期间就是常量*/
    constexpr int i = 10; 
    constexpr int j = sizeof(int);
    /*call to non-constexpr function ‘int foo()’*/
    constexpr int z = foo();
    constexpr int t = foo1();
    /*error: ‘constexpr int foo2(int)’ called in a constant expression*/
    constexpr int t1 = foo2(j);


    


    return 0;

}
