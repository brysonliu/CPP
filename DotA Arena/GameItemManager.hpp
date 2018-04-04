//
// Kaylin C. Tate
// DotA Arena
// Game Item Manager Header File
//


#ifndef GameItemManager_hpp
#define GameItemManager_hpp

#include <string>

using namespace std;

class GameEntity;

class GameItem
{

    public:

		GameItem(string itemName, int itemCost, int itemSTR, int itemAGI, int itemINT, 
                    int itemHP, float itemHPR, int itemMP, float itemMPR, 
                    int itemAttackSpeed, int itemAttackRange, int itemDMG, float itemArmor, int itemMove, float itemMovePercent, float itemMagicResist, float itemSpellAMP, float itemManaLossReduc, float itemStatusResist);
        ~GameItem();

        string itemName;
        int itemCost;
        int itemSTR;
        int itemAGI;
        int itemINT;
        int itemHP;
        float itemHPR;
        int itemMP;
        float itemMPR;
        int itemAttackSpeed;
        int itemAttackRange;
        int itemDMG;
        float itemArmor;
        int itemMove;
        float itemMovePercent;
        float itemMagicResist;
        float itemSpellAMP;
        float itemManaLossReduc;
        float itemStatusResist;
};

#endif
