#include <iostream>
#include <map>

using namespace std;

int main(void)
{

    map<string, int> m{{"hello", 5},{"associative", 4},{"container", 3},{"find", 2},{"map", 1}};


    for(auto it=m.begin(); it != m.end(); )
    {
        if(it->second == 3)
        {
            it = m.erase(it); 
            continue;
        }
        it++;
    }

    for(auto p : m)
    {
        cout << p.first << "," << p.second << endl;
    }

}
