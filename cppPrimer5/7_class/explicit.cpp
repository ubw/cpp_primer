#include <iostream>
#include <string>

using namespace std;

class Book{
public:
    //1. explicit 只对一个参数的构造函数有效
    explicit Book(string bookName){
        cout << "book(string) constructer" << endl;
    }
    void isEqual(Book otherBook){
        cout << "in isEqual(Book)" << endl;
    }

private:
    string name;
};

int main(void)
{
    /*2. 直接初始化,explicit构造函数只能用于直接初始化*/
    Book book("c++ primer");
    /*3. 拷贝初始化不可以 */
    //error: conversion from ‘std::string {aka std::basic_string<char>}’ to non-scalar type Book’ requested
    string tmp = "unix";
    //Book book1 = tmp;

    string test1 = "test book";
    /*4. explicit抑制了隐式的转换*/
    // invalid initialization of reference of type ‘int&’ from expression of type
    //book.isEqual(test1);

}
