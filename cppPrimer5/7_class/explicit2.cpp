#include <iostream>
#include <string>

using namespace std;

class Book{
public:
    //1. explicit 去除explicit 让构造函数支持隐式转换
    Book(string bookName){
        cout << "book(string) constructer" << endl;
    }
    /*
    void isEqual(Book otherBook){
        //形参貌似没有构造这个对象?
        cout << "in isEqual(Book)" << endl;
    }
    */

    void isEqual(const Book& otherBook){
       cout << "in isEqual(Book&)" << endl;
    }
private:
    string name;
};

int main(void)
{
    /*2. 直接初始化*/
    Book book("c++ primer");
    /*3. 拷贝初始化可以 */
    string tmp = "unix";
    Book book1 = tmp;

    string test1 = "test book";
    /*4. explicit抑制了隐式的转换,去掉就能够支持*/
    book.isEqual(test1);

    cout << "=====" << endl;

    /*5. explicit 参数的引用，因为是临时量，所以是const的不能修改,传值的话是因为创建了一个新的副本,引用必须指定为const*/
    book.isEqual(test1);
}
