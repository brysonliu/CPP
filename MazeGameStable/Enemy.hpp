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
        DirectionX pastDirX;
        DirectionY pastDirY;
        
        Enemy(vector< vector<char> >& maze, int size, char icon);
        ~Enemy();
        char move(vector< vector<char> >& maze, int i, int j, string& smove, bool& nc);
};

#endif