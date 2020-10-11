#include <iostream>
#include <set>
#include <string>

using namespace std;

class Lottery{
public:
    int id;
    string date;
    string res;

public:
    Lottery(int id, string date, string res):id(id),date(date),res(res){}
    Lottery(){}
    ~Lottery(){}

};

//2. 构建关联容器的可选函数指针参数必须是容器元素的类型
//error: cannot convert ‘const key_type {aka const Lottery}’ to ‘int’ in argument passing
//3. 为什么我这里和下面typedef改成引用不行????
//4. 为什么const 引用就可以了?
bool foo(const Lottery &l1, const  Lottery &l2)
{
    return true;
}

//4. 定义函数指针，需要括起来，不然优先级没有括号高，右边结合的关系??
typedef bool (*compareLottery)(const Lottery &,const  Lottery &);

int main(void)
{
    //1. 必须要加*??不是函数名就表示函数指针吗?
    multiset<Lottery, compareLottery>  multiLottery(foo);

    Lottery l1(1, "2020-09-20", "1-2-3-4-5-6-7");
    Lottery l2(2, "2020-09-23", "1-3-5-7-9-1-7");
    multiLottery.insert(l1);
    multiLottery.insert(l2);

   //2. 遍历，定义迭代器，不用auto 
   for(multiset<Lottery, compareLottery>::iterator it=multiLottery.begin(); it != multiLottery.end(); it++)
   {
       cout << it->id << endl;
   }

}
