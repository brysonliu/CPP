#ifndef Maze_hpp
#define Maze_hpp

#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"
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
        int mEndX;
        int mEndY;
        bool mHasntWon;
        int mHitPoints;
        int mEnemyCount;
        char mEnemySprite;
        bool mEnemyRandom;
        class Menu *mMenu;
        class Map *mMap;
        class Player *mPlayer;
        vector<class Enemy *> mEnemy;
        
        void menu();
        void mazeTemplate();
        void displayMazeInitial();
        void displayMazePlaying();
        void endPoints();
        char getch();
};

#endif