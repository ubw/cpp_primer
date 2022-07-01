#include <iostream>

using namespace std;

//1. 类模板名不是一个类型，实例化类模板需要提供显示模板实参
//2. 在类模板自己的作用域中，可以直接使用模板名而不提供实参
template <typename elemType> class ListItem;
template <typename elemType> class List{
public:
    List(){
        cout << "List()" << endl;
    }
    List(const List &);
    List& operator=(const List &);
    ~List()
    {
        cout << "~List()" << endl;
    }
    void insert(ListItem<elemType> *ptr, elemType value);

private:
    ListItem<elemType> *front;
    ListItem<elemType> *end;
};

int main(void)
{
   List<int>  li;

}
