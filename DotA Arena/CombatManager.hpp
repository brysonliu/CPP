//
// Kaylin C. Tate
// DotA Arena
// Combat Manager Header File
//

#ifndef CombatManager_hpp
#define CombatManager_hpp

using namespace std;


class ArenaManager;

class GameEntity;

class GameManager;

class CombatManager
{
    public:
        CombatManager();
        ~CombatManager();

        GameManager* tournamentCombat(GameEntity* pPlayer, GameEntity* pEnemy1, GameEntity* pEnemy2, GameEntity* pEnemy3, GameManager* ptrDotAArenaGame);
        void actionPhase(GameEntity* pUnitA, GameEntity* pUnitB, GameEntity* pUnitC, GameEntity* pUnitD, ArenaManager* pArena, GameManager* ptrDotAArenaGame);
        void playerMenu(GameEntity* pUnitA, GameEntity* pUnitB, GameEntity* pUnitC, GameEntity* pUnitD, ArenaManager* pArena, GameManager* ptrDotAArenaGame);

        void attackScreen(GameEntity* pAttacker, GameEntity* pDefender, ArenaManager* pArena);
        float totalAttackDamageCalc(float netDamage, GameEntity* pDefender);
        float abyssalBash(GameEntity* pAttacker, GameEntity* pDefender, ArenaManager* pArena);
        float criticalStrike(GameEntity* pAttacker, GameEntity* pDefender);
        float lifeSteal(GameEntity* pAttacker, float netDamage);
        float attackBlock(GameEntity* pDefender);

        int totalAGICalc(GameEntity* pUnitA);
        int totalINTCalc(GameEntity* pUnitA);
        int totalSTRCalc(GameEntity* pUnitA);
        int mainATRCalc(GameEntity* pUnitA);
        float totalArmorCalc(GameEntity* pUnitA);
        int totalMaxDMGCalc(GameEntity* pUnitA);
        int totalMinDMGCalc(GameEntity* pUnitA);
        float totalAttackSpeedCalc(GameEntity* pUnitA);
        int totalAttackRangeCalc(GameEntity* pUnitA);
        int totalHPCalc(GameEntity* pUnitA);
        int totalMPCalc(GameEntity* pUnitA);
        float totalHPRCalc(GameEntity* pUnitA);
        float totalMPRCalc(GameEntity* pUnitA);
        float totalMagicResistCalc(GameEntity* pUnitA);
        int totalMoveCalc(GameEntity* pUnitA);
        float totalSpellAMPCalc(GameEntity* pUnitA);
        float totalManaLossReducCalc(GameEntity* pUnitA);
        float totalStatusResistCalc(GameEntity* pUnitA);
        float totalSTRHeroStatusResistCalc(GameEntity* pUnitA);
        int totalAGIHeroMoveCalc(GameEntity* pUnitA);
        float totalINTHeroMagicResist(GameEntity* pUnitA);
        GameEntity* allTotalCalc(GameEntity* pUnitA);

        void healthManaRegen(GameEntity* pRegenUnit);
        bool statusCheckFunction(GameEntity* pAffectedUnit, ArenaManager* pArena);
        int unitDistanceCalc(GameEntity* pHereUnit, GameEntity* pOverThereUnit);
        int randomInt(int numberMin, int numberMax);
        int distanceCalc(int herePOS, int therePOS);
        void dayNightCycle();

        GameEntity* movementScreen(GameEntity* pUnitA, GameEntity* pUnitB);
        void enemyMovementControls(GameEntity* pEnemy, GameEntity* pPlayer);
        void onTheMove(GameEntity* pMovingUnit);
        void moveXUP(GameEntity* pMovingUnit);
        void moveXDOWN(GameEntity* pMovingUnit);
        void moveYUP(GameEntity* pMovingUnit);
        void moveYDOWN(GameEntity* pMovingUnit);
};

#endif
