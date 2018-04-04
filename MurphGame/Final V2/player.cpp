#include <iostream>
#include <cstdlib>
#include <string>
#include "player.hpp"
#include "final.hpp"

using namespace std;

srand((unsigned)time(NULL));

int Player::LockPick()
{
     randomNumber = randomInt(1,20);
    
    
    return;
}

double Player::randomInt (int min, int max)
{
    int range = max - min + 1;
    return rand()%range + min;
}
