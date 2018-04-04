#include "Board.hpp"
#include <cstdlib>

Board::Board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board_[i][j] = " ";
        }
    }

    srand(time(0));

    if (rand()%2 == 0)
    {
        user_ = "X";
        computer_ = "O";
        turn_ = "u";
        uStart_ = true;
    }
    else
    {
        user_ = "O";
        computer_ = "X";
        turn_ = "c";
        uStart_ = false;
    }
}

Board::~Board()
{

}

string Board::getTurn()
{
    return turn_;
}

bool Board::userPlay(int x, int y)
{
    if (board_[y][x] == " ")
    {
        board_[y][x] = user_;
        turn_ = "c";
        return true;
    }

    return false;
}

bool Board::playMove(int x, int y)
{
    if (board_[y][x] == " ")
    {
        board_[y][x] = computer_;
        turn_ = "u";
        return true;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board_[i][j] == " ")
                {
                    board_[i][j] = computer_;
                    turn_ = "u";
                    return true;
                }
            }
        }
    }

    return false;
}

void Board::computerPlayRandom()
{
    srand(time(0));
    int x = rand() % 3;
    int y = rand() % 3;

    if (rand() % 2 == 0)
    {
        playMove(x, y);
    }
    else
    {
        playMove(x, x);
    }
}

void Board::computerPlay()
{
    int computerState[3][3];
    readBoard(computerState);

    cout << "Computer State: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << computerState[i][j] << " ";
        }

        cout << endl;
    }

    int x = 1;
    int y = 1;

    findBestMove(computerState, x, y);

    playMove(x, y);
}

void Board::readBoard(int boardState[3][3])
{
    // To calculate which square gives a potential fork for the AI
    bool boardStateHorizontal[3][3], boardStateVertical[3][3], boardStateDDiagonal[3][3], boardStateADiagonal[3][3];
    // To calculate which square gives a potential fork for the user
    bool bsh[3][3], bsv[3][3], bsdd[3][3], bsad[3][3];

    // Initializing the arrays of state
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_[i][j] != " ")
            {
                boardState[i][j] = -1;
            }
            else
            {
                boardState[i][j] = 0;
            }

            boardStateHorizontal[i][j] = false;
            boardStateVertical[i][j] = false;
            boardStateDDiagonal[i][j] = false;
            boardStateADiagonal[i][j] = false;
            bsh[i][j] = false;
            bsv[i][j] = false;
            bsdd[i][j] = false;
            bsad[i][j] = false;
        }
    }

    // Hard-coded move for the specific situation where
    // X - -
    // - O -
    // - - X
    // The only right move is to avoid corners (AI is playing O)

    int boardSum = 0;

    cout << "Board State: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << boardState[i][j] << " ";
            boardSum += boardState[i][j];
        }
        cout << endl;
    }

    if (boardSum == -3)
    {
        if ((board_[0][0] == board_[2][2] && board_[2][0] == board_[0][2]) 
            && board_[1][1] != " " && (board_[0][0] != " " || board_[2][0] != " "))
        {
            boardState[0][1] += 1000000;
            boardState[2][1] += 1000000;
            boardState[1][0] += 1000000;
            boardState[1][2] += 1000000;
            return;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Computing Horizontal wins
            // If the square is empty and the other two squares in the same row are filled and the same; e.g. X X * where * is the square we're evaluating
            if (boardState[i][j % 3] != -1 && board_[i][(j + 1) % 3] != " " 
                && board_[i][(j + 1) % 3] == board_[i][(j + 2) % 3])
            {
                // If they're filled by the computer
                if (board_[i][(j + 1) % 3] == computer_)
                {
                    boardState[i][j % 3] += 1000;
                }
                // If they're filled by the user
                else if (board_[i][(j + 1) % 3] == user_)
                {
                    boardState[i][j % 3] += 100;
                }
            }

            // Computing Vertical wins
            // If the square is empty and the other two squares in the same column are filled and the same; e.g. see "Computing Horizontal wins"
            if (boardState[j % 3][i] != -1 && board_[(j + 1) % 3][i] != " " 
                && board_[(j + 1) % 3][i] == board_[(j + 2) % 3][i])
            {
                // If they're filled by the computer
                if (board_[(j + 1) % 3][i] == computer_)
                {
                    boardState[j % 3][i] += 1000;
                }
                // If they're filled by the user
                else if (board_[(j + 1) % 3][i] == user_)
                {
                    boardState[j % 3][i] += 100;
                }
            }

            // Computing Horizontal points
            // If the square is empty and one of the other two squares is empty, but the other is filled; e.g. X - * where * is the square we're evaluating
            // A move that satisfies this condition forces the opponent to block
            if (boardState[i][j % 3] != -1 
                && (board_[i][(j + 1) % 3] == " " || board_[i][(j + 2) % 3] == " ") 
                && board_[i][(j + 1) % 3] != board_[i][(j + 2) % 3])
            {
                // If it's filled by the computer
                if (board_[i][(j + 1) % 3] == computer_ || board_[i][(j + 2) % 3] == computer_)
                {
                    boardState[i][j % 3] += 10;
                    boardStateHorizontal[i][j % 3] = true;
                }
                // If it's filled by the user
                else if (board_[i][(j + 1) % 3] == user_ || board_[i][(j + 2) % 3] == user_)
                {
                    boardState[i][j % 3] += 10;
                    if (uStart_)
                    {
                        bsh[i][j%3] = true;
                    }
                }
            }

            // Computing Vertical points
            // If the square is empty and one of the other two squares is empty, but the other is filled; e.g. see "Computing Horizontal points"
            // A move that satisfies this condition forces the opponent to block
            if (boardState[j % 3][i] != -1 
                && (board_[(j + 1) % 3][i] == " " || board_[(j + 2) % 3][i] == " ") 
                && board_[(j + 1) % 3][i] != board_[(j + 2) % 3][i])
            {
                // If it's filled by the computer
                if (board_[(j + 1) % 3][i] == computer_ || board_[(j + 2) % 3][i] == computer_)
                {
                    boardState[j % 3][i] += 10;
                    boardStateVertical[j % 3][i] = true;
                }
                // If it's filled by the user
                else if (board_[(j + 1) % 3][i] == user_ || board_[(j + 2) % 3][i] == user_)
                {
                    boardState[j % 3][i] += 10;
                    if (uStart_) 
                    {
                        bsv[j % 3][i] = true;
                    }
                }
            }

            // Horizontal potential
            // If the square is empty and the other two squares in the same row are empty; e.g. empty row
            if (boardState[i][j % 3] != -1 && board_[i][(j + 1) % 3] == " " 
                && " " == board_[i][(j + 2) % 3])
            {
                boardState[i][j % 3] ++;
            }

            // Vertical potential
            // If the square is empty and the other two squares in the same column are empty; empty column
            if (boardState[j % 3][i] != -1 && board_[(j + 1) % 3][i] == " " 
                && " " == board_[(j + 2) % 3][i])
            {
                boardState[j % 3][i] ++;
            }
        }

        // Descending diagonal wins
        // If the square is empty, and the other two squares on the descending diagonal are the same;
        // e.g. X - -
        //      - X - where * is the square we're evaluating
        //      - - *
        if (boardState[i % 3][i % 3] != -1 
            && board_[(i + 1) % 3][(i + 1) % 3] != " " 
            && board_[(i + 1) % 3][(i + 1) % 3] == board_[(i + 2) % 3][(i + 2) % 3])
        {
            // If they're filled by the computer
            if (board_[(i + 1) % 3][(i + 1) % 3] == computer_)
            {
                boardState[i % 3][i % 3] += 1000;
            }
            // If they're filled by the user
            else if (board_[(i + 1) % 3][(i + 1) % 3] == user_)
            {
                boardState[i % 3][i % 3] += 100;
            }
        }

        // Ascending diagonal wins
        // If the square is empty, and the other two squares on the ascending diagonal are the same; e.g. see "Ascending Diagonal wins"
        if (boardState[(5 - i) % 3][i % 3] != -1 
            && board_[(4 - i) % 3][(i + 1) % 3] != " " 
            && board_[(4 - i) % 3][(i + 1) % 3] == board_[(3 - i) % 3][(i + 2) % 3])
        {
            // If they're filled by the computer
            if (board_[(4 - i) % 3][(i + 1) % 3] == computer_)
            {
                boardState[(5 - i) % 3][i % 3] += 1000;
            }
            // If they're filled by the user
            else if (board_[(4 - i) % 3][(i + 1) % 3] == user_)
            {
                boardState[(5 - i) % 3][i % 3] += 100;
            }
        }

        // Descending diagonal points
        // If the square is empty and one of the other two squares is empty, but the other is filled;
        // e.g. X - -
        //      - - - where * is the square we're evaluating
        //      - - *
        if (boardState[i % 3][i % 3] != -1 
            && (board_[(i + 1) % 3][(i + 1) % 3] == " " || board_[(i + 2) % 3][(i + 2) % 3] == " ") 
            && board_[(i + 1) % 3][(i + 1) % 3] != board_[(i + 2) % 3][(i + 2) % 3])
        {
            // If it's filled by the computer
            if (board_[(i + 1) % 3][(i + 1) % 3] == computer_ || board_[(i + 2) % 3][(i + 2) % 3] == computer_)
            {
                boardState[i % 3][i % 3] += 10;
                boardStateDDiagonal[i % 3][i % 3] = true;
            }
            // If it's filled by the user
            else if (board_[(i + 1) % 3][(i + 1) % 3] == user_ || board_[(i + 2) % 3][(i + 2) % 3] == user_)
            {
                boardState[i % 3][i % 3] += 10;
                if (uStart_)
                {
                    bsdd[i % 3][i % 3] = true;
                }
            }
        }

        // Ascending diagonal points
        // If the square is empty and one of the other two squares is empty, but the other is filled
        if (boardState[(5 - i) % 3][i % 3] != -1 
            && (board_[(4 - i) % 3][(i + 1) % 3] == " " || board_[(3 - i) % 3][(i + 2) % 3] == " ")
            && board_[(4 - i) % 3][(i + 1) % 3] != board_[(3 - i) % 3][(i + 2) % 3])
        {
            // If it's filled by the computer
            if (board_[(4 - i) % 3][(i + 1) % 3] == computer_ || board_[(3 - i) % 3][(i + 2) % 3] == computer_)
            {
                boardState[(5 - i) % 3][i % 3] += 10;
                boardStateADiagonal[(5 - i) % 3][i % 3] = true;
            }
            // If it's filled by the user
            else if (board_[(4 - i) % 3][(i + 1) % 3] == user_ || board_[(3 - i) % 3][(i + 2) % 3] == user_)
            {
                boardState[(5 - i) % 3][i % 3] += 10;
                if (uStart_)
                {
                    bsad[(5 - i) % 3][i % 3] = true;
                }
            }
        }

        /*// Descending diagonal potential
         // If the square is empty, and the other two squares on the descending diagonal are empty
         if (boardState[i % 3][i % 3] != -1 
             && board_[(i + 1) % 3][(i + 1) % 3] == " " 
             && " " == board_[(i + 2) % 3][(i + 2) % 3]) {
             boardState[i % 3][i % 3]++;
         }

         // Ascending diagonal potential
         // If the square is empty, and the other two squares on the ascending diagonal are empty
         if (boardState[(5 - i) % 3][i % 3] != -1 
             && board_[(4 - i) % 3][(i + 1) % 3] == " " && " " == board_[(3 - i) % 3][(i + 2) % 3]) {
             boardState[(5 - i) % 3][i % 3] ++;
         }*/
    }

    // Calculating forks
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // If the square generates a fork for the AI, +30 points
            if (boardStateVertical[i][j])
            {
                if (boardStateHorizontal[i][j])
                {
                    boardState[i][j] += 30;
                }
                if (boardStateADiagonal[i][j])
                {
                    boardState[i][j] += 30;
                }
                if (boardStateDDiagonal[i][j])
                {
                    boardState[i][j] += 30;
                }
            }
            if (boardStateHorizontal[i][j])
            {
                if (boardStateADiagonal[i][j])
                {
                    boardState[i][j] += 30;
                }
                if (boardStateDDiagonal[i][j])
                {
                    boardState[i][j] += 30;
                }
            }
            if (boardStateDDiagonal[i][j])
            {
                if (boardStateADiagonal[i][j])
                {
                    boardState[i][j] += 30;
                }
            }

            // If the square generates a fork for the user, +25 points
            // Better to create a fork first than to block a potential one from the user
            if (bsv[i][j])
            {
                if (bsh[i][j])
                {
                    boardState[i][j] += 25;
                }
                if (bsad[i][j])
                {
                    boardState[i][j] += 25;
                }
                if (bsdd[i][j])
                {
                    boardState[i][j] += 25;
                }
            }
            if (bsh[i][j])
            {
                if (bsad[i][j])
                {
                    boardState[i][j] += 25;
                }
                if (bsdd[i][j])
                {
                    boardState[i][j] += 25;
                }
            }
            if (bsad[i][j])
            {
                if (bsdd[i][j])
                {
                    boardState[i][j] += 25;
                }
            }
        }
    }
}

void Board::findBestMove(int boardState[3][3], int& x, int& y)
{
    // Find the square that has the highest points on boardState[3][3]
    int bestScore = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (boardState[i][j] > bestScore)
            {
                bestScore = boardState[i][j];
                x = j;
                y = i;
            }
            // If two squares have the same points, randomize the choice
            else if (boardState[i][j] == bestScore && rand()%2)
            {
                bestScore = boardState[i][j];
                x = j;
                y = i;
            }
        }
    }
    // If the center is the best score, don't randomize
    if (boardState[1][1] == bestScore)
    {
        x = 1;
        y = 1;
    }
}

void Board::clearBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board_[i][j] = " ";
        }
    }
}

void Board::displayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "" << board_[i][j];
            if (j < 2)
            {
                cout << "|";
            }
        }
        if (i < 2)
        {
            cout << endl << "-+-+-" << endl;
        }
        else
        {
            cout << endl;
        }
    }
}

bool Board::gameEnd()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_[i][j] == " ")
            {
                return false;
            }
        }
    }

    return true;
}

bool Board::gameWinner(string& winner)
{
    for (int i = 0; i < 3; i++)
    {
        // Horizontal
        // If the square is empty and the other two squares in the same row are empty
        if (board_[i][0] == board_[i][1] && board_[i][1] == board_[i][2] && board_[i][0] != " ")
        {
            if (board_[i][0] == computer_)
            {
                winner = "computer";
                return true;
            }
            else
            {
                winner = "user";
                return true;
            }
        }

        // Vertical
        // If the square is empty and the other two squares in the same column are empty
        if (board_[0][i] == board_[1][i] && board_[1][i] == board_[2][i] && board_[0][i] != " ")
        {
            if (board_[i % 3][i] == computer_)
            {
                winner = "computer";
                return true;
            }
            else
            {
                winner = "user";
                return true;
            }
        }
    }

    // Descending diagonal
    // If the square is empty, and the other two squares on the descending diagonal are empty
    if (board_[0][0] == board_[1][1] && board_[1][1] == board_[2][2] && board_[0][0] != " ")
    {
        if (board_[0][0] == computer_)
        {
            winner = "computer";
            return true;
        }
        else
        {
            winner = "user";
            return true;
        }
    }

    // Ascending diagonal
    // If the square is empty, and the other two squares on the ascending diagonal are empty
    if (board_[2][0] == board_[1][1] && board_[1][1] == board_[0][2] && board_[2][0] != " ")
    {
        if (board_[2][0] == computer_)
        {
            winner = "computer";
            return true;
        }
        else
        {
            winner = "user";
            return true;
        }
    }

    return false;
}