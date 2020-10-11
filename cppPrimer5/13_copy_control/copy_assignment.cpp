#include <iostream>
#include <string>

using namespace std;

class foo{
private:
    int i;
    string s;

public:
   foo(int i , string s)
   {
       cout << "ordenary constructor" << endl;
   }

   foo(const foo &f) 
   {
       cout << "copy constructor" << endl;
   }

   foo()
   {
       cout << "default constructor" << endl;
   }

   foo& operator=(const foo &f)
   {
       cout << "copy assigment" << endl;
   }

   ~foo(){
       cout << "destructor"  << endl;
   }

};


int main(void)
{
    foo a(1, "hello copy assignment");

    foo b(2, "hello copy_assignment");

    b = a;
}
