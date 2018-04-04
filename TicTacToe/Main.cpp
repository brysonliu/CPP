#include <iostream>
#include <chrono>

#include "Board.hpp"

using namespace std;
using namespace std::chrono;

int main()
{
    cout << endl << "Would you like to play tic-tac-toe? (y/n) ";
    string answer;
    cin >> answer;

    while (answer == "y")
    {
        Board board;
        bool firstMoveRandom = true;
        string winner;

        while (!board.gameEnd() && !board.gameWinner(winner))
        {
            cout << "Current board: " << endl;
            board.displayBoard();
            cout << "____________________" << endl;

            if (board.getTurn() == "u")
            {
                firstMoveRandom = false;

                cout << "Your turn" << endl;

                int x;
                int y;

                try
                {
                    cout << "Please enter x (0 to 2): ";
                    cin >> x;

                    cout << "Please enter y (0 to 2): ";
                    cin >> y;
                    if (y < 0 || y > 2 || x < 0 || x > 2)
                    {
                        throw runtime_error("Error: must enter between 0 and 2");
                    }
                }
                catch (runtime_error& e)
                {
                    cout << e.what() << endl;
                }

                board.userPlay(x, y);
            }

            else if (board.getTurn() == "c")
            {
                if (firstMoveRandom)
                {
                    board.computerPlayRandom();
                    firstMoveRandom = false;
                }
                else
                {
                    high_resolution_clock::time_point t1 = high_resolution_clock::now();

                    board.computerPlay();

                    high_resolution_clock::time_point t2 = high_resolution_clock::now();
                    double duration = duration_cast<microseconds>( t2 - t1 ).count();
                    cout << duration/1000000 << " seconds" << endl;
                }
            }
        }

        if (winner.size() != 0)
        {
            cout << "The " << winner << " has won the game!" << endl;
        }

        else cout << "The game was a tie!" << endl;

        board.displayBoard();

        cout << "Would you like to play again? (y/n) ";
        cin >> answer;
    }

    return 0;
}