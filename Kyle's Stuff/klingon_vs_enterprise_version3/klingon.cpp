//
//  Kyle Samson
//  C++ Programming II
//  klingon.cpp
//

#include "enterprise.hpp"
#include "klingon.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Klingon::Klingon(int firePhasers, int fireTorpedoes)
{
    cout << "KLINGON OBJECT BEING CREATED. " << this << endl;
    mFirePhasers = firePhasers;
    mFireTorpedoes = fireTorpedoes;

    klingonQuadrantRow = 4;
    klingonQuadrantColumn = 5;
    mKlingonRow = 3;
    mKlingonColumn = 3;
    mKlingonEnergy = 200;
    mKlingonRow = 3; // (rand() % 8) + 1;
    mKlingonColumn = 3; // (rand() % 8) + 1;

    // mDamageMin = 100;
    // mDamageMid = 200;
    // mDamageMax = mDamageMin + mDamageMid;
};

Klingon::~Klingon()
{
    cout << "***KLINGON DESTROYED***" << endl;
    mScore = mScore + 10;
    klingonsLeft--;

    if (klingonsLeft <= 0)
    {
        mScore = mScore + 100;
        cout << "\nCONGRATULATIONS, CAPTAIN!"
                << "\n\nTHE LAST KLINGON BATTLE CRUISER MENACING THE FEDERATION HAS BEEN DESTROYED."
                << "\n\nYOUR EFFICIENCY RATING IS: " << mScore << endl;
    }
};

int Klingon::klingonHealthPHA()
{
    cout << mFirePhasers << " UNIT HIT ON KLINGON AT SECTOR " << mKlingonRow << " , " << mKlingonColumn << endl;
    mKlingonEnergy = mKlingonEnergy - mFirePhasers;

    if (mKlingonEnergy <= 0)
    {
        this->~Klingon();
    }
};

int Klingon::klingonHealthTOR()
{
    cout << "TORPEDO TRACK: " << endl;
    mKlingonEnergy = mKlingonEnergy - 200;

    if (mKlingonEnergy <= 0)
    {
        this->~Klingon();
    }
}

/*
void Klingon::attack()
{
    int klingonAttack = rand()%mDamageMax + mDamgeMin;
    if (mKlingonEnergy >= 1 && mKlingonEnergy <= 200)
    {
        cout << "KLINGON ATTACKS FOR " << klingonAttack << " DAMAGE." << endl;
        /*
        mEnterpriseEnergy = mEnterpriseEnergy - klingonAttack;
        if (mEnterpriseEnergy == 0)
        {
            mScore = mScore - 100;
            cout << "\n\nIT IS STARDATE 3000."
                 << "\n\nTHE ENTERPRISE HAS BEEN DESTROYED. THE FEDERATION WILL BE CONQUERED."
                 << "\n\nTHERE WERE 1 KLINGONS LEFT AT THE END OF YOUR MISSION."
                 << "\n\nYOUR EFFICIENCY RATING IS: " << mScore;
        }
    }
}
*/

/*
void Klingon::attack(int enterpriseEnergy, int score)
{
    if (klingonEnergy == 0)
    {
        cout << endl;
    }

    if (klingonEnergy >= 1 && klingonEnergy == 1000)
    {
        cout << "Klingon attacks for " << rand()%klingonDamageMax + klingonDamageMin << " damage." << endl;
        enterpriseEnergy = enterpriseEnergy - 100;

        if (enterpriseEnergy == 0)
        {
            score = score - 100;
            cout << "\n\nIT IS STARDATE 0000."
                << "\n\nTHE ENTERPRISE HAS BEEN DESTROYED. THE FEDERATION WILL BE CONQUERED."
                << "\n\nTHERE WERE 1 KLINGONS LEFT AT THE END OF YOUR MISSION."
                << "\n\nYOUR EFFICIENCY RATING IS: " << score;
        }
    }
}
*/