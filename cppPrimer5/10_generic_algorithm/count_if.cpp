#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<string> vs{"hello", "generic", "algorithm", "hello", "predicate", "lambda", "bind"};

    auto ret =  count_if(vs.begin(), vs.end(), [](string &tmp){return tmp.size() <= 6;});

    cout << ret << endl;


}
