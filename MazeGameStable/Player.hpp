#ifndef Player_hpp
#define Player_hpp

#include "Maze.hpp"

class Player
{
    public:
        char sprite;
        int x;
        int y;

        Player(char icon);
        ~Player();
};

#endif