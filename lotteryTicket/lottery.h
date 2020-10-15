#ifndef _LOTTERY_H
#define _LOTTERY_H

#include <iostream>
#include <string>
#include <map>
#include "lottery.h"


using namespace std;

class lottery{
private:
int red[5];
int blue[2];
int prize;
public:
const static map<pair<int, int>, int> prize_map;

public:
lottery(string tmp){
    for(int i = 0; i < 7; i++){
        if(i < 5)
        {
            red[i] = stoi(tmp.substr(i*3,2));
        } else {
            blue[i-5] = stoi(tmp.substr(i*3,2));
        }
    }

    prize = 0;
}

int match(lottery &l);
int getRed(int index);
int getBlue(int index);
int getPrize(){return prize;};
};

#endif
