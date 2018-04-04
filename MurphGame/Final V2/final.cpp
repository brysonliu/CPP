#include <iostream>
#include <cstdlib>
#include <string>
#include "final.hpp"
#include "player.hpp"

using namespace std;
/*
Final::Final()      // constructor
{
    cout << "Game object being created. " << this << endl;
}

Final::~Final()     // destructor
{
    delete mPtrPiece;
    cout << "Game object being deleted. " << this << endl;
}


*/



int Final::main()
{
    while(mRunning)
    {
        mTitleFunc();// Initializes the Title Screen
        game(); // Starts the game function
    }
    return 0; // Ends the game
}
void Final::mTitleFunc() 
    {
    if (mPlayerLocation==0)
    {
        cout << "\t\t\t\t   Dungeon Escape\n\n\n"; // Displays the Title
        cout << "\t\t\t\t   1: Play\n";
        cin >> mUserInput; //Stores user input into a variable

// The variable is now examined with this "If"Statement.
    if(mUserInput == 1) {
        mNewGameFunc(); // Creates a new game if the input=1
        }
  

    return;
    }
    else //This will allow the player to play by bypassing the Title.
    {
        return;
    }
}
void Final::mNewGameFunc() {
        cout << "Darkness.\n\n";
        cout << "You awaken in a cold, wet stone room. There is a single, tiny bed.\n\n";
        cout <<"You Feel the memories of your past life coming back to haunt you. Were you a: 1) Barbarian, 2) Rogue, or 3) mage?\n\n";
        cin >> mUserInput;
    mPlayerInfo[1] = mUserInput; // Store player information
       
   
    mPlayerLocation=1; 
    
    
    return; 
}


void Final::game() 
{ //The game itself is inside this function

    if(mPlayerLocation == 1)
    { // main cell
            cout << "You get up and open the door out of your cell.\n\n";
            cout << "You notice two identical paths \n\n";
            cout << " 1: Go to the room\n 2: Go past the room.\n\n";
            cin >> mUserInput;
            
        if (mUserInput==1) mPlayerLocation=2;
        // Two options, each of them changes the Area.
        if (mUserInput==2) mPlayerLocation=3;
        
        return;
    
    }
    if (mPlayerLocation==2)
    {// Left
           
            cout << "You head into the room.\n\n";
            cout << "On your right, you see a small jewel hidden behind a box.\n\n";
            cout << " 1: continue through to the next room\n 2: Pick up the jewel and move to the next room.\n\n";
            cin >> mUserInput;
           
        if (mUserInput==1) mPlayerLocation=3;
        if (mUserInput==2) mPlayerLocation=4;
         
        return;
        
    }
       
    if (mPlayerLocation==3)
    {// Left
           
                
            cout << "You find yourself at a dead end.\n\n";
            cout << "there is a small crack in the wall. Maybe you missed something?\n\n";
            cout << " 1: Go to the room.\n\n";
            cin >> mUserInput;
           
        if (mUserInput==1) mPlayerLocation=2;
    
        return;
         
    }
    if (mPlayerLocation==4)
        { 
            cout << "As you enter the hallway, you notice that there is a groove in the wall that is the same size as the jewel you picked up.\n\n";
            cout << "When you approach the wall, the jewel gives off a slight glow.\n\n";
            cout << "You reach forward and insert the jewel into the crack of the wall.\n\n";
            cout << "A door appears followed by a long, dark hallway.\n\n";
            cout << " 1: Enter the Dark Hallway. \n 2: Stand and stare at the new doorway.\n\n";
            cin >> mUserInput;
           
        if (mUserInput==1) mPlayerLocation=5;
        if (mUserInput==2) mPlayerLocation=4;
    
        return;
             
            
    
    }
    if (mPlayerLocation==5)
        { 
            cout << "As you enter the hallway, the light goes out.\n\n";
            cout << "You continue along the path. Lit only by the light of the jewel.\n\n";
            cout << "As you hold the jewel before you, a deep feeling of unease washes over you.\n\n";
            cout << "A door appears directly to your left. the corridor continues.\n\n";
            cout << " 1: Enter door to the left. \n 2: continue along the corridor.\n\n";
            cin >> mUserInput;
            
        if (mUserInput==1) mPlayerLocation=6;
        if (mUserInput==2) mPlayerLocation=7;
          
            return;
   
        }   
    if (mPlayerLocation==6)
        { 
            
            cout << "you attempt to break the lock.\n\n";
            Player::LockPick;
            if (Player::randomNumber >= 10)
            { 
                cout << " you manage to break into the room.\n";
                cout << " You find nothing of interest. \n\n\n\n";
                mPlayerLocation=5;
                
                return;
                 
            }
            if (Player::randomNumber <= 9)
            {
                cout << " You could not manage to break the lock. \n\n\n\n";
               
                mPlayerLocation=5;
                
                return;
                
            }
            
        }
            
    if (mPlayerLocation==7)
        { 
            cout << "You take a quick break to gather your thoughts.\n\n";
            cout << "As you push your way through the dark tunnels, you find a dim light in the distance.\n\n";
            cout << "Do you want to: \n1. Take a break, you earned it! \nor \n2. Follow the light.\n\n";
            cin >> mUserInput;
            
        if (mUserInput==1) mPlayerLocation=7;
        if (mUserInput==2) mPlayerLocation=8;
       
        return; 
        
        }   
    if (mPlayerLocation==8)
        { 
            cout << "The door is made from a sturdy material.\n\n";
            cout << "Do you: \n1. Observe the door. Something seems off. \nor  \n2.Enter the door.\n\n";
            cin >> mUserInput;
           
        if (mUserInput==1) mPlayerLocation=8;
        if (mUserInput==2) mPlayerLocation=9;
        
        return; 
         
        }   
    if (mPlayerLocation==9)
        { 
            cout << "You open the door.\n\n";
            cout << "You are blinded by the brightness of the light during mid day! Something seems off. Like you are living a nightmare...\n\n";
            cout << "Do you:\n 1.Run back inside. the light burns!\n 2.This Seems too easy you have to be dreaming!\n\n";
            cin >> mUserInput;
           
        if (mUserInput==1) mPlayerLocation=8;
        if (mUserInput==2) mPlayerLocation=10;
      
        return; 
       
        }
    if (mPlayerLocation==10)
        { 
            cout << "You exit the dungeon and take a deep breath in.\n\n";
            cout << "As you start to walk away, Guards round the corner and capture you again.\n\n";
            cout << "you are knocked out and dragged back to your cell.\n\n";
            cout << "Press 1 to try again!\n\n";
            
            cin >> mUserInput;
          
        if (mUserInput==1) mPlayerLocation=1;
     
        return;
        
        }
    
    }
      
    




  


