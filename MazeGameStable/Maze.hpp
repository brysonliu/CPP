#ifndef Maze_hpp
#define Maze_hpp

#include "Map.hpp"
#include "Enemy.hpp"
#include <string>
#include <vector>
using namespace std;

class Player
{
    public:
        char sprite;
        int x;
        int y;
};

class Maze
{
    public:
        vector< vector<char> > maze;

        Maze();
        ~Maze();

        void play();        
        Player createPlayer(char sprite);
        
    private:
        int mMazeSize;
        bool mHasntWon;
        int mHitPoints;
        class Map* mMap;
        class Enemy* mEnemy1;
        class Enemy* mEnemy2;
        class Enemy* mEnemy3;
        class Enemy* mEnemy4;
        class Enemy* mEnemy5;

        void introduction();
        void mazeTemplate();
        void displayMaze();
        char getch();
};

#endif