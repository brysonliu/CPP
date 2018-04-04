//
//  Kyle Samson
//  C++ Programming II
//  klingon.cpp
//

#include "enterprise.hpp"
#include "klingon.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Klingon::Klingon(int firePhasers)
{
    cout << "KLINGON OBJECT BEING CREATED. " << this << endl;
    mFirePhasers = firePhasers;
    // mFireTorpedoes = fireTorpedoes;

    mKlingonEnergy = 200;
    mKlingonsLeft = 1;
    //mDamageMin = 100;
    //mDamageMid = 200;
    //mDamageMax = mDamageMin + mDamageMid;
    mScore = 0;

    this->klingonHealthPHA();
};

Klingon::~Klingon()
{
    cout << "\nKLINGON OBJECT BEING DELETED. " << this << endl;
};

int Klingon::klingonHealthPHA()
{
    cout << mFirePhasers << " UNIT HIT ON KLINGON AT SECTOR 0 , 0" << endl;
    mKlingonEnergy = mKlingonEnergy - mFirePhasers;

    if (mKlingonEnergy == 0)
    {
        cout << "***KLINGON DESTROYED***";
        mScore = mScore + 10;
        mKlingonsLeft--;

        if (mKlingonsLeft == 0)
        {
            mScore = mScore + 100;
            cout << "\n\nCONGRATULATIONS, CAPTAIN!"
                 << "\n\nTHE LAST KLINGON BATTLE CRUISER MENACING THE FEDERATION HAS BEEN DESTROYED."
                 << "\n\nYOUR EFFICIENCY RATING IS: " << mScore;
            exit(1);
        }
    }
};

/*
int Klingon::klingonHealthTOR();
{
    mKlingonEnergy = mKlingonEnergy - mFireTorpedoes;
}

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