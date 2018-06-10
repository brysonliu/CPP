//
// Kaylin C. Tate
// DotA Arena
// Main File
//


#include "GameManager.hpp"

using namespace std;

int main()
{
    GameManager* ptrDotAArenaGame = new GameManager();
    
	while (ptrDotAArenaGame->gameActive == true)
    {
        ptrDotAArenaGame = ptrDotAArenaGame->playGame(ptrDotAArenaGame);
    }

    delete ptrDotAArenaGame;

    return 0;
}
