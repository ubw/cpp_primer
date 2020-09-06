#include <iostream>
#include <string>

using namespace std;

class Book{
public:
    Book(string bookName){
        cout << "book(string) constructer" << endl;
    }
    void isEqual(Book otherBook){
        cout << "in isEqual()" << endl;
    }
private:
    string name;
};

int main(void)
{
    /*直接初始化*/
    Book book("c++ primer");
    /*拷贝初始化 */
    Book book1 = book;

    string test1 = "test book";
    /*1. 转为了一个常量引用*/
    book.isEqual(test1);
    //2. 只允许一步类型转换
    //error: no matching function for call to ‘Book::isEqual(const char [10])’
    //book.isEqual("test book");
}
