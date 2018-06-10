//
// Kaylin C. Tate
// DotA Arena
// Arena Manager File
//

#include "GameArenaManager.hpp"

#include <iostream>

using namespace std;

ArenaManager::ArenaManager(float _matchTime, bool _dayTime, float _dayNightRotationTime)
{
    matchTime = _matchTime;
    dayTime = _dayTime;
    dayNightRotationTime = _dayNightRotationTime;
}

ArenaManager::~ArenaManager()
{
    cout << "Arena has been destroyed." << endl;
}

ArenaManager* ArenaManager::dayNightCycle(ArenaManager* pArena)
{
    if (pArena->dayTime == true)
    {
        cout << "The light of the sun fades as the dark of night takes it's place." << endl;
        pArena->dayTime = false;
    }
    if (pArena->dayTime == false)
    {
        cout << "Darkness flees back to the wretched depths it came as the light returns again." << endl;
        pArena->dayTime = true;
    }

    pArena->dayNightRotationTime += 10;

    return pArena;
}