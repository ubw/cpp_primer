#include <iostream>

using namespace std;

class myClass{
private:
    int i;
    string s;

public:
    //1. 运算符重载可以设置成友元函数
    //2. 算数运算符一般定义为非成员函数
    friend myClass operator+ (const myClass& m,const  myClass& n)
    {
        myClass r;
        cout << "friend operator +" << endl;

        r.i = n.i + m.i;
        r.s = n.s + m.s;
        return r;
    }

    myClass(const myClass &m)
    {
        this->i = m.i;
        this->s = m.s;
        cout << "copy consturctor" << endl;
    }

    myClass() = default;

    myClass(int i, string s) : i(i),s(s)
   {
       cout << "ordenary consturcter" << endl;
   }
friend void getValue(myClass& m);
};

void getValue(myClass& m)
{
    cout  << m.i << "," << m.s  << endl;
}

int main(void)
{
    myClass m1(1, "hello overload operator");
    myClass m2(2, "hello cpp");

    myClass n = m1 +  m2;
    
    //成员函数的+重载不改变了加数m1吗？这合理吗?
    getValue(n);
    getValue(m1);
    myClass n2 = operator+(n, m1);
    getValue(n2);
}
