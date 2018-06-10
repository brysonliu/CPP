//
// Kaylin C. Tate
// DotA Arena
// Game Manager Header File
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include "CombatManager.hpp"
#include "GameItemManager.hpp"
#include "GameArenaManager.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

class GameEntity;

class GameManager
{
    public:	
        GameManager();
        ~GameManager();
        
        GameManager* playGame(GameManager* ptrDotAArenaGame);

        void logoDotA();
        GameManager* mainMenu(GameManager* ptrDotAArenaGame);
        void playerMenuLogo(GameEntity* pUnitA);

        GameEntity characterSelection();
        int tournamentBattle(GameManager* ptrDotAArenaGame);
        void victory(GameEntity* pPlayer);

        GameEntity* itemStore(GameEntity* pPlayer);
        bool playerItemCheck(GameEntity* pPlayer, GameItem* pItem);
        GameEntity* itemPurchase(GameEntity* pPlayer, GameItem* pItem);
        void itemPurchasedPRINT(GameEntity* pPlayer, GameItem* pItem);
        void notEnoughGold();
        void notEnoughInventory();

        GameEntity enemySetUP (int tournamentRound, int monsterClass);
        GameEntity roundOneMonster(int monsterClass);
        GameEntity roundTwoMonster(int monsterClass);
        GameEntity roundThreeMonster(int monsterClass);
        GameEntity roundFourMonster(int monsterClass);
        GameEntity roundFiveMonster(int monsterClass);

        void library();
        void agilityDefinition();
        void intelligenceDefinition();
        void strengthDefinition();
        void physicalDamageDefinition();
        void magicalDamageDefinition();
        void stunDefinition();
        void rootDefinition();
        void silenceDefinition();
        void muteDefinition();
        void disarmDefinition();
        void fearDefinition();
        void etherealDefinition();
        
        void itemLibrary();
        void abyssalDefinition();
        void aetherDefinition();
        void bkbDefinition();
        void blinkDefinition();
        void bloodthornDefinition();
        void desolatorDefinition();
        void dragonlanceDefinition();
        void echoDefinition();
        void healingDefinition();
        void kayaDefinition();
        void morbidDefinition();
        void nullifierDefinition();
        void powerDefinition();
        void atosDefinition();
        void sangeDefinition();
        void yashaDefinition();

        void heroLibrary();
        void svenDefinition();
        void drowDefinition();
        void maidenDefinition();

        bool askBool(int questionType);
        void askBoolQuestionPRINT(int questionType);
        int askInt(int min, int max);
        GameManager* endProgram(GameManager* ptrDotAArenaGame);

        bool gameActive = true;
        float dayNightRotationTime = 10;
        bool playerQuit = false;
        bool playerDead = false;
        bool enemiesDefeated = false;
        
};

#endif
