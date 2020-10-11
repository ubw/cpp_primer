#include <iostream>
#include <string>
#include <vector>

using namespace std;

class foo{
private:
    int a;
    string b;

public:
    foo(int a, string b){
        cout << "ordenary constucter" << endl;
        this->a = a;
        this->b = b;
    };
    //add const ok?????????????
    foo(const foo &f){
        cout << "copy initialization" << endl;
        //new add ,need???
        a = f.a;
        b = f.b;
    };

    foo(){
        cout << "default initialization" << endl;
    };
    int getA(){
        return this->a;
    };

    string getB(){
        return this->b; 
    };
};

//1. 非引用类型的形参
void func1(foo f)
{
    cout << "call func1" << endl;
}

foo func2()
{
    foo f(2, "the func return object is not reference type");
    return f;
}

int main(void)
{
     foo f1(1, "the parameter is not reference type");
     func1(f1);

     //1. 函数返回值是非引用类型的
     cout << "the func return type is not reference" << endl;
     foo f2 = func2();
     //2. RVO优化了，所以其实实际没有调用拷贝构造函数,现代编译器将这个临时变量优化了
     //func2();

     //cout << f2.getA() << endl;
     //cout << f2.getB() << endl;

     vector<foo> v;
     cout << "test push_back:" << endl;
     v.push_back(f1);

     cout << "test emplace_back 1:" << endl;
     //3. 为什么也调用了两次拷贝构造???,因为vector的空间不够的关系, 扩容，通过拷贝构造函数复制之前的元素的
     foo f3(3, "test");
     v.emplace_back(f3);

     //也是调用两次呀????
     cout << "test emplace_back 2 direct parameter:" << endl;
     v.emplace_back(2, "test emplace_back2");
     cout << "test emplace_back 3 direct parameter:" << endl;
     v.emplace_back(3, "test emplace_back3");
     cout << "test emplace_back 4 direct parameter:" << endl;
     v.emplace_back(4, "test emplace_back4");
     cout << "test emplace_back 5 direct parameter:" << endl;
     v.emplace_back(5, "test emplace_back5");
     cout << "test emplace_back 6 direct parameter:" << endl;
     v.emplace_back(6, "test emplace_back6");
     cout << "test emplace_back 7 direct parameter:" << endl;
     v.emplace_back(7, "test emplace_back7");
}
