#ifndef Enemy_hpp
#define Enemy_hpp

#include "Maze.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

enum DirectionX { Right, Left };
enum DirectionY { Up, Down };

class Enemy
{
    public:
        char sprite;
        int damage;
        int x;
        int y;
        bool once;
        string prevMove;
        DirectionX pastDirX;
        DirectionY pastDirY;
        
        Enemy(vector< vector<char> > &maze, int size, char icon, bool isRandom);
        ~Enemy();
        
        void resetMove();
        char move(vector< vector<char> > &maze, int i, int j);
    
    private:
        void shuffle();
        void difficulty(char spr);
};

#endif