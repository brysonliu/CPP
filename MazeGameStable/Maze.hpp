#ifndef Maze_hpp
#define Maze_hpp

#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <string>
#include <vector>
using namespace std;

class Maze
{
    public:
        vector< vector<char> > maze;

        Maze();
        ~Maze();

        void play();
        
    private:
        int mMazeSize;
        bool mHasntWon;
        int mHitPoints;
        class Map* mMap;
        class Player* mPlayer;
        class Enemy* mEnemy1;
        class Enemy* mEnemy2;
        class Enemy* mEnemy3;
        class Enemy* mEnemy4;
        class Enemy* mEnemy5;
        class Enemy* mEnemy6;
        class Enemy* mEnemy7;
        class Enemy* mEnemy8;
        class Enemy* mEnemy9;

        void introduction();
        void mazeTemplate();
        void displayMaze();
        char getch();
};

#endif