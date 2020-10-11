#include <iostream>

using namespace std;

class myClass{
private:
    int i;
    string s;

public:
    friend myClass operator+(const myClass& m,const  myClass& n)
    {
        myClass r;
        cout << "operator +" << endl;
        cout << m.i << endl;
        cout << n.i << endl; 

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
    getValue(n);
}
