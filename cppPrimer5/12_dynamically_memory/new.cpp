#include <iostream>

using namespace std;

int *gp1 = new int;
int main(void)
{

    int *p1 = new int;
    //1.  传统的方式初始化
    int *p2 = new int(2048);
    //2. c++11的初始化列表来初始化
    int *p3 = new int{1024};

    cout << "int *p1 = new int, *p1=" << *p1 << endl;
    cout << "int *gp1 = new int, *gp1=" << *gp1 << endl;
    cout << "int *p2 = new int(2048), *p2=" << *p2 << endl;
    cout << "int *p3 = new int{1024}, *p3=" << *p3 << endl;
    delete(p1);
    delete(p2);
    delete(p3);
    delete(gp1);

    
}
