#include <iostream>
#include <string>
#include <memory>

using namespace std;

class myClass{
private:
    int i;
    string s;

public:
    //1. 参数列表后的引用限定符，表示只能赋值左值
    //o match for ‘operator=’ (operand types are ‘myClass’ and ‘myClass’
    myClass& operator=(const myClass& m) &  {
       cout << "assignment" << endl; 
   }

   myClass(int i1, string s1) : i(i1), s(s1) {
        cout << "ordenary consturct" << endl;
   };

   myClass() = default;

   myClass retVal(){
       return myClass(1, "value"); 
   }

   myClass& retRef(){
       //return myClass(2, "reference");
       shared_ptr<myClass> r = make_shared<myClass>(myClass(2, "reference"));
       return *r;
   }
};

int main(void)
{
    myClass t = myClass();
    myClass t1 = myClass(1, "hello reference qualifier");
   
    //当返回左值的时候才可以,存在引用限定符的时候
    //t.retVal() = t1;
    t.retRef() = t1;

}
