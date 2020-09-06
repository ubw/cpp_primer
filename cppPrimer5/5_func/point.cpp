#include <iostream>

using namespace std;

int foo1(int **pa, int **pb)
{
    /*1. 形参中的二级指针是一个拷贝了的对象，对他修改是没用的*/
    //int **tmp = pa;
    //pa = pb;
    //pb = tmp;
    int *tmp = *pa;
    *pa = *pb;
    *pb = tmp;
    
    return 0;
}

int foo2(int* &ra, int* &rb)
{
    int* tmp = ra;
    ra = rb;
    rb = tmp;

    return 0;
}

int main(void)
{
    int a = 20;
    int b = 30;
    int *pa = &a;
    int *pb = &b;

    cout << *pa << ", " << *pb << endl;
    /*1. 二级指针改变指针指向*/
    foo1(&pa, &pb);
    cout << *pa << ", " << *pb << endl;

   /*2. 指针的引用改变指针的指向*/
    foo2(pa, pb);
    cout << *pa << ", " << *pb << endl;

    return 0;
}
