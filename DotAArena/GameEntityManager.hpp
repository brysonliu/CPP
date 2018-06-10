//
// Kaylin C. Tate
// DotA Arena
// GameUnit
//

#ifndef GameEntityManager_hpp
#define GameEntityManager_hpp

using namespace std;

class GameEntity
{

    public:

        GameEntity(string entityName, int currentLvl, int mainATRType, bool meleeAttack, int attackRange, float BAT, float BCT, int baseMovementSpeed, float baseArmor, int baseSTR, int baseAGI, int baseINT, float perLvlSTR, float perLvlAGI, float perLvlINT, int baseHP, int baseMP, float baseHPR, float baseMPR, int baseMaxDMG, int baseMinDMG, float baseMagicResist, int dayVision, int nightVision, 
                    bool isPlayer, int inventory, int goldSupply);
        ~GameEntity();
        
        GameEntity enemySetUP(int tournamentRound, int monsterClass);
        GameEntity roundOneMonster(int monsterClass);
        GameEntity roundTwoMonster(int monsterClass);
        GameEntity roundThreeMonster(int monsterClass);
        GameEntity roundFourMonster(int monsterClass);
        GameEntity roundFiveMonster(int monsterClass);

        string entityName;
        int currentLvl;
        int mainATRType;
        bool meleeAttack;
        int attackRange = 0;
        float BAT = 0.0;
        float BCT = 0.0;
        int baseMovementSpeed = 0;
        float baseArmor = 0.0;
        int baseSTR = 0;
        int baseAGI = 0;
        int baseINT = 0;
        float perLvlSTR = 0.0;
        float perLvlAGI = 0.0;
        float perLvlINT = 0.0;
        int baseHP = 0;
        int baseMP = 0;
        float baseHPR = 0.0;
        float baseMPR = 0.0;
        int baseMaxDMG = 0;
        int baseMinDMG = 0;
        float baseMagicResist = 0.0;
        int dayVision = 0;
        int nightVision = 0;
        int XPosition = 0;
        int YPosition = 0;
        int XDestination = 0;
        int YDestination = 0;

        //////////////////
        //  Item Stats  //
        //////////////////

        int totalItemAGI = 0.0;
        int totalItemINT = 0.0;
        int totalItemSTR = 0.0;
        float totalItemArmor = 0.0;
        int totalItemAttackSpeed = 0.0;
        int totalItemAttackRange = 0.0;
        int totalItemDMG = 0.0;
        int totalItemHP = 0.0;
        float totalItemHPR = 0.0;
        int totalItemMP = 0.0;
        float totalItemMPR = 0.0;
        int totalItemMove = 0.0;
        int totalItemMovePercent = 0.0;
        float totalItemMagicResist = 0.0;
        float totalItemSpellAMP = 0.0;
        float totalItemManaLossReduc = 0.0;
        float totalItemStatusResist = 0.0;

        //////////////////
        //  Buff Stats  //
        //////////////////

        int totalBuffAGI = 0.0;
        int totalBuffINT = 0.0;
        int totalBuffSTR = 0.0;
        int totalBuffArmor = 0.0;
        int totalBuffAttackSpeed = 0.0;
        int totalBuffDMG = 0.0;
        int totalBuffHP = 0.0;
        float totalBuffHPR = 0.0;
        int totalBuffMP = 0.0;
        float totalBuffMPR = 0.0;
        int totalBuffMove = 0.0;
        float totalBuffMovePercent = 0.0;
        int totalBuffMagicResist = 0.0;
        float totalBuffSpellAMP = 0.0;
        float totalBuffManaLossReduc = 0.0;
        float totalBuffStatusResist = 0.0;

        //////////////////
        //  Buff Stats  //
        //////////////////

        int totalDebuffAGI = 0.0;
        int totalDebuffINT = 0.0;
        int totalDebuffSTR = 0.0;
        int totalDebuffArmor = 0.0;
        int totalDebuffAttackSpeed = 0.0;
        int totalDebuffDMG = 0.0;
        int totalDebuffHP = 0.0;
        float totalDebuffHPR = 0.0;
        int totalDebuffMP = 0.0;
        float totalDebuffMPR = 0.0;
        int totalDebuffMove = 0.0;
        float totalDebuffMovePercent = 0.0;
        int totalDebuffMagicResist = 0.0;
        float totalDebuffSpellAMP = 0.0;
        float totalDebuffManaLossReduc = 0.0;
        float totalDebuffStatusResist = 0.0;

        //////////////////
        // Stats Totals //
        //////////////////

        int totalHP = 0.0;
        float totalHPR = 0.0;
        float currentHP = 0.0;
        int totalMP = 0.0;
        float totalMPR = 0.0;
        int currentMP = 0.0;
        int totalMoveSpeed = 0.0;
        float totalSTR = 0.0;
        float totalAGI = 0.0;
        float totalINT = 0.0;
        int totalMaxDMG = 0.0;
        int totalMinDMG = 0.0;
        float totalArmor = 0.0;
        float totalSpellAMP = 0.0;
        float totalAttackSpeed = 0.0;
        float totalMagicResist = 0.0;
        float totalManaLossReduc = 0.0;
        int totalAttackRange = 0.0;
        int totalStatusResist = 0.0;

        //////////////////////
        // In Combat Status //
        //////////////////////

        bool isAlive = true;
        bool isMoving = false;
        bool isAttacking = false;
        bool isCasting = false;

        bool isStunned = false;
        bool isSilenced = false;
        bool isMuted = false;
        bool isSlowed = false;
        bool isDisarmed = false;
        bool isRooted = false;
        bool isAfraid = false;

        float attackDuration = 0.0;
        float castDuration = 0.0;
        float stunDuration = 0.0;
        float silenceDuration = 0.0;
        float muteDuration = 0.0;
        float slowDuration = 0.0;
        float disarmDuration = 0.0;
        float rootDuration = 0.0;
        float fearDuration = 0.0;

        bool isSpellImmune = false;
        bool isEthereal = false;
        bool isInvisible = false;

        float spellImmuneDuration = 0.0;
        float etherealDuration = 0.0;
        float invisibleDuration = 0.0;

        //////////////////////
        // Item Information //
        //////////////////////

        int goldSupply;
        int inventory = 0;
        int maxInventory = 6;

        bool hasAbyssal = false;
        bool hasAetherLens = false;
        bool hasBlink = false;
        bool hasBloodThorn = false;
        bool hasBKB = false;
        bool hasDesolator = false;
        bool hasDragonLance = false;
        bool hasEchoSabre = false;
        bool hasHealingSalve = false;
        bool hasKaya = false;
        bool hasMorbidMask = false;
        bool hasNullifier = false;
        bool hasPowerTreads = false;
        bool hasRodofAtos = false;
        bool hasSange = false;
        bool hasYasha = false;

        ///////////////////////////
        // Other Important Stuff //
        ///////////////////////////

        bool isPlayer;
        int playerNumber =0;
        int moveTiles = 0;
        bool facingNorth;
        bool facingSouth;
        bool facingEast;
        bool facingWest;
};

#endif
