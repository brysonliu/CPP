#ifndef Menu_hpp
#define Menu_hpp

#include <cstdlib>
#include <iostream>
using namespace std;

class Menu
{
    public:
        int mazeSize;
        int enemyCount;
        int enemyDifficulty;
        bool randomDifficulty;
        char enemySprite;
    
        Menu();
        ~Menu();

        void introduction();

    private:
        void sizeMenu();
        void difficultyMenu();
};

#endif