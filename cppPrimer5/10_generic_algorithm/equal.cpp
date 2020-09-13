#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> vs{"hello", "generic", "algorithm", "readonly", "equal"};
    vector<string> vs1{"hello", "generic", "algorithm", "readonly"};
    list<const char *> lc{"hello", "generic", "algorithm", "readonly", "equal"};
    list<const char *> lc2{"ello", "generic", "algorithm", "readonly", "equal"};
    list<const char *> lc3{"hello", "generic", "algorithm", "readonly"};

    // 1. 类型不同也可以用equal,因为只要类型支持==符号就可以,返回的是bool值
    int ret = equal(vs.begin(),vs.end(), lc.begin());
    //2. Segmentation fault, equal，第二个迭代器只有首迭代器的默认长度相同，否则段错误 
    //int ret2 = equal(vs.begin(),vs.end(), vs1.begin());
    int ret3 = equal(lc.begin(),lc.end(), lc2.begin());
    //int ret4 = equal(lc.begin(),lc.end(), lc3.begin());

    cout << ret << endl;
    //cout << ret2 << endl;
    cout << ret3 << endl;
    //cout << ret4 << endl;
}
