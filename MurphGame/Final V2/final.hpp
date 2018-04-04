#include<string>


#ifndef final_hpp
#define final_hpp
#include "player.hpp"


class Final
{
public:
    
    
    void game();
    int main();
    
    
    
private:
    
    
    bool mRunning=1; //Used to run the loop while the variable is 1
    int mUserInput; //User input variable
    void mTitleFunc(); 
    void mNewGameFunc(); 
    int mPlayerLocation; //Setting Player Location. The number is the AREA.
    int mPlayerInfo[2]; //Information gathered when starting a new game is stored here.
     
    
};

#endif