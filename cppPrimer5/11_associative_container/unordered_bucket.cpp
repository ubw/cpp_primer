#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
    unordered_map<string, int> um{};
    string tmp;

    while(cin >> tmp)
    {
        um[tmp]++;
    }

    //1. 无序容器，桶管理，桶的数目
    cout << um.bucket_count() << endl;

    //2. 最大桶的数目
    cout << um.max_bucket_count() << endl;

    cout << "======" << endl;
    //3. 第n个桶有几个元素
    for(int i = 0; i < um.bucket_count(); i++)
    {
        cout << um.bucket_size(i) << endl;
    }
    cout << "======" << endl;

    //4. 关键字是k的元素在哪个桶中

    cout << um.bucket("hello") << endl;
    cout << um.bucket("hello1") << endl;





}
