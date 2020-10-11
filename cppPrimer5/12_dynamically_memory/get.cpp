#include <iostream>
#include <memory>

using namespace std;


int main(void)
{
    shared_ptr<int> sp(new int(1024));
   
    //1. shard_ptr的get()函数可以返回一个普通指针，但是要确保这个指针不会被free掉
    int *p = sp.get();
    cout << "now shard_ptr get:" << *p << endl;
    cout << sp.use_count() << endl;

    //2. 这个指针被free掉了,那为什么原本的没有报double free
    {
        shared_ptr<int> (p);
        cout << sp.use_count() << endl;
    }


    cout << "now shard_ptr get:" << *p << endl;


    //3.  double free 运行异常了
    //delete(p);
    //cout << "now shard_ptr get:" << *p << endl;
}
