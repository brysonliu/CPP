//
// Kaylin C. Tate
// DotA Arena
// Game Item Manager File
//

#include "GameManager.hpp"
#include "GameItemManager.hpp"
#include "CombatManager.hpp"
#include "GameEntityManager.hpp"

using namespace std;

GameItem::GameItem(string _itemName, int _itemCost, int _itemSTR, int _itemAGI, int _itemINT, 
                    int _itemHP, float _itemHPR, int _itemMP, float _itemMPR, 
                    int _itemAttackSpeed, int _itemAttackRange, int _itemDMG, float _itemArmor, int _itemMove, float _itemMovePercent, float _itemMagicResist, float _itemSpellAMP, float _itemManaLossReduc, float _itemStatusResist)
{
    itemName = _itemName;
    itemCost = _itemCost;
    itemSTR = _itemSTR;
    itemAGI = _itemAGI;
    itemINT = _itemINT;
    itemHP = _itemHP;
    itemHPR = _itemHPR;
    itemMP = _itemMP;
    itemMPR = _itemMPR;
    itemAttackSpeed = _itemAttackSpeed;
    itemAttackRange = _itemAttackRange;
    itemDMG = _itemDMG;
    itemArmor = _itemArmor;
    itemMove = _itemMove;
    itemMovePercent = _itemMovePercent;
    itemMagicResist = _itemMagicResist;
    itemSpellAMP = _itemSpellAMP;
    itemManaLossReduc = _itemManaLossReduc;
    itemStatusResist = _itemStatusResist;
}

GameItem::~GameItem()
{

}
