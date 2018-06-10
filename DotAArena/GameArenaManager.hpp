//
// Kaylin C. Tate
// DotA Arena
// Arena Manager Header File 
//

#ifndef GameArenaManager_hpp
#define GameArenaManager_hpp

class ArenaManager
{

    public:
        ArenaManager(float matchTime, bool dayTime, float dayNightRotationTime);
        ~ArenaManager();
        ArenaManager* dayNightCycle(ArenaManager* pArena);

        float matchTime;
        bool dayTime;
        float dayNightRotationTime;
};

#endif