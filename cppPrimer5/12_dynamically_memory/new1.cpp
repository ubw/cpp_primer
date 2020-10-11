#include <iostream>
#include <vector>

using namespace std;

vector<int>* foo(){
    vector<int> *p = new vector<int>();

    return p;
}

void foo1(vector<int> *p)
{
    cout << "enter int into vector" << endl;
    int tmp;
    while(cin >> tmp)
    {
        p->push_back(tmp);
    }
}

void foo2(vector<int> *p)
{
    cout << "what's in vector:" << endl;

    for(int i : *p)
    {
        cout << i << endl;
    }
}


int main(void)
{
    vector<int> *p = foo();

    foo1(p);
    foo2(p);

    delete(p);
}
