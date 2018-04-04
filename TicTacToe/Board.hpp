#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Board
{
    public:
        Board();
        ~Board();

        string getTurn();

        bool userPlay(int x, int y);
        bool playMove(int x, int y);

        void computerPlayRandom();
        void computerPlay();

        void readBoard(int boardState[3][3]);
        void findBestMove(int boardState[3][3], int& x, int& y);

        void clearBoard();
        void displayBoard();

        bool gameEnd();
        bool gameWinner(string& winner);

    private:
        string board_[3][3];
        string user_;
        string computer_;
        string turn_;
        bool uStart_;
};

#endif