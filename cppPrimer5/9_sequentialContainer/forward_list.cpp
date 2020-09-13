#include <iostream>
#include <forward_list>

using namespace std;

int main(void)
{
    forward_list<int> fi{0,1,2,3,4,5,6,7,8,9,10};


    //删除奇数的元素
    //1.  forward_list因为是单向链表，删元素的话要删下一个，需要保存上一个的指针
    auto pre = fi.before_begin();
    auto cur = fi.begin();

    while(cur != fi.end())
    {
        if(*cur & 1)
        {
            cout << *cur << endl;
            //2. 删除后面一个
            // 增加同理，是insert_after , emplace_after
            //3. 删除后，原来的迭代器就失效了 
            cur = fi.erase_after(pre);
        }else {
            // 移动前，保存上个指针指向
            pre = cur;
            cur++;
        }
    }

    for(auto i:fi)
    {
        cout << i << ","; 
    }

    cout << endl;

}
