#include "Chess.hpp"

int main()
{
    Chess* ptrChessGame = new Chess();
    ptrChessGame->play();
    delete ptrChessGame;
    
    return 0;
}
