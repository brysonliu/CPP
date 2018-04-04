#ifndef Maze_hpp
#define Maze_hpp

#include "Map.hpp"
#include <string>
#include <vector>
using namespace std;

enum DirectionX { Right, Left };
enum DirectionY { Up, Down };

class Player
{
    public:
        char sprite;
        int x;
        int y;
};

class Enemy
{
    public:
        char sprite;
        int x;
        int y;
        DirectionX pastDirX;
        DirectionY pastDirY;
};

class Maze
{
    public:
        vector< vector<char> > maze;

        Maze();
        ~Maze();

        void play();        
        Player createPlayer(char sprite);
        Enemy createEnemy(char sprite);
        
    private:
        int mMazeSize;
        bool mHasntWon;
        int mHitPoints;
        class Map* mMap;

        void introduction();
        void mazeTemplate();
        void displayMaze();
        char MoveEnemy(Enemy& enemy, vector< vector<char> >& maze, int i, int j, string& smove, bool& nc);
        char getch();
};

#endif