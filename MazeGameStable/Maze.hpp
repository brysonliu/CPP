#ifndef Maze_hpp
#define Maze_hpp

#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
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
        class Map *mMap;
        class Player *mPlayer;
        vector<class Enemy *> mEnemy;

        void introduction();
        void mazeTemplate();
        void displayMazeInitial();
        void displayMazePlaying();
        int endPointX();
        int endPointY();
        char getch();
};

#endif