#include <iostream>
#include <string>

using namespace std;

/*1. stuct 和 class的不同， struct默认的是Public的*/
struct FooStruct{
private:
    string id;
    int sold;
    int price;

public:
   
    FooStruct() = default; 
    FooStruct(int i, int j):sold(i),price(j),id("9527"){
       cout <<"FooStuct(int i, int j) "<< endl;
   }
   FooStruct(const FooStruct& foo2){
       sold = foo2.sold;      
       price = foo2.price;
       cout <<"FooStuct(FooStruct& foo2) "<< endl;
   }

public:

   //const string& getId() {return id;}
   string getId() const  {return id;}
   int   calcTotalPrice(){
        return sold*price;
   }
   int getSold() const {return sold;}
   int getPrice() const {return price;}

   /*2. 在类中只能是友员的声明，在外面需要有实际的声明，友元主要是解决了访问的权限*/
   friend FooStruct add(const FooStruct& foo1, const FooStruct& foo2);
};


/* 友员的实际声明 返回一个右值是没事的*/
FooStruct add(const FooStruct& foo1, const FooStruct& foo2)
{
   FooStruct tmp = foo1; //底层的const忽略了????函数传递过来变成顶层const了1??
   //友员不可以访问private? ??必须要类型和声明正确啊
   if (foo1.id == foo2.id)
   {
      cout << "diferent foo1 and foo2" << endl;
   }else {
      tmp.price = foo1.price + foo2.price;
      tmp.sold = foo1.sold + foo2.sold;
  }
  
  return tmp;
}

int main(void)
{

   FooStruct foo1; 
   /*error: conversion from ‘FooStruct*’ to non-scalar type ‘FooStruct’ requested*/
   /*2. new只能是指针类型，变量不可以*/
   FooStruct *foo2 = new FooStruct(10, 2); 
   FooStruct *foo3 = new FooStruct(*foo2); 

   FooStruct tmp = add(*foo2, *foo3); 
   cout << "add foo2 foo3 ,price:" << tmp.getPrice() << " sold:" << tmp.getSold() << endl;

   delete(foo2);
   delete(foo3);
    
}
