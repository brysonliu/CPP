//
// Kaylin C. Tate
// DotA Arena
// Combat Manager File
//

#include "GameManager.hpp"
#include "CombatManager.hpp"
#include "GameItemManager.hpp"
#include "GameEntityManager.hpp"

CombatManager::CombatManager()
{

}

CombatManager::~CombatManager()
{
    
}


///////////////
//   Main    //
// Functions //
///////////////

GameManager* CombatManager::tournamentCombat(GameEntity* pPlayer, GameEntity* pEnemy1, GameEntity* pEnemy2, GameEntity* pEnemy3, GameManager* ptrDotAArenaGame)
{
    CombatManager* ptrDotAArenaCombat;

    ArenaManager Arena = ArenaManager(0.0, true, 10);

    ArenaManager* pArena = &Arena;

    pPlayer = ptrDotAArenaCombat->allTotalCalc(pPlayer);
    pEnemy1 = ptrDotAArenaCombat->allTotalCalc(pEnemy1);
    pEnemy2 = ptrDotAArenaCombat->allTotalCalc(pEnemy2);
    pEnemy3 = ptrDotAArenaCombat->allTotalCalc(pEnemy3);

    pPlayer->playerNumber = 0;
    
    pPlayer->XPosition = 1000;
    pPlayer->YPosition = 1000;
    pEnemy1->XPosition = 1500;
    pEnemy1->YPosition = 1250;
    pEnemy2->XPosition = 1500;
    pEnemy2->YPosition = 1500;
    pEnemy3->XPosition = 1000;
    pEnemy3->YPosition = 1250;

    for ( ; ; )
    {

        cout << "Match Time: " << pArena->matchTime << endl;

        if (pArena->dayNightRotationTime <= pArena->matchTime)
        {
            pArena->dayNightCycle(pArena);
        }
        
        if (pPlayer->isAlive == true)
        {
            ptrDotAArenaCombat->actionPhase(pPlayer, pEnemy1, pEnemy2, pEnemy3, pArena, ptrDotAArenaGame);
        }
        if (pEnemy1->isAlive == true)
        {
            ptrDotAArenaCombat->actionPhase(pEnemy1, pPlayer, pEnemy2, pEnemy3, pArena, ptrDotAArenaGame);
        }
        if (pEnemy1->isAlive == true)
        {
            ptrDotAArenaCombat->actionPhase(pEnemy2, pPlayer, pEnemy1, pEnemy3, pArena, ptrDotAArenaGame);
        }
        if (pEnemy1->isAlive == true)
        {
            ptrDotAArenaCombat->actionPhase(pEnemy3, pPlayer, pEnemy1, pEnemy2, pArena, ptrDotAArenaGame);
        }
        
        if (pPlayer->currentHP < 0)
        {
            ptrDotAArenaGame->playerDead = true;
            break;
        }
        if (pEnemy1->currentHP <= 0 && pEnemy2->currentHP <= 0 && pEnemy3->currentHP <= 0)
        {
            ptrDotAArenaGame->enemiesDefeated = true;
            break;
        }
        if (ptrDotAArenaGame->playerQuit == true)
        {
            break;
        }
        pArena->matchTime += 0.10;
    }

return ptrDotAArenaGame;

}

void CombatManager::actionPhase(GameEntity* pUnitA, GameEntity* pUnitB, GameEntity* pUnitC, GameEntity* pUnitD, ArenaManager* pArena, GameManager* ptrDotAArenaGame)
{

    if (statusCheckFunction(pUnitA, pArena) == false)
    {
        playerMenu(pUnitA, pUnitB, pUnitC, pUnitD, pArena, ptrDotAArenaGame);
    }
}


void CombatManager::playerMenu(GameEntity* pUnitA, GameEntity* pUnitB, GameEntity* pUnitC, GameEntity* pUnitD, ArenaManager* pArena, GameManager* ptrDotAArenaGame)
{
    
    int menuChoice;
    char target;
    bool quitGame;
    int enemyDistance;

    if (pUnitA->isPlayer == true)
    {
        ptrDotAArenaGame->playerMenuLogo(pUnitA);

        int visionRange;

        if (pArena->dayTime == true)
        {
            visionRange = pUnitA->dayVision;
        }
        else
        {
            visionRange = pUnitA->nightVision;
        }

        if (unitDistanceCalc(pUnitA, pUnitB) <= visionRange && pUnitB->isAlive == true)
        {
            cout << "  1) " << pUnitB->entityName << setw(32) << " X: " << pUnitB->XPosition << " Y: " << pUnitB->YPosition << endl;
        }
        if (unitDistanceCalc(pUnitA, pUnitC) <= visionRange && pUnitC->isAlive == true)
        {
            cout << "  2) " << pUnitC->entityName << setw(32) << " X: " << pUnitC->XPosition << " Y: " << pUnitC->YPosition << endl;
        }
        if (unitDistanceCalc(pUnitA, pUnitD) <= visionRange && pUnitD->isAlive == true)
        {
            cout << "  3) " << pUnitD->entityName << setw(32) << " X: " << pUnitD->XPosition << " Y: " << pUnitD->YPosition << endl;
        }
        cout << "  Player: " << pUnitA->entityName << setw(32) << " X: " << pUnitA->XPosition << " Y: " << pUnitA->YPosition << endl;
        cout << "  Health: " << pUnitA->currentHP << " / " << pUnitA->totalHP << endl;
        cout << "  Mana:   " << pUnitA->currentMP << " / " << pUnitA->totalMP << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//" << setw(76) << "//" << endl;
        cout << "//     1)  Move                                                             //" << endl;
        cout << "//     2)  Attack                                                           //" << endl;
        cout << "//     3)  Use Spells  (WIP)                                                //" << endl;
        cout << "//     4)  Use Items   (WIP)                                                //" << endl;
        cout << "//     5)  Quit                                                             //" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    
        menuChoice = ptrDotAArenaGame->askInt(1, 5);

        switch(menuChoice)
        {
            case 1:
            {
                pUnitA = movementScreen(pUnitA, pUnitB);
            }
            break;
            case 2:
            {   
                cout << endl;
                cout << "Choose a target to attack remember that they have to be within your attack range." << endl;
                cout << endl;
                cout << "Total Attack Range: " << pUnitA->totalAttackRange << endl;
                
                target = ptrDotAArenaGame->askInt(1, 3);

                switch(target)
                {
                    case 1:
                    {
                        if (unitDistanceCalc(pUnitA, pUnitB) <= pUnitA->totalAttackRange && pUnitB->isAlive == true)
                        {
                            pUnitA->isAttacking = true;
                            attackScreen(pUnitA, pUnitB, pArena);
                        }
                        else
                        {
                            cout << "You are not close enough." << endl;
                        }
                    }
                    break;
                    case 2:
                    {
                        if (unitDistanceCalc(pUnitA, pUnitC) <= pUnitA->totalAttackRange && pUnitC->isAlive == true)
                        {
                            pUnitA->isAttacking = true;
                            attackScreen(pUnitA, pUnitC, pArena);
                        }
                        else
                        {
                            cout << "You are not close enough." << endl;
                        }
                    }
                    break;
                    case 3:
                    {
                        if (unitDistanceCalc(pUnitA, pUnitD) <= pUnitA->totalAttackRange && pUnitD->isAlive == true)
                        {
                            pUnitA->isAttacking = true;
                            attackScreen(pUnitA, pUnitD, pArena);
                        }
                        else
                        {
                            cout << "You are not close enough." << endl;
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
            break;
            case 3:
            {
                cout << "This will be the spell menu choice later on." << endl;
            }
            break;
            case 4:
            {
                cout << "This will be the item menu choice later on." << endl;
            }
            break;
            case 5:
            {
                quitGame = ptrDotAArenaGame->askBool(7);

                if (quitGame == true)
                {
                    ptrDotAArenaGame->playerQuit = true;
                }
            }
            break;
            default:
            {
                cout << "That is not a valid choice." << endl;
            }
            break;
        }
    }
    else
    {
        enemyDistance = unitDistanceCalc(pUnitA, pUnitB);

        cout << "Enemy distance is " << enemyDistance << endl;

        if (enemyDistance <= pUnitA->totalAttackRange)
        {
            pUnitA->isAttacking = true;
            attackScreen(pUnitA, pUnitB, pArena);
        }
        else
        {
            cout << "Running stuff runs." << endl;
            pUnitA = movementScreen(pUnitA, pUnitB);
        }
    }
}

//////////////////
//   Attacking  //
//     Stuff    //
//////////////////

void CombatManager::attackScreen(GameEntity* pAttacker, GameEntity* pDefender, ArenaManager* pArena)
{
    float netDamage = 0;
    float totalDamage;

    netDamage += randomInt(pAttacker->totalMaxDMG, pAttacker->totalMinDMG);

    if (pAttacker->hasAbyssal == true)
    {
        netDamage += abyssalBash(pAttacker, pDefender, pArena);
	}
    if (pAttacker->hasDesolator == true)
    {
        pDefender->totalArmor -= 6;
	}
    if (pAttacker->hasMorbidMask == true)
    {
        pAttacker->currentHP += lifeSteal(pAttacker, netDamage);
    }
    if (pAttacker->hasBloodThorn == true)
    {
        netDamage *= criticalStrike(pAttacker, pDefender);
    }

    totalDamage = totalAttackDamageCalc(netDamage, pDefender);
    
    if (pDefender->hasAbyssal == true)
    {
        totalDamage -= attackBlock(pDefender);
    }

	pDefender->currentHP -= totalDamage;

    if (pAttacker->hasDesolator == true)
    {
        pDefender->totalArmor += 6;
    }

    cout << pAttacker->entityName << " hits " << pDefender->entityName << " for " << totalDamage << " damage." << endl;
}
float CombatManager::totalAttackDamageCalc(float netDamage, GameEntity* pDefender)
{
    float totalDamage;

    totalDamage = netDamage * (1 - (0.05 * pDefender->totalArmor));

    if (totalDamage < 0)
    {
        totalDamage *= -1;
    }

    return totalDamage;
}

float CombatManager::abyssalBash(GameEntity* pAttacker, GameEntity* pDefender, ArenaManager* pArena)
{
    GameManager* ptrDotAArenaGame;

    int chance;
    float magicDamage;
    float bonusDamage;
	
	if(pAttacker->meleeAttack == true)
    {
        chance = randomInt(1, 4);

        if (chance == 1)
        {
            cout << pAttacker->entityName << " bashes " << pDefender->entityName << endl;
            pDefender->isStunned = true;
            pDefender->stunDuration = (1.4 + pArena->matchTime);
            
            magicDamage = 100;
                    
            bonusDamage = magicDamage * (1 - pDefender->totalMagicResist);
        }
    }
    else
    {
        chance = randomInt(1, 10);
        
        if (chance == 1)
        {
            cout << pAttacker->entityName << " bashes " << pDefender->entityName << endl;
            pDefender->isStunned = true;
            pDefender->stunDuration = (1.4 + pArena->matchTime);

            magicDamage = 100;
                    
            bonusDamage = magicDamage * (1 - pDefender->totalMagicResist);
        }
    }
}

float CombatManager::criticalStrike(GameEntity* pAttacker, GameEntity* pDefender)
{
    int chance;

    const float CRIT = 1.75;

    chance = randomInt(1, 5);

    if (chance == 1)
    {
        cout << pAttacker->entityName << " lands a Critcal Strike on " << endl;

        return CRIT;
    }
    else
    {
        return 1;
    }
}

float CombatManager::lifeSteal(GameEntity* pAttacker, float netDamage)
{
    float lifeSteal;

    return lifeSteal = (netDamage * 0.15);
}

float CombatManager::attackBlock(GameEntity* pDefender)
{
    int chance;
    const float BLOCK = 70;
    
    if (pDefender->meleeAttack == true)
    {
        chance = randomInt(1, 2);

        if (chance == 1)
        {
			return BLOCK;
        }
    }

    return 0;
}

//////////////////
//    Stats     //
// Calculations //
//////////////////

int CombatManager::totalAGICalc(GameEntity* pUnitA)
{
    return pUnitA->totalAGI = pUnitA->baseAGI + (pUnitA->perLvlAGI * pUnitA->currentLvl) + pUnitA->totalItemAGI + (pUnitA->totalBuffAGI - pUnitA->totalDebuffAGI);
}
int CombatManager::totalINTCalc(GameEntity* pUnitA)
{
    return pUnitA->totalINT = pUnitA->baseINT + (pUnitA->perLvlINT * pUnitA->currentLvl) + pUnitA->totalItemINT + (pUnitA->totalBuffINT - pUnitA->totalDebuffINT);
}
int CombatManager::totalSTRCalc(GameEntity* pUnitA)
{
    return pUnitA->totalSTR = pUnitA->baseSTR + (pUnitA->perLvlSTR * pUnitA->currentLvl) + pUnitA->totalItemSTR + (pUnitA->totalBuffSTR - pUnitA->totalDebuffSTR);
}

int CombatManager::mainATRCalc(GameEntity* pUnitA)
{
    if (pUnitA->mainATRType == 1)
    {
        return pUnitA->totalSTR;
    }
    if (pUnitA->mainATRType == 2)
    {
        return pUnitA->totalAGI;
    }
    if (pUnitA->mainATRType == 3)
    {
        return pUnitA->totalINT;
    }

    return 0;
}
float CombatManager::totalArmorCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseArmor + pUnitA->totalItemArmor + (0.16 * pUnitA->totalAGI) + (pUnitA->totalBuffArmor - pUnitA->totalDebuffArmor));
}
int CombatManager::totalMaxDMGCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseMaxDMG + pUnitA->totalItemDMG + (pUnitA->totalBuffDMG - pUnitA->totalDebuffDMG) + mainATRCalc(pUnitA));
}
int CombatManager::totalMinDMGCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseMinDMG + pUnitA->totalItemDMG + (pUnitA->totalBuffDMG - pUnitA->totalDebuffDMG) + mainATRCalc(pUnitA));
}
float CombatManager::totalAttackSpeedCalc(GameEntity* pUnitA)
{
    return (pUnitA->BAT - (pUnitA->totalItemAttackSpeed + (pUnitA->totalBuffAttackSpeed - pUnitA->totalDebuffAttackSpeed)));
}
int CombatManager::totalAttackRangeCalc(GameEntity* pUnitA)
{
    return (pUnitA->attackRange + pUnitA->totalItemAttackRange);
}
int CombatManager::totalHPCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseHP + pUnitA->totalItemHP + (pUnitA->totalBuffHP - pUnitA->totalDebuffHP) + (20 * pUnitA->totalSTR));
}
int CombatManager::totalMPCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseMP + pUnitA->totalItemMP + (pUnitA->totalBuffMP - pUnitA->totalDebuffMP) + (12 * pUnitA->totalINT));
}
float CombatManager::totalHPRCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseHPR + pUnitA->totalItemHPR + (pUnitA->totalBuffHPR - pUnitA->totalDebuffHPR)) * (1 + pUnitA->totalSTR * 0.0071);
}
float CombatManager::totalMPRCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseMPR + pUnitA->totalItemMPR + (pUnitA->totalBuffMPR - pUnitA->totalDebuffMPR)) * (1 + pUnitA->totalINT * 0.02);
}
float CombatManager::totalMagicResistCalc(GameEntity* pUnitA)
{
    return 1 - ((1 - pUnitA->baseMagicResist) * (1 - pUnitA->totalItemMagicResist) * (1 - pUnitA->totalBuffMagicResist - pUnitA->totalDebuffMagicResist));
}
int CombatManager::totalMoveCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseMovementSpeed + pUnitA->totalItemMove) * (1 + (pUnitA->totalItemMovePercent + pUnitA->totalBuffMove - pUnitA->totalDebuffMove));
}
float CombatManager::totalSpellAMPCalc(GameEntity* pUnitA)
{
    return (1 + (pUnitA->totalItemSpellAMP + (pUnitA->totalBuffSpellAMP - pUnitA->totalDebuffSpellAMP) + (0.007 * pUnitA->totalINT)));
}
float CombatManager::totalManaLossReducCalc(GameEntity* pUnitA)
{
    return (1 - (pUnitA->totalItemManaLossReduc + (pUnitA->totalBuffManaLossReduc - pUnitA->totalDebuffManaLossReduc)));
}
float CombatManager::totalStatusResistCalc(GameEntity* pUnitA)
{
    return (1 - (pUnitA->totalItemStatusResist + (pUnitA->totalBuffStatusResist - pUnitA->totalDebuffStatusResist)));
}
float CombatManager::totalSTRHeroStatusResistCalc(GameEntity* pUnitA)
{
    return (1 - (pUnitA->totalItemStatusResist + (pUnitA->totalBuffStatusResist - pUnitA->totalDebuffStatusResist) + (pUnitA->totalSTR * 0.0015)));
}
int CombatManager::totalAGIHeroMoveCalc(GameEntity* pUnitA)
{
    return (pUnitA->baseMovementSpeed + pUnitA->totalItemMove) * (1 + (pUnitA->totalItemMovePercent + pUnitA->totalBuffMove - pUnitA->totalDebuffMove)* 1 + (pUnitA->totalAGI * 0.006));
}
float CombatManager::totalINTHeroMagicResist(GameEntity* pUnitA)
{
    return 1 - ((1 - pUnitA->baseMagicResist) * (1 - pUnitA->totalItemMagicResist) * (1 - pUnitA->totalBuffMagicResist - pUnitA->totalDebuffMagicResist) * (1 - (pUnitA->totalINT * 0.0015)));
}

GameEntity* CombatManager::allTotalCalc(GameEntity* pUnitA)
{
    pUnitA->totalSTR = totalSTRCalc(pUnitA);
    pUnitA->totalAGI = totalAGICalc(pUnitA);
    pUnitA->totalINT = totalINTCalc(pUnitA);

    pUnitA->totalArmor = totalArmorCalc(pUnitA);
    pUnitA->totalMaxDMG = totalMaxDMGCalc(pUnitA);
    pUnitA->totalMinDMG = totalMinDMGCalc(pUnitA);
    pUnitA->totalHP = totalHPCalc(pUnitA);
    pUnitA->totalHPR = totalHPRCalc(pUnitA);
    pUnitA->totalMP = totalMPCalc(pUnitA);
    pUnitA->totalMPR = totalMPRCalc(pUnitA);
    pUnitA->totalAttackRange = totalAttackRangeCalc(pUnitA);
    pUnitA->totalAttackSpeed = totalAttackSpeedCalc(pUnitA);
    pUnitA->totalMoveSpeed = totalMoveCalc(pUnitA);
    pUnitA->totalSpellAMP = totalSpellAMPCalc(pUnitA);
    pUnitA->totalManaLossReduc = totalManaLossReducCalc(pUnitA);
    pUnitA->totalStatusResist = totalStatusResistCalc(pUnitA);

    switch (pUnitA->mainATRType)
    {
        case 1:
        {
            pUnitA->totalStatusResist = totalSTRHeroStatusResistCalc(pUnitA);
        }
        break;
        case 2:
        {
            pUnitA->totalMoveSpeed = totalAGIHeroMoveCalc(pUnitA);
        }
        break;
        case 3:
        {
            pUnitA->totalMagicResist = totalINTHeroMagicResist(pUnitA);
        }
        break;
        default:
        break;
    }

    pUnitA->currentHP = pUnitA->totalHP;
    pUnitA->currentMP = pUnitA->totalMP;

    return pUnitA;
}

////////////////////
//    In Combat   //
//    Functions   //
////////////////////


void CombatManager::healthManaRegen(GameEntity* pRegenUnit)
{
    if (pRegenUnit->currentHP < pRegenUnit->totalHP)
    {
        pRegenUnit->currentHP += (pRegenUnit->totalHPR * 0.1);
    }
    if (pRegenUnit->currentMP < pRegenUnit->totalMP)
    {
        pRegenUnit->currentMP += (pRegenUnit->totalMPR * 0.1);
    }
}

bool CombatManager::statusCheckFunction(GameEntity* pAffectedUnit, ArenaManager* pArena)
{
    GameManager* ptrDotAArenaGame;

    float duration;
    bool turnSkipped = false;

    if (pAffectedUnit->currentHP < 0)
    {
        cout << pAffectedUnit->entityName << " has died." << endl;

        pAffectedUnit->isAlive = false;

        turnSkipped = true;
    }
    if (pAffectedUnit->isStunned == true)
    {
        if (pAffectedUnit->stunDuration <= pArena->matchTime)
        {
            pAffectedUnit->isStunned = false;
            cout << pAffectedUnit->entityName << " is no longer stunned." << endl;
        }
        else
        {
            duration = pArena->matchTime - pAffectedUnit->stunDuration;

            cout << duration << " seconds until stun expires" << endl;
            turnSkipped = true;
        }
    }
    if (pAffectedUnit->isSlowed == true)
    {
        if (pAffectedUnit->slowDuration <= pArena->matchTime)
        {
            pAffectedUnit->isSlowed = false;
            cout << pAffectedUnit->entityName << " is no longer slowed." << endl;
        }
        else
        {
            duration = pArena->matchTime - pAffectedUnit->slowDuration;

            cout << duration << " seconds until slow expires" << endl;
        }
    }
    if (pAffectedUnit->isMuted == true)
    {
        if(pAffectedUnit->muteDuration <= pArena->matchTime)
        {
            pAffectedUnit->isMuted = false;
            cout << pAffectedUnit->entityName << " is no longer muted." << endl;
        }
        else
        {
            duration = pArena->matchTime - pAffectedUnit->muteDuration;

            cout << duration << " seconds until mute expires" << endl;
        }
    }
    if (pAffectedUnit->isSilenced == true)
    {
        if (pAffectedUnit->silenceDuration <= pArena->matchTime)
        {
        	pAffectedUnit->isSilenced = false;
            cout << pAffectedUnit->entityName << " is no longer silenced." << endl;
        }
        else
        {
            duration = pArena->matchTime - pAffectedUnit->stunDuration;

            cout << duration << " seconds until silence expires" << endl;
        }
    }
    if (pAffectedUnit->isDisarmed == true)
    {
        if (pAffectedUnit->disarmDuration <= pArena->matchTime)
        {
            pAffectedUnit->isDisarmed = false;

            cout << pAffectedUnit->entityName << " is no longer disarmed." << endl;
        }
        else
        {
            duration = pArena->matchTime - pAffectedUnit->stunDuration;

            cout << duration << " seconds until disarm expires" << endl;
        }
    }
    if (pAffectedUnit->isAfraid == true)
    {
        if (pAffectedUnit->fearDuration <= pArena->matchTime)
        {
            pAffectedUnit->isAfraid = false;
            pAffectedUnit->isMoving = false;
            cout << pAffectedUnit->entityName << " is no longer afraid." << endl;
        }
        else
        {
            duration = pArena->matchTime - pAffectedUnit->stunDuration;
            cout << duration << " seconds until fear expires" << endl;
            turnSkipped = true;
        }
    }
    if (pAffectedUnit->isAttacking == true)
    {
        if (pAffectedUnit->attackDuration <= pArena->matchTime)
        {
            pAffectedUnit->isAttacking = false;
        }
        else
        {
            turnSkipped = true;
        }
    }
    if (pAffectedUnit->isMoving == true)
    {
        onTheMove(pAffectedUnit);
        turnSkipped = true;
    }
    if (pAffectedUnit->isCasting == true)
    {
        if (pAffectedUnit->castDuration <= pArena->matchTime)
        {
            pAffectedUnit->isCasting = false;
        }
        else
        {
            turnSkipped = true;
        }
    }
    return turnSkipped;
}

int CombatManager::unitDistanceCalc(GameEntity* pHereUnit, GameEntity* pOverThereUnit)
{
    int distance;
	
	distance = distanceCalc(pHereUnit->XPosition, pOverThereUnit->XPosition) + distanceCalc(pHereUnit->YPosition, pOverThereUnit->YPosition);

    if (distance < 0)
    {
        distance *= -1;
    }

    return distance;
}

int CombatManager::randomInt(int numberMin, int numberMax)
{
    int range = numberMax - numberMin + 1;
    return rand()%range - numberMin;
}

int CombatManager::distanceCalc (int herePOS, int therePOS)
{
    int distance = (herePOS - therePOS);

    if (distance < 0)
    {
        distance *= -1;
    }

    return distance;
}

//////////////////
//   Movement   //
//   Controls   //
//////////////////

GameEntity* CombatManager::movementScreen(GameEntity* pUnitA, GameEntity* pUnitB)
{
    if (pUnitA->isPlayer == true)
    {
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//" << setw(76) << "//" << endl;
        cout << "//                        Player Movement Screen                            //" << endl;
        cout << "//" << setw(76) << "//" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "//" << setw(76) << "//" << endl;
        cout << "//     Player can move up to " << pUnitA->totalMoveSpeed << " units within one second period.            //" << endl;
        cout << "//" << setw(76) << "//" << endl;
        cout << "//     Please enter the desired location within your total movement speed.  //" << endl;
        cout << "//" << setw(76) << "//" << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "       X: ";
        cin >> pUnitA->XDestination;
        cout << endl;
        cout << endl;
        cout << "       Y: ";
        cin >> pUnitA->YDestination;
        cout << endl;
        cout << endl;

        if (distanceCalc(pUnitA->XPosition, pUnitA->XDestination) - distanceCalc(pUnitA->YPosition, pUnitA->YDestination) <= pUnitA->totalMoveSpeed)
        {
            pUnitA->isMoving = true;
            cout << pUnitA->entityName << " is on the move." << endl;

        }
        else
        {
            cout << "That is too far for you to go; pick a smaller number." << endl;
        }
    }
    else
    {
        cout << " enemy controls are being activated." << endl;
        enemyMovementControls(pUnitA, pUnitB);
    }
    return pUnitA;
}

void CombatManager::enemyMovementControls(GameEntity* pEnemy, GameEntity* pPlayer)
{
    int botMovement;

    for (int i = 0; i <= 1000; ++i)
    {
        pEnemy->XDestination = randomInt(pEnemy->XPosition, pPlayer->XPosition);
        pEnemy->YDestination = randomInt(pEnemy->YPosition, pPlayer->YPosition);

        if (pEnemy->XDestination < 0)
        {
            pEnemy->XDestination *= -1;
        }
        if (pEnemy->YDestination < 0)
        {
            pEnemy->YDestination *= -1;
        }

        botMovement = distanceCalc(pEnemy->XPosition, pEnemy->XDestination) - distanceCalc(pEnemy->YPosition, pEnemy->YDestination);

        if (botMovement < 0)
        {
            botMovement *= -1;
        }

        cout << "Attempting to move." << endl;
        if ( botMovement <= pEnemy->totalMoveSpeed)
        {
            pEnemy->isMoving = true;
            cout << pEnemy->entityName << " is on the move." << endl;
            cout << pEnemy->XDestination << endl;
            cout << pEnemy->YDestination << endl;
            cout << endl;
            break;
        }
    }
}

void CombatManager::onTheMove(GameEntity* pMovingUnit)
{

    cout << pMovingUnit->entityName << endl;
    cout << "Current X: " << pMovingUnit->XPosition << endl;
    cout << "Current Y: " << pMovingUnit->YPosition << endl;

    pMovingUnit->moveTiles = (pMovingUnit->totalMoveSpeed * 0.1);	

    if (pMovingUnit->XPosition != pMovingUnit->XDestination)
    {
        if(pMovingUnit->XPosition < pMovingUnit->XDestination)
        {
            for (;;)
            {
                moveXUP(pMovingUnit);
                if (pMovingUnit->XPosition == pMovingUnit->XDestination || pMovingUnit->moveTiles <= 0)
                {
                    break;
                }
            }
        }
        if(pMovingUnit->XPosition > pMovingUnit->XDestination)
        {
            for (;;)
            {
                moveXDOWN(pMovingUnit);
                if (pMovingUnit->XPosition == pMovingUnit->XDestination || pMovingUnit->moveTiles <= 0)
                {
                    break;
                }
            }
        }
    }
    else if (pMovingUnit->YPosition != pMovingUnit->YDestination)
    {
        if(pMovingUnit->YPosition < pMovingUnit->YDestination)
        {
            for (;;)
            {
                moveYUP(pMovingUnit);
                if (pMovingUnit->XPosition == pMovingUnit->XDestination || pMovingUnit->moveTiles <= 0)
                {
                    break;
                }
            }
        }
        if(pMovingUnit->YPosition > pMovingUnit->YDestination)
        {
            for (;;)
            {
                moveYDOWN(pMovingUnit);
                if (pMovingUnit->XPosition == pMovingUnit->XDestination || pMovingUnit->moveTiles <= 0)
                {
                    break;
                }
            }
        }
    }
    else
    {
        cout << pMovingUnit->entityName << " has stopped moving." << endl;
        pMovingUnit->isMoving = false;
    }
}

void CombatManager::moveXUP(GameEntity* pMovingUnit)
{
    pMovingUnit->XPosition += 1;
    pMovingUnit->moveTiles -= 1;

    pMovingUnit->facingNorth = true;
    pMovingUnit->facingEast = false;
    pMovingUnit->facingWest = false;
    pMovingUnit->facingSouth = false;
}

void CombatManager::moveXDOWN(GameEntity* pMovingUnit)
{
    pMovingUnit->XPosition -= 1;
    pMovingUnit->moveTiles -= 1;

    pMovingUnit->facingNorth = false;
    pMovingUnit->facingEast = false;
    pMovingUnit->facingWest = false;
    pMovingUnit->facingSouth = true;
}

void CombatManager::moveYUP(GameEntity* pMovingUnit)
{
    pMovingUnit->YPosition += 1;
    pMovingUnit->moveTiles -= 1;

    pMovingUnit->facingNorth = false;
    pMovingUnit->facingEast = true;
    pMovingUnit->facingWest = false;
    pMovingUnit->facingSouth = false;
}

void CombatManager::moveYDOWN(GameEntity* pMovingUnit)
{
    pMovingUnit->YPosition -= 1;
    pMovingUnit->moveTiles -= 1;
    
    pMovingUnit->facingNorth = false;
    pMovingUnit->facingEast = false;
    pMovingUnit->facingWest = true;
    pMovingUnit->facingSouth = false;
}
