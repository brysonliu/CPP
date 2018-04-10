#ifndef Enemy_hpp
#define Enemy_hpp

#include "Maze.hpp"
#include <string>
#include <vector>

enum DirectionX { Right, Left };
enum DirectionY { Up, Down };

class Enemy
{
    public:
        char sprite;
        int x;
        int y;
        bool once;
        string prevMove;
        DirectionX pastDirX;
        DirectionY pastDirY;
        
        Enemy(vector< vector<char> >& maze, int size, char icon);
        ~Enemy();
        
        void resetMove();
        char move(vector< vector<char> >& maze, int i, int j);
};

#endif