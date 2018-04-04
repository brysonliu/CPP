#include "Maze.hpp"
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Maze* mazeGame = new Maze();
    mazeGame->play();
    delete mazeGame;
    
    return 0;
}