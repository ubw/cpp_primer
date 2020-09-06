#include <iostream>

using namespace std;

int foo(int array[]);
/*error: call of overloaded ‘foo(int [10])’ is ambiguous*/
//int foo(int (&array)[10]);
int foo2(int (&array)[10]);

int main(void)
{
    int array[10]{0,1,2,3,4,5,6,7,8,9};

    /*1 c++11新增的两个函数begin(),end() 变量名不能定义成这个了？定义在iterator头文件中*/
    /*begin返回的是头指针，end返回的是尾后指针*/
    int* b = begin(array);
    int* e = end(array);

    cout << *(++b) << "," << *(--e) << endl;

   /*2. 多维数组和引用*/
   int array2[4][3] = {0};
   int cnt = 0;

   /*第一个for中，如果不定义为引用，auto会解析成指向array2首元素的指针,引用则是对一个有3个元素的数组的引用*/
   for(auto &row:array2)
   {
       for(auto &col:row)
       {
           col = cnt++;
       }
   }

   for(int i = 0; i<4; i++)
   {
       for(int j = 0; j< 3; j++)
       {
           cout << array2[i][j] << endl;
       }
   }

   /*3. 数组的特殊性质1 无法拷贝数组，2. 数组会退化为指针*/
   /*即无法以值传递的方式使用数组*/
   foo(array);

   /*4. 数组的引用,没有退化??,引用和指针类型是一致的吗？重载报错？*/
   foo2(array);
   
   return 0;

}

/*形参其实是一个指针*/
int foo(int array[])
{
    cout << "func array:" << sizeof(array) << " sizeof(int*):"<< sizeof(int *) << endl;

    return 0;
}


int foo2(int (&array)[10])
{
    cout << "func array:" << sizeof(array) << " sizeof(int*):"<< sizeof(int *) << endl;
}

