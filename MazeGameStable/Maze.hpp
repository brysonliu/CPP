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
        int mEnemyCount;
        class Map* mMap;
        class Player* mPlayer;
        vector<class Enemy *> mEnemy;

        void introduction();
        void mazeTemplate();
        void displayMazeInitial();
        void displayMazePlaying();
        char getch();
};

#endif