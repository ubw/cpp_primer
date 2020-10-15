#include <iostream>
#include <string>
#include <map>
#include "lottery.h"


using namespace std;


const map<pair<int, int>, int> lottery::prize_map{
{{5,2}, 1},
{{5,1}, 2},
{{5,0}, 3},
{{4,2}, 4},
{{4,1}, 5},
{{3,2}, 6},
{{4,0}, 7},
{{2,2}, 8},
{{3,1}, 8},
{{1,2}, 9},
{{3,0}, 9},
{{2,1}, 9},
{{0,2}, 9}
};

int lottery::match(lottery &tmp){
   int match_red = 0;
   int match_blue = 0;
   for(int i = 0; i < 5; i++) 
   {
       if(red[i] == tmp.getRed(i)) match_red++;
   }

   for(int i = 0; i<2; i++)
   {
       if(blue[i] == tmp.getBlue(i)) match_blue++;
   }

   int ret = 0;
   try{
       ret = lottery::prize_map.at({match_red, match_blue}); 
       prize = ret;
   }
   catch(std::exception& e){
       cout << e.what() << endl;
       cout << "match_red:" << match_red << " match_blue:"  << match_blue << endl;
   }

   return ret;
}


int lottery::getRed(int index)
{
    return red[index];
}

int lottery::getBlue(int index)
{
    return blue[index];
}

  
