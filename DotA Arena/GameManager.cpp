//
// Kaylin C. Tate
// DotA Arena
// GameManager File 
//

#include "GameManager.hpp"
#include "CombatManager.hpp"
#include "GameEntityManager.hpp"
#include "GameItemManager.hpp"

using namespace std;

GameManager::GameManager()
{
    CombatManager* ptrDotAArenaCombat = new CombatManager();
}
GameManager::~GameManager()
{
    GameItem* ptrDotAArenaItem;
    GameEntity* ptrDotAArenaUnit;
    CombatManager* ptrDotAArenaCombat; 

    delete ptrDotAArenaItem;
    delete ptrDotAArenaUnit;
    delete ptrDotAArenaCombat;

    cout << "Items, Units and Combat being deleted." << endl;
}

GameManager* GameManager::playGame(GameManager* ptrDotAArenaGame)
{
    logoDotA();
    ptrDotAArenaGame = mainMenu(ptrDotAArenaGame);

    return ptrDotAArenaGame;
}

///////////
// Menus //
///////////

void GameManager::logoDotA()
{
    cout << endl;
    cout << setw(47) << "DOTADOTADOTADOTADOTA" << endl;
    cout << setw(47) << "DOT   TADOTAD    OTA" << endl;
    cout << setw(47) << "DOTA    DOTADO   OTA" << endl;
    cout << setw(47) << "DOTAD    OTADOTA OTA" << endl;
    cout << setw(47) << "DOTADO     ADOTADOTA" << endl;
    cout << setw(47) << "DOTADOTA      TADOTA" << endl;
    cout << setw(47) << "DOT DOTAD       DOTA" << endl;
    cout << setw(47) << "DOT   TADO      DOTA" << endl;
    cout << setw(47) << "DOT    ADOT     DOTA" << endl;
    cout << setw(47) << "DOTADOTADOTADOTADOTA" << endl;
    cout << endl;
    cout << endl;
    cout << "  DDDDDDDDDD             OOOOOOOOO       TTTTTTTTTTTTTTTTTT        AAAA        " <<  endl;
    cout << "  DDDDDDDDDDDD         OOOOOOOOOOOOO     TTTTTTTTTTTTTTTTTT       AAAAAA       " << endl;
    cout << "  DDD       DDD       OOO         OOO           TTTT             AAAAAAAA      " << endl;
    cout << "  DDD        DDD     OOO           OOO          TTTT            AAA    AAA     " << endl;
    cout << "  DDD        DDD     OOO           OOO          TTTT           AAA      AAA    " << endl;
    cout << "  DDD        DDD     OOO           OOO          TTTT          AAAA      AAAA   " << endl;
    cout << "  DDD        DDD     OOO           OOO          TTTT         AAAAAAAAAAAAAAAA  " << endl;
    cout << "  DDD       DDD       OOO         OOO           TTTT         AAAAAAAAAAAAAAAA  " << endl;
    cout << "  DDDDDDDDDDDD         OOOOOOOOOOOOO            TTTT         AAAA        AAAA  " << endl;
    cout << "  DDDDDDDDDD             OOOOOOOOO              TTTT         AAAAA      AAAAA  " << endl;
    cout << endl;
    cout << endl;
    cout << setw(47) << "A Game by Kaylin Tate" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

GameManager* GameManager::mainMenu(GameManager* ptrDotAArenaGame)
{
    int menuAnswer;
    int menuAnswer2;
    
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// 1 = Tournament Battle                                                    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// 2 = Game Library                                                         //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// 3 = End Program                                                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
    
    menuAnswer = askInt(1, 3);

    switch (menuAnswer)
    {
        case 1:
        {
            cout << "You have picked Tournament Mode." << endl;
            menuAnswer2 = askBool(2);

            if (menuAnswer == true)
            {
                tournamentBattle(ptrDotAArenaGame);
            }
        }
        break;
        case 2:
        {
            library();
        }
        break;
        case 3:
        {
            menuAnswer2 = askBool(1);
            if (menuAnswer2 == true)
            {
                endProgram(ptrDotAArenaGame);

            }
        }
        break;
        default:
        {
            cout << endl;
            cout << "That is not a correct response." << endl;
            cout << endl;
        }
        break;
    }

    return ptrDotAArenaGame;
}

void GameManager::playerMenuLogo(GameEntity* pUnitA)
{
    int logoNumber = pUnitA->playerNumber;

    if (logoNumber == 0)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//     PPPPP      LL           AAA       YY    YY     EEEEE     RRRRRR      //" << endl;
        cout << "//     PP  PP     LL          AAAAA       YY  YY      EE        RR   RR     //" << endl;
        cout << "//     PPPP       LL         AA   AA       YYYY       EEEEE     RR  RR      //" << endl;
        cout << "//     PP         LL        AA  A  AA       YY        EE        RRRRR       //" << endl;
        cout << "//     PP         LLLLL     AA     AA       YY        EEEEE     RR   RR     //" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    }
    if (logoNumber == 1)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//                                                                          //" << endl;
        cout << "// PPPPP   LL        AAA    YY    YY  EEEEE  RRRRRR      ##  ##      1111   //" << endl;
        cout << "// PP  PP  LL       AAAAA    YY  YY   EE     RR   RR    ########    11111   //" << endl;
        cout << "// PPPP    LL      AA   AA    YYYY    EEEEE  RR  RR      ##  ##       111   //" << endl;
        cout << "// PP      LL     AA  A  AA    YY     EE     RRRRR      ########      111   //" << endl;
        cout << "// PP      LLLLL  AA     AA    YY     EEEEE  RR   RR     ##  ##     1111111 //" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

        
    }
    if (logoNumber == 2)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//                                                                          //" << endl;
        cout << "// PPPPP   LL        AAA    YY    YY  EEEEE  RRRRRR      ##  ##     222222  //" << endl;
        cout << "// PP  PP  LL       AAAAA    YY  YY   EE     RR   RR    ########   22    22 //" << endl;
        cout << "// PPPP    LL      AA   AA    YYYY    EEEEE  RR  RR      ##  ##        22   //" << endl;
        cout << "// PP      LL     AA  A  AA    YY     EE     RRRRR      ########     22     //" << endl;
        cout << "// PP      LLLLL  AA     AA    YY     EEEEE  RR   RR     ##  ##    22222222 //" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

    }
    if (logoNumber == 3)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//                                                                          //" << endl;
        cout << "// PPPPP   LL        AAA    YY    YY  EEEEE  RRRRRR      ##  ##     333333  //" << endl;
        cout << "// PP  PP  LL       AAAAA    YY  YY   EE     RR   RR    ########   33    33 //" << endl;
        cout << "// PPPP    LL      AA   AA    YYYY    EEEEE  RR  RR      ##  ##        33   //" << endl;
        cout << "// PP      LL     AA  A  AA    YY     EE     RRRRR      ########   33    33 //" << endl;
        cout << "// PP      LLLLL  AA     AA    YY     EEEEE  RR   RR     ##  ##     333333  //" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

    }
    if (logoNumber == 4)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//                                                                          //" << endl;
        cout << "// PPPPP   LL        AAA    YY    YY  EEEEE  RRRRRR      ##  ##   44    44  //" << endl;
        cout << "// PP  PP  LL       AAAAA    YY  YY   EE     RR   RR    ########  44    44  //" << endl;
        cout << "// PPPP    LL      AA   AA    YYYY    EEEEE  RR  RR      ##  ##   444444444 //" << endl;
        cout << "// PP      LL     AA  A  AA    YY     EE     RRRRR      ########        44  //" << endl;
        cout << "// PP      LLLLL  AA     AA    YY     EEEEE  RR   RR     ##  ##         44  //" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    }
    if (logoNumber == 5)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//  PPPPP   LL        AAA    YY    YY  EEEEE  RRRRRR      ##  ##    5555555 //" << endl;
        cout << "//  PP  PP  LL       AAAAA    YY  YY   EE     RR   RR    ########    55     //" << endl;
        cout << "//  PPPP    LL      AA   AA    YYYY    EEEEE  RR  RR      ##  ##     55555  //" << endl;
        cout << "//  PP      LL     AA  A  AA    YY     EE     RRRRR      ########       55  //" << endl;
        cout << "//  PP      LLLLL  AA     AA    YY     EEEEE  RR   RR     ##  ##    555555  //" << endl;
        cout << "//                                                                          //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

        
    }
}

////////////////
// Monster BS //
////////////////

GameEntity GameManager::enemySetUP(int tournamentRound, int monsterClass)
{   

    if (tournamentRound == 0)
    {
        GameEntity monster = roundOneMonster(monsterClass);
        return monster;
    }
    if (tournamentRound == 1)
    {

        GameEntity monster = roundTwoMonster(monsterClass);
        return monster;
    }
    if (tournamentRound == 2)
    {

        GameEntity monster = roundThreeMonster(monsterClass);
        return monster;
    }
    if (tournamentRound == 3)
    {

        GameEntity monster = roundFourMonster(monsterClass);
        return monster;
    }
    if (tournamentRound == 4)
    {
        GameEntity monster = roundFiveMonster(monsterClass);
        return monster;
    }
    
}

GameEntity GameManager::roundOneMonster(int monsterClass)
{
    if (monsterClass == 1)
    {
        GameEntity monster = GameEntity("Harpy Stormcrafter", 6, 3, false, 450, 1.6, 0.25, 310, 2.0, 10, 15, 20, 0.5, 1.5, 2.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800,  
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 2)
    {
        GameEntity monster = GameEntity("Harpy Scout", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 3)
    {
        GameEntity monster = GameEntity("Harpy Scout", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
}
GameEntity GameManager::roundTwoMonster(int monsterClass)
{
    if (monsterClass == 1)
    {
        GameEntity monster = GameEntity("Centaur Conqueror", 6, 3, false, 450, 1.6, 0.25, 310, 2.0, 10, 15, 20, 0.5, 1.5, 2.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800,  
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 2)
    {
        GameEntity monster = GameEntity("Centaur Courser", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 

                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 3)
    {
        GameEntity monster = GameEntity("Centaur Courser", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
}
GameEntity GameManager::roundThreeMonster(int monsterClass)
{

    if (monsterClass == 1)
    {
        GameEntity monster = GameEntity("Satyr Tormenter", 6, 3, false, 450, 1.6, 0.25, 310, 2.0, 10, 15, 20, 0.5, 1.5, 2.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800,  
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 2)
    {
        GameEntity monster = GameEntity("Satyr Mindstealer", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 3)
    {
        GameEntity monster = GameEntity("Satyr Banisher", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
}
GameEntity GameManager::roundFourMonster(int monsterClass)
{

    if (monsterClass == 1)
    {
        GameEntity monster = GameEntity("Ancient Granite Golem", 6, 3, false, 450, 1.6, 0.25, 310, 2.0, 10, 15, 20, 0.5, 1.5, 2.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800,  
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 2)
    {
        GameEntity monster = GameEntity("Ancient Rock Golem", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 3)
    {
        GameEntity monster = GameEntity("Ancient Rock Golem", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
}
GameEntity GameManager::roundFiveMonster(int monsterClass)
{

    if (monsterClass == 1)
    {
        GameEntity monster = GameEntity("Nightstalker", 6, 3, false, 450, 1.6, 0.25, 310, 2.0, 10, 15, 20, 0.5, 1.5, 2.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800,  
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 2)
    {
        GameEntity monster = GameEntity("Necronomicon Warrior", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    }
    if (monsterClass == 3)
    {
        GameEntity monster = GameEntity("Necronomicon Archer", 2, 2, false, 300, 1.6, 0.25, 280, 2.0, 15, 20, 10, 1.5, 2.5, 0.5, 200, 75, 1.5, 0.9, 43, 41, 0.0, 1800, 800, 
                                false, 0, 0);
        cout << monster.entityName << endl;
        return monster;
    };
}


////////////////
// Tournament //
//    Stuff   //
////////////////

GameEntity GameManager::characterSelection()
{

    int characterChoice;
    int characterChoice2;

    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Select a hero!                              //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Strength Heroes                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   1 = Sven, the Rouge Knight                                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Agility Heroes                              //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   2 = Traxex, the Drow Ranger                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Intelligence Heroes                         //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   3 = Rylai, the Crystal Maiden                                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

    for (;;)
    {
        characterChoice = askInt(1, 3);

        switch (characterChoice)
        {
            case 1:
            {
                svenDefinition();

                characterChoice2 = askBool(3);

                if (characterChoice2 == true)
                {
                    GameEntity unitA = GameEntity("Sven", 6, 1, true, 150, 1.8, 0.5, 290, 2.0, 23, 21, 16, 3.0, 2.0, 1.3, 200, 75, 1.5, 0.9, 43, 41, 0.25, 1800, 800, 
                        true, 0, 10000);
                    cout << "You have selected " << unitA.entityName << endl;
                    
                    return unitA;
                    break;
                }

            }
            break;
            case 2:
            {
                drowDefinition();

                characterChoice2 = askBool(3);

                if (characterChoice2 == true)
                {
                    GameEntity unitA = GameEntity("Drow Ranger", 6, 2, false, 625, 1.7, 0.5, 285, -3.0, 17, 26, 15, 1.9, 1.9, 1.3, 200, 75, 1.5, 0.9, 43, 41, 0.25, 1800, 800,
                        true, 0, 10000);
                    cout << "You have selected " << unitA.entityName << endl;
                    
                    return unitA;
                    break;
                }
            }
            break;
            case 3:
            {
                maidenDefinition();

                characterChoice2 = askBool(3);

                if (characterChoice2 == true)
                {
                    GameEntity unitA = GameEntity("Crystal Maiden", 6, 3, false, 600, 1.7, 0.5, 285, -1.0, 16, 16, 16, 2.0, 1.6, 2.9, 200, 75, 1.5, 0.9, 43, 41, 0.25, 1800, 800,
                        true, 0, 10000);
                    cout << "You have selected " << unitA.entityName << endl;

                    return unitA;
                    break;
                }
            }
            break;
            default:
            {
                cout << "That is not a correct response." << endl;
            }
            break;
        }
    }
}

int GameManager::tournamentBattle(GameManager* ptrDotAArenaGame)
{
    bool storeChoice;

    GameEntity player = characterSelection();
    
    GameEntity* pPlayer;

    pPlayer = &player;

    for (int i = 0 ; i != 5; i++)
    {
        CombatManager* ptrDotAArenaCombat;

        storeChoice = askBool(8);
        
        if (storeChoice == true)
        {
            pPlayer = itemStore(pPlayer);
        }

        GameEntity monster1 = enemySetUP(i, 1);
        GameEntity monster2 = enemySetUP(i, 2);
        GameEntity monster3 = enemySetUP(i, 3);

        GameEntity* pEnemy1;
        GameEntity* pEnemy2;
        GameEntity* pEnemy3;

        pEnemy1 = &monster1;
        pEnemy2 = &monster2;
        pEnemy3 = &monster3;

        cout << "Enemies Deafeated: " << ptrDotAArenaGame->enemiesDefeated << endl;
        cout << "Player is Dead: " << ptrDotAArenaGame->playerDead << endl;
        cout << "Player has Quit: " << ptrDotAArenaGame->playerQuit << endl;

        ptrDotAArenaGame = ptrDotAArenaCombat->tournamentCombat(pPlayer, pEnemy1, pEnemy2, pEnemy3, ptrDotAArenaGame);

        cout << "Enemies Deafeated: " << ptrDotAArenaGame->enemiesDefeated << endl;
        cout << "Player is Dead: " << ptrDotAArenaGame->playerDead << endl;
        cout << "Player has Quit: " << ptrDotAArenaGame->playerQuit << endl;

        if (ptrDotAArenaGame->enemiesDefeated == true)
        {
            cout << "Congrats on your victory!" << endl;
            ptrDotAArenaGame->enemiesDefeated = false;
            if (i == 5)
            {
                victory(pPlayer);
                break;
            }
        }
        if (ptrDotAArenaGame->playerDead == true)
        {
            cout << "You died" << endl;
            break;
        }
        if (ptrDotAArenaGame->playerQuit == true)
        {
            cout << "You quit." << endl;
            break;
        }
    }

    return 0;
}

void GameManager::victory(GameEntity* pPlayer)
{
    cout << "Congradulations " << pPlayer->entityName << " you have faced against all the opponents the tournament" << endl;
    cout << "has to offer and came out victorious!" << endl;
    cout << endl;
    cout << "currently there is not reward in place, but the programmer should have something in store, else he " << endl; 
    cout << "will get a D for sure." << endl;
}

////////////
//  Item  //
//  Store //
////////////

GameEntity* GameManager::itemStore(GameEntity* pPlayer)
{

    GameManager* ptrDotAArenaGame;
    int itemChoice;
    int itemChoice2;
    bool itemCheck;
    bool doneShopping;

    GameItem itemA = GameItem("Abyssal Blade", 6850, 10, 0, 0, 250, 7.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemB = GameItem("Aether Lens", 2350, 0, 0, 0, 0, 0, 450, 1.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemC = GameItem("Black King Bar", 3975, 10, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemD = GameItem("Blink Dagger", 2250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemE = GameItem("Bloodthorn", 7195, 0, 0, 25, 0, 0 , 0, 2.25, 30, 0, 60, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemF = GameItem("Desolator", 3500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemG = GameItem("Dragon Lance", 1900, 12, 12, 0, 0, 0, 0, 0, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemH = GameItem("Echo Sabre", 2650, 10, 0, 10, 0, 0, 0, 0.75, 10, 0, 15, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemI = GameItem("Healing Salve", 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemJ = GameItem("Kaya", 1950, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1, 0.1, 0);
    GameItem itemK = GameItem("Morbid Mask", 1100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemL = GameItem("Nullifier", 4700, 0, 0, 0 , 0, 5.0, 0, 0, 0, 0, 65, 5.0, 0, 0, 0, 0, 0, 0);
    GameItem itemM = GameItem("Power Treads", 1350, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 45, 0, 0, 0, 0, 0);
    GameItem itemN = GameItem("Rod of Atos", 3030, 15, 6, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemO = GameItem("Sange", 1950, 16, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0);
    GameItem itemP = GameItem("Yasha", 1950, 0, 16, 0, 0, 00, 0, 0, 10, 0, 0, 0, 0, 0.08, 0, 0, 0, 0);

    GameItem* abyssal;
    GameItem* aether;
    GameItem* bkb;
    GameItem* blink;
    GameItem* bloodThorn;
    GameItem* desolator;
    GameItem* dragonLance;
    GameItem* echoSabre;
    GameItem* healingSalve;
    GameItem* kaya;
    GameItem* morbidMask;
    GameItem* nullifier;
    GameItem* powerTreads;
    GameItem* rodOfAtos;
    GameItem* sange;
    GameItem* yasha;

    abyssal = &itemA;
    aether = &itemB;
    bkb = &itemC;
    blink = &itemD;
    bloodThorn = &itemE;
    desolator = &itemF;
    dragonLance = &itemG;
    echoSabre = &itemH;
    healingSalve = &itemI;
    kaya = &itemJ;
    morbidMask = &itemK;
    nullifier = &itemL;
    powerTreads = &itemM;
    rodOfAtos = &itemN;
    sange = &itemO;
    yasha = &itemP;

    cout << endl;
    cout << "Welcome to the item shop " << pPlayer->entityName << ", what will you be purchasing today?" << endl;
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                    Store                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//     1 = Abyssal Blade:   6,850 gold     2 = Aether Lens:    2,350 gold   //" << endl;
    cout << "//     3 = Black King Bar:  3,975 gold     4 = Blink Dagger:   2,250 gold   //" << endl;
    cout << "//     5 = Bloodthorn:      7,195 gold     6 = Desolator:      3,500 gold   //" << endl;
    cout << "//     7 = Dragon Lance:    1,900 gold     8 = Echo Sabre:     2,650 gold   //" << endl;
    cout << "//     9 = Healing Salve:     110 gold    10 = Kaya:           1,950 gold   //" << endl;
    cout << "//    11 = Morbid Mask:     1,100 gold    12 = Nullifier:      4,700 gold   //" << endl;
    cout << "//    13 = Power Treads:    1,350 gold    14 = Rod of Atos:    3,030 gold   //" << endl;
    cout << "//    15 = Sange:           1,950 gold    16 = Yasha:          1,950 gold   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

    itemChoice = ptrDotAArenaGame->askInt(1, 16);

    switch (itemChoice)
    {
        case 1:
        {
                ptrDotAArenaGame->abyssalDefinition();

                itemCheck = playerItemCheck(pPlayer, abyssal);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {   
                        pPlayer->hasAbyssal = true;
                        pPlayer = itemPurchase(pPlayer, abyssal);
                    }
                }
        }
        break;
        case 2:
        {
                ptrDotAArenaGame->aetherDefinition();
                
                itemCheck = playerItemCheck(pPlayer, aether);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasAetherLens = true;
                        pPlayer = itemPurchase(pPlayer, aether);
                    }
                }

        }
        break;
        case 3:
        {
                ptrDotAArenaGame->bkbDefinition();

                itemCheck = playerItemCheck(pPlayer, bkb);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasBKB = true;
                        pPlayer = itemPurchase(pPlayer, bkb);
                    }
                }
        }
        break;
        case 4:
        {
                ptrDotAArenaGame->blinkDefinition();

                itemCheck = playerItemCheck(pPlayer, blink);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasBlink = true;
                        pPlayer = itemPurchase(pPlayer, blink);
                    }
                }
        }
        break;
        case 5:
        {
                ptrDotAArenaGame->bloodthornDefinition();

                itemCheck = playerItemCheck(pPlayer, bloodThorn);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasBloodThorn = true;
                        pPlayer = itemPurchase(pPlayer, bloodThorn);
                    }
                }
        }
        break;
        case 6:
        {
                ptrDotAArenaGame->desolatorDefinition();
                itemCheck = playerItemCheck(pPlayer, desolator);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasDesolator = true;
                        pPlayer = itemPurchase(pPlayer, desolator);
                    }
                }
        }
        break;
        case 7:
        {
                ptrDotAArenaGame->dragonlanceDefinition();

                itemCheck = playerItemCheck(pPlayer, dragonLance);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasDragonLance = true;
                        pPlayer = itemPurchase(pPlayer, dragonLance);
                    }
                }
        }
        break;
        case 8:
        {
                ptrDotAArenaGame->echoDefinition();

                itemCheck = playerItemCheck(pPlayer, echoSabre);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasEchoSabre = true;
                        pPlayer = itemPurchase(pPlayer, echoSabre);
                    }
                }    
        }
        break;
        case 9:
        {
                ptrDotAArenaGame->healingDefinition();

                itemCheck = playerItemCheck(pPlayer, healingSalve);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasHealingSalve = true;
                        pPlayer = itemPurchase(pPlayer, healingSalve);
                    }
                }
        }
        break;
        case 10:
        {
                ptrDotAArenaGame->kayaDefinition();

                itemCheck = playerItemCheck(pPlayer, kaya);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasKaya = true;
                        pPlayer = itemPurchase(pPlayer, kaya);
                    }
                }
        }
        break;
        case 11:
        {
                ptrDotAArenaGame->morbidDefinition();

                itemCheck = playerItemCheck(pPlayer, morbidMask);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasMorbidMask = true;
                        pPlayer = itemPurchase(pPlayer, morbidMask);
                    }
                }
        }
        break;
        case 12:
        {
                ptrDotAArenaGame->nullifierDefinition();

                itemCheck = playerItemCheck(pPlayer, nullifier);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasNullifier = true;
                        pPlayer = itemPurchase(pPlayer, nullifier);
                    }
                }
        }
        break;
        case 13:
        {
                ptrDotAArenaGame->powerDefinition();

                itemCheck = playerItemCheck(pPlayer, powerTreads);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasPowerTreads = true;
                        pPlayer = itemPurchase(pPlayer, powerTreads);
                    }
                }
        }
        break;        
        case 14:
        {
                ptrDotAArenaGame->atosDefinition();

                itemCheck = playerItemCheck(pPlayer, rodOfAtos);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasRodofAtos = true;
                        pPlayer = itemPurchase(pPlayer, rodOfAtos);
                    }
                }
        }
        break;
        case 15:
        {
                ptrDotAArenaGame->sangeDefinition();
                
                itemCheck = playerItemCheck(pPlayer, sange);

                if (itemCheck == true)
                {
                    itemChoice2 = ptrDotAArenaGame->askBool(5);

                    if (itemChoice2 == true)
                    {
                        pPlayer->hasSange = true;
                        pPlayer = itemPurchase(pPlayer, sange);
                    }
                }
        }
        break;
        case 16:
        {
                ptrDotAArenaGame->yashaDefinition();

                itemCheck = playerItemCheck(pPlayer, yasha);

                    if (itemCheck == true)
                    {
                        itemChoice2 = ptrDotAArenaGame->askBool(5);

                        if (itemChoice2 == true)
                        {
                            pPlayer->hasYasha = true;
                            pPlayer = itemPurchase(pPlayer, yasha);
                        }
                    }
        }
        break;
        default:
        break;
    }

    doneShopping = ptrDotAArenaGame->askBool(6);
        
    if (doneShopping == false)
    {
        cout << "It's just going to false." << endl;
        itemStore(pPlayer);
    }

    return pPlayer;
}

bool GameManager::playerItemCheck(GameEntity* pPlayer, GameItem* pItem)
{
    GameManager* ptrDotAArenaGame;

    if (pPlayer->inventory > pPlayer->maxInventory)
    {
        ptrDotAArenaGame->notEnoughInventory();
        return false;
    }
    else if (pPlayer->goldSupply < pItem->itemCost)
    {
        ptrDotAArenaGame->notEnoughGold();
        return false;
    }
    else
    {
        return true;
    }
}

GameEntity* GameManager::itemPurchase(GameEntity* pPlayer, GameItem* pItem)
{

    //Applies item buffs to player.
    pPlayer->totalItemSTR += pItem-> itemSTR;
    pPlayer->totalItemAGI += pItem-> itemAGI;
    pPlayer->totalItemINT += pItem-> itemINT;
    pPlayer->totalItemHP += pItem-> itemHP;
    pPlayer->totalItemHPR += pItem-> itemHPR;
    pPlayer->totalItemMP += pItem-> itemMP;
    pPlayer->totalItemMPR += pItem-> itemMPR;
    pPlayer->totalItemAttackSpeed += pItem-> itemAttackSpeed;
    pPlayer->totalItemAttackRange += pItem-> itemAttackRange;
    pPlayer->totalItemDMG += pItem-> itemDMG;
    pPlayer->totalItemArmor += pItem-> itemArmor;
    pPlayer->totalItemMove += pItem-> itemMove;
    pPlayer->totalItemMovePercent += pItem-> itemMovePercent;
    pPlayer->totalItemMagicResist += pItem-> itemMagicResist;
    pPlayer->totalItemSpellAMP += pItem-> itemSpellAMP;
    pPlayer->totalItemManaLossReduc += pItem-> itemManaLossReduc;
    pPlayer->totalItemStatusResist += pItem-> itemStatusResist;

    //Inventory and gold cost
    pPlayer->goldSupply -= pItem->itemCost;
    pPlayer->inventory += 1;

    itemPurchasedPRINT(pPlayer, pItem);

    return pPlayer;
}

void GameManager::itemPurchasedPRINT(GameEntity* pPlayer, GameItem* pItem)
{
    cout << "You have purchased " << pItem->itemName << endl;
    cout << "You have " << pPlayer->goldSupply << " left." << endl;
    cout << "You have " << pPlayer->inventory << " out of a max of six items." << endl;
}

void GameManager::notEnoughGold()
{
    cout << endl;
    cout << "You don't have enough gold to purchase this item." << endl;
    cout << endl;
}

void GameManager::notEnoughInventory()
{
    cout << endl;
    cout << "You already have the max amount of items." << endl;
    cout << endl;
}


/////////////
// Library //
/////////////

void GameManager::library()
{
    int menuAnswer;
    int menuAnswer2;

    cout << endl;
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// You have chosen the game library here you can learn what certain         //" << endl;
    cout << "// mechanics do, or learn more about heroes in the game.                    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// Please choose any of the following.                                      //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//        1 = Agility                    2 = Intelligence                   //" << endl;
    cout << "//        3 = Strength                   4 = Attack Damage                  //" << endl;
    cout << "//        5 = Magical Damage             6 = Stun                           //" << endl;
    cout << "//        7 = Root                       8 = Silence                        //" << endl;
    cout << "//        9 = Mute                      10 = Disarm                         //" << endl;
    cout << "//       11 = Fear                      12 = Ethereal                       //" << endl;
    cout << "//       13 = Items                     14 = Heroes Library                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    
    cout << endl;

    menuAnswer = askInt(1, 14);
    
    switch (menuAnswer)
    {
        case 1:
        {
            agilityDefinition();
        }
        break;
        case 2:
        {
            intelligenceDefinition();
        }
        break;
        case 3:
        {
            strengthDefinition();
        }
        break;
        case 4:
        {
            physicalDamageDefinition();
        }
        break;
        case 5:
        {
            magicalDamageDefinition();
        }
        break;
        case 6:
        {
            stunDefinition();
        }
        break;
        case 7:
        {
            rootDefinition();
        }
        break;
        case 8:
        {
            silenceDefinition();
        }
        break;
        case 9:
        {
            muteDefinition();
        }
        case 10:
        {
            disarmDefinition();
        }
        case 11:
        {
            fearDefinition();
        }
        case 12:
        {
            etherealDefinition();
        }
        case 13:
        {
            itemLibrary();
        }
        break;
        case 14:
        {
            heroLibrary();
        }
        break;

        default:
        {
            cout << endl;
            cout <<"That is not a correct response." << endl;
            cout << endl;
        }
        break;
    }
    
    menuAnswer2 = askBool(4);

    if (menuAnswer2 == true)
    {
        cout << "Exiting the library." << endl;
    }
    else
    {
        library();
    }
}
void GameManager::agilityDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                Agility                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//        is the attribute that grants armor and attack speed to every      //" << endl;
    cout << "//  hero, and additionally movement speed and attack to agility heroes.     //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//  0.17 Armor per Agility Point.                                           //" << endl;
    cout << "//  1 Attack Speed per Agility Point.                                       //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                            Agility Heroes                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//  1 Attack Damage                                                         //" << endl;
    cout << "//  0.06% Bonus Movement Speed                                              //" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::intelligenceDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Intelligence                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//              is the attribute that grants mana, mana regeneration and    //" << endl;
    cout << "//   spell damage aplification to all heroes as well as bonus magic         //" << endl;
    cout << "//   resistance and attack damage to Intelligence Heroes.                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   12 Mana Points per Intelligence point.                                 //" << endl;
    cout << "//   2% Mana Regeneration per Intelligence point.                           //" << endl;
    cout << "//   0.07% Spell Damage Amplification per Intelligence point.               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                          Intelligence Heroes                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   1 Attack Damage per Intelligence point.                                //" << endl;
    cout << "//   0.15% Magic Resistance per Intelligence point.                         //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::strengthDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Strength                                    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//              is the attribute that grants health and health              //" << endl;
    cout << "//   regeneration as well as status resistance and attack damage to         //" << endl;
    cout << "//   strength heroes.                                                       //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   20 Health Points per Strength point.                                   //" << endl;
    cout << "//   0.71% Health Regeneration per Strength point.                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                          Strength Heroes                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   1 Attack Damage per Strength point.                                    //" << endl;
    cout << "//   0.15% Status Resistance per Strength point.                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::physicalDamageDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Attack Damage                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//              is the type of damage caused when a character attacks      //" << endl;
    cout << "//   another. This value can be increased by items, spells and increasing  //" << endl;
    cout << "//   their main attribute.                                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::magicalDamageDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Magical Damage                              //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//              is the type of damage that comes from spells cast or items  //" << endl;
    cout << "//   used. This type of damage can be increased by either items, spells or  //" << endl;
    cout << "//   increasing the hero's intelligence attribute.                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::stunDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                    Stun                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//              is a type of status in which the effected unit cannot       //" << endl;
    cout << "//   perform any actions until the duration of the stun has finished.       //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::rootDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Root                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                       is a status that prevents a target from moving and //" << endl;
    cout << "//    will stop them if they are in the process of moving until they go     //" << endl;
    cout << "//    spell immune or the duration ends.                                    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::silenceDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                   Silence                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                       is a status that prevents the target from casting  //" << endl;
    cout << "//   spells until they go spell immune or the duration ends.                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::muteDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                    Mute                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                       is a status that prevents a target from using      //" << endl;
    cout << "//   their items until they go spell immune of the duration ends.           //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::disarmDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                    Disarm                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                       is a status that prevents the target from          //" << endl;
    cout << "//   attacking until they go spell immune or the duration ends.             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::fearDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                    Fear                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                       is a status that causes the target to run back to  //" << endl; 
    cout << "//    their starting position for the duration of the effect they cannot    //" << endl;
    cout << "//    perform any action other than forced movement.                        //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::etherealDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Ethereal                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                       is a status that causes the target to become       //" << endl;
    cout << "//   immune to attacks as well as being unable to attack. They will also    //" << endl;
    cout << "//   take bonus damage from spells.                                         //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::itemLibrary()
{
    int menuAnswer;
    int menuAnswer2;

    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   Welcome to the item library, what item would you like to learn about?  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//   1 = Abyssal Blade                              2 = Aether Lens         //" << endl;
    cout << "//   3 = Black King Bar                             4 = Blink Dagger        //" << endl;
    cout << "//   5 = Bloodthorn                                 6 = Desolator           //" << endl;
    cout << "//   7 = Dragon Lance                               8 = Echo Sabre          //" << endl;
    cout << "//   9 = Healing Salve                             10 = Kaya                //" << endl;
    cout << "//  11 = Morbid Mask                               12 = Nullfier            //" << endl;
    cout << "//  13 = Power Treads                              14 = Rod of Atos         //" << endl;
    cout << "//  15 = Sange                                     16 = Yasha               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

    menuAnswer = askInt(1, 16);

    switch (menuAnswer)
    {
        case 1:
        {
            abyssalDefinition();
        }
        break;
        case 2:
        {
            aetherDefinition();
        }
        break;
        case 3:
        {
            bkbDefinition();
        }
        break;
        case 4:
        {
            blinkDefinition();
        }
        break;
        case 5:
        {
            bloodthornDefinition();
        }
        break;
        case 6:
        {
            desolatorDefinition();
        }
        break;
        case 7:
        {
            dragonlanceDefinition();
        }
        break;
        case 8:
        {
            echoDefinition();
        }
        break;
        case 9:
        {
            healingDefinition();
        }
        break;
        case 10:
        {
            kayaDefinition();
        }
        break;
        case 11:
        {
            morbidDefinition();
        }
        break;
        case 12:
        {
            nullifierDefinition();
        }
        break;
        case 13:
        {
            powerDefinition();
        }
        break;
        case 14:
        {
            atosDefinition();
        }
        break;
        case 15:
        {
            sangeDefinition();
        }
        break;
        case 16:
        {
            yashaDefinition();
        }
        break;
        default:
        {
            cout << "That is not the correct response" << endl;
        }
        break;
    }


    menuAnswer2 = askBool(4);

    if (menuAnswer2 == true)
    {
        cout << "Exiting the library" << endl;
    }
    else
    {
        itemLibrary();
    }
}
void GameManager::abyssalDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Abyssal Blade                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Strength:             10                                            //" << endl;
    cout << "//      Health:               250                                           //" << endl;
    cout << "//      Health Regeneration:  7                                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Overwhelm:            stuns target enemy for 2 seconds.             //" << endl;
    cout << "//      Bash:                 gives a chance to stun an enemy on attack     //" << endl;
    cout << "//                            for 1.4 seconds.                              //" << endl;
    cout << "//      Damage Block:         gives a 50% chance to block damage when       //" << endl;
    cout << "//                            being attacked.                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::aetherDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Ather Lens                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Mana Points:          450                                           //" << endl;
    cout << "//      Mana Regeneration:    1.25                                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Aethereal Focus:      increases targeted spell and item cast        //" << endl;
    cout << "//                            range by 250.                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::bkbDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                             Black King Bar                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Strength:             10                                            //" << endl;
    cout << "//      Attack Damage:        24                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Avatar:               You become completely immune to magic spells  //" << endl;
    cout << "//                            as well as items in both damage and effects.  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::blinkDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                               Blink Dagger                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Blink:                Allows the caster to instantly teleport up    //" << endl;
    cout << "//                            to 1200 units and to dodge certain spells.    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::bloodthornDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                Bloodthorn                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Speed:         30                                            //" << endl;
    cout << "//      Attack Damage:        60                                            //" << endl;
    cout << "//      Intelligence:         25                                            //" << endl;
    cout << "//      Mana Regeneration:    2.25                                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl; 
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Soul Rend:            Silences target, disables evasion and allows  //" << endl;
    cout << "//                            every attack to be a critical hit for 5       //" << endl;
    cout << "//                            seconds.                                      //" << endl;
    cout << "//      Critical Strike:      gives a 20% chance to land a critical hit on  //" << endl;
    cout << "//                            on attack dealing for 1.75x damage.           //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::desolatorDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                Desolator                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Damage:        50                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Corruption:           Lowers enemy armor when you attack them by    //" << endl;
    cout << "//                            6 for 15 seconds which resets with every      //" << endl;
    cout << "//                            successful attack.                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::dragonlanceDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Dragon Lance                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Agility:              12                                            //" << endl;
    cout << "//      Strength:             12                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Dragon's Reach:       Increases ranged heroes attack range by       //" << endl;
    cout << "//                            140 units.                                    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::echoDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                Echo Sabre                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Damage:        15                                            //" << endl;
    cout << "//      Attack Speed:         10                                            //" << endl;
    cout << "//      Strength:             10                                            //" << endl;
    cout << "//      Intelligence:         10                                            //" << endl;
    cout << "//      Mana Regeneration:    0.75                                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Echo Strike:          Allows melee heroes to strike twice in quick  //" << endl;
    cout << "//                            succession.                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::healingDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Healing Salve                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Salve:                Grants a bonus 50 health regeneration to the  //" << endl;
    cout << "//                            selected target.                              //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::kayaDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                   Kaya                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Intelligence:         16                                            //" << endl;
    cout << "//      Spell Damage Amp:     10%                                           //" << endl;
    cout << "//      Mana Loss/ Reduction: 10%                                           //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::morbidDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                               Morbid Mask                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Damage:        10                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Lifesteal:            Heals the attacker for 15% of their attack    //" << endl;
    cout << "//                            dealt.                                        //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::nullifierDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                Nullifier                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Damage:        65                                            //" << endl;
    cout << "//      Armor:                5                                             //" << endl;
    cout << "//      Health Regeneration:  5                                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Nullify               Mutes the target for 5 seconds, not allowing  //" << endl;
    cout << "//                            them to use items for the duration.           //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::powerDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                              Power Treads                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Speed:         25                                            //" << endl;
    cout << "//      Movement Speed:       45                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Switch Attribute:     Switches between +10 Strength, +10 Agility    //" << endl;
    cout << "//                            or +10 Intelligence.                          //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::atosDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                               Rod of Atos                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Agility:              6                                             //" << endl;
    cout << "//      Intelligence:        20                                             //" << endl;
    cout << "//      Strength:            15                                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Cripple:              Roots the target for 2 seconds.               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::sangeDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Sange                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Attack Damage:        10                                            //" << endl;
    cout << "//      Strength:             16                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Spells                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Lesser Maim:          Gives a 30% chance to land a slow on attack   //" << endl;
    cout << "//                            to their movement speed.                      //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::yashaDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Yasha                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                  Stats                                   //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Agility:              16                                            //" << endl;
    cout << "//      Attack Speed:         10                                            //" << endl;
    cout << "//      Movement Speed:       8%                                            //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::heroLibrary()
{
    int menuAnswer;
    int menuAnswer2;

    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// Welcome to the hero library, what hero would you like to learn about?    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// Strength                                                                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// 1) Sven, the Rouge Knight                                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// Agility                                                                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// 2) Traxex, the Drow Ranger                                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// Intelligence                                                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "// 3) Rylai, The Crystal Maiden                                             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;

    menuAnswer = askInt(1, 3);

    switch (menuAnswer)
    {
        case 1:
        {
            svenDefinition();
        }
        break;
        case 2:
        {
            drowDefinition();
        }
        break;
        case 3:
        {
            maidenDefinition();
        }
        break;
        default:
        {
        	cout << "This is not a proper response please try again." << endl;
		}
        break;

    }
    
    menuAnswer2 = askBool(4);

    if (menuAnswer2 == true)
    {
        cout << "Exiting the Library." << endl;
    }
    else
    {
        heroLibrary();
    }
}
void GameManager::svenDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                           Sven, The Rouge Knight                         //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Stats                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Strength:             23          Strength per Level:        3.0    //" << endl;
    cout << "//      Agility:              21          Agility per Level:         2.0    //" << endl;
    cout << "//      Intelligence:         16          Intelligence per Level:    1.3    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Health Regeneration:  1.5         Mana Regeneration:         0.9    //" << endl;
    cout << "//      Movement Speed:       290         Attack Range:              150    //" << endl;
    cout << "//      Base Attack Time:     1.8         Magic Resistance:          25%    //" << endl;
    cout << "//      Day Vision:          1800         Night Vision:              800    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Spells                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Storm Hammer:         Sven stuns and damages a targeted enemy as    //" << endl;
    cout << "//                            well as any enemy within a small radius of    //" << endl;
    cout << "//                            the target for 2 seconds and 250 damage.      //" << endl;        
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Great Cleave          Sven will damage all enemies in a small       //" << endl;
    cout << "//                            around the target he is attacking for 54%     //" << endl;
    cout << "//                            of the damage inflicted on the target.        //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      War Cry               Sven will gain bonus 15 armor and 12%         //" << endl;
    cout << "//                            movement speed for 8 seconds.                 //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      God's Strength        Sven will gain 120% damage buff to his        //" << endl;
    cout << "//                            attacks as well as 20 strength for 25         //" << endl;
    cout << "//                            seconds.                                      //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::drowDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                             Traxex, The Drow Ranger                      //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Stats                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Strength:             17          Strength per Level:        1.9    //" << endl;
    cout << "//      Agility:              26          Agility per Level:         1.9    //" << endl;
    cout << "//      Intelligence:         15          Intelligence per Level:    1.4    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Health Regeneration:  1.5         Mana Regeneration:         0.9    //" << endl;
    cout << "//      Movement Speed:       285         Attack Range:              625    //" << endl;
    cout << "//      Base Attack Time:     1.8         Magic Resistance:          25%    //" << endl;
    cout << "//      Day Vision:          1800         Night Vision:              800    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Spells                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Frost Arrow           Adds a slowing effect to Drow's attacks       //" << endl;
    cout << "//                            slowing enemies up to 48% for 1.5 seconds.    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Gust                  Pushes enemies away from drow and will        //" << endl;
    cout << "//                            silence them for up to 5 seconds.             //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Precision Aura        Adds bonus damage to Drow's attacks based on  //" << endl;
    cout << "//                            26% of Drow's total agility.                  //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Maksmanship           As long as enemies are at least 400 units     //" << endl;
    cout << "//                            away from Drow she will gain a bonus 60       //" << endl;
    cout << "//                            Agility.                                      //" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}
void GameManager::maidenDefinition()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                             Rylai, Crystal Maiden                        //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Stats                                //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Strength:             16          Strength per Level:        2.0    //" << endl;
    cout << "//      Agility:              16          Agility per Level:         1.6    //" << endl;
    cout << "//      Intelligence:         16          Intelligence per Level:    2.9    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Health Regeneration:  1.5         Mana Regeneration:         0.9    //" << endl;
    cout << "//      Movement Speed:       275         Attack Range:              600    //" << endl;
    cout << "//      Base Attack Time:     1.7         Magic Resistance:          25%    //" << endl;
    cout << "//      Day Vision:          1800         Night Vision:              800    //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//                                     Spells                               //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Crystal Nova          Crystal Maiden slows and damages enemies      //" << endl;
    cout << "//                            within a targeted radius for 40% and 200      //" << endl;
    cout << "//                            damage.                                       //" << endl;       
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Frostbite             Cyrstal Maiden can target a single enemy and  //" << endl;
    cout << "//                            root them in place and damage them for every  //" << endl;
    cout << "//                            second they are rooted.                       //" << endl;
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Arcane Aura           Gives Crystal Maiden an additional 3 mana     //" << endl;
    cout << "//                            regeneration.                                 //" << endl;      
    cout << "//" << setw(76) << "//" << endl;
    cout << "//      Freezing Field        Crystal Maiden channels a snow storm around   //" << endl;
    cout << "//                            her slowing and damaging enemies caught in    //" << endl;
    cout << "//                            it for 30% and 170 damage per second.         //" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
}



////////////////
// Ask Player //
//  Question  //
////////////////

bool GameManager::askBool(int questionType)
{
    char answer;

    askBoolQuestionPRINT(questionType);

    while (! (answer == 'Y' || answer == 'N' || answer == 'y' || answer == 'n'))
    {
        cout << endl;
        cout << "Please enter Y or N" << endl;
        cin >> answer;

        if (answer == 'Y' || answer == 'y')
        {
            return true;
        }
        
        if (answer == 'N' || answer == 'n')
        {
            return false;
        }

        cout << endl;
        cout << "That is not the proper response, please try again." << endl;
        cout << endl;
    };

    return false;
}

void GameManager::askBoolQuestionPRINT(int questionType)
{

    switch(questionType)
    {
        case 1:
        {
            cout << endl;
            cout << "Do you wish to end the program?" << endl;
        }
        break;
        case 2:
        {
            cout << endl;
            cout << "Is this the mode you want?" << endl;

        }
        break;
        case 3:
        {
            cout << endl;
            cout << "Is this the character you want?" << endl;
        }
        break;
        case 4:
        {
            cout << endl;
            cout << "Are you done with the library?" << endl;
            cout << endl;
        }
        break;
        case 5:
        {
            cout << endl;
            cout << "Is this the item you want?" << endl;
            cout << endl;
        }
        break;
        case 6:
        {
            cout << endl;
            cout << "Are you done shopping?" << endl;
            cout << endl;
        }
        break;
        case 7:
        {
            cout << endl;
            cout << "Do you want to quit the current game?" << endl;
        }
        break;
        case 8:
        {
            cout << endl;
            cout << "Do you want to go to the item shop?" << endl;
            cout << endl;
        }
        break;
		case 9:
		{
			cout << endl;
			cout << "Stop moving to attack?" << endl;
			cout << endl;
		}
		break;
        default:
        {
           cout << endl;
           cout << "Are you sure?" << endl; 
        }
        break;
    }
}

int GameManager::askInt(int min, int max)
{
    int value = 0;
    while(true)
    {
        cout << "Enter a number from " << min << " to " << max << ": " ;
        cin >> value;
        if (value >= min && value <= max)
        {
            return value;
        }
        cout << "Invalid value. Try again. " << endl;
    };
}

GameManager* GameManager::endProgram(GameManager* ptrDotAArenaGame)
{
    cout << endl;
    cout << "Program has been terminated, have a good day." << endl;
    cout << endl;

    ptrDotAArenaGame->gameActive = false;

    return ptrDotAArenaGame;
}
