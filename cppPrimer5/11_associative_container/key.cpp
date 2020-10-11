#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

//1. 需要元素支持<操作，否则需要自定义严格弱序
int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    vector<int>::iterator vit1 = vi.begin()++;
    vector<int>::iterator vit2 = vi.begin()++;
    vector<int>::iterator vit3 = vi.begin()++;

    multimap<vector<int>::iterator, int> multimapIt;
    //为什么不可以?????
    //multimapIt[vit1]++;
    //multimapIt[vit1]++;
    //
    
  
    //2. 因为list<int>::iterator 不支持<，所以这个不可以定义??
    list<int> li{1,2,3,4,5,6,7,8,9};
    list<int>::iterator lit1 = li.begin()++;

    map<list<int>::iterator, int> mapIt;

    

   
}
