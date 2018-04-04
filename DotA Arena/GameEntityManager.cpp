//
// Kaylin C. Tate
// DotA Arena
// GameEntity Manager File
//

#include "GameManager.hpp"
#include "CombatManager.hpp"
#include "GameEntityManager.hpp"
#include "GameItemManager.hpp"

GameEntity::GameEntity(string _entityName, int _currentLvl, int _mainATRType, bool _meleeAttack, int _attackRange, float _BAT, float _BCT, int _baseMovementSpeed, float _baseArmor, 
                    int _baseSTR, int _baseAGI, int _baseINT, float _perLvlSTR, float _perLvlAGI, float _perLvlINT, int _baseHP, int _baseMP, float _baseHPR, float _baseMPR, int _baseMaxDMG, int _baseMinDMG, float _baseMagicResist, 
                    int _dayVision, int _nightVision,
                    bool _isPlayer, int _inventory, int _goldSupply)
{
    entityName = _entityName;
    currentLvl = _currentLvl;
    mainATRType = _mainATRType;
    meleeAttack = _meleeAttack;
    attackRange = _attackRange;
    BAT = _BAT;
    BCT = _BCT;
    baseMovementSpeed = _baseMovementSpeed;
    baseArmor = _baseArmor;
    baseSTR = _baseSTR;
    baseAGI = _baseAGI;
    baseINT = _baseINT;
    perLvlSTR = _perLvlSTR;
    perLvlAGI = _perLvlAGI;
    perLvlINT = _perLvlINT;
    baseHP = _baseHP;
    baseMP = _baseMP;
    baseHPR = _baseHPR;
    baseMPR = _baseMPR;
    baseMaxDMG = _baseMaxDMG;
    baseMinDMG = _baseMinDMG;
    baseMagicResist = _baseMagicResist;
    dayVision = _dayVision;
    nightVision = _nightVision;

    isPlayer = _isPlayer;
    inventory = _inventory;
    goldSupply = _goldSupply;
}

GameEntity::~GameEntity()
{
    cout << "Destroy Unit" << endl;
}