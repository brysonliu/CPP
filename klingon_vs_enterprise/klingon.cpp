#include "klingon.hpp"
#include <iostream>

using namespace std;

int klingonsLeft = 4;
int enterpriseEnergy = 3000;
int klingonEnergy = 1000;
int score = 0;

int firePhasers;

void EnterprisePhasers::phasers()
{
    cout << "PHASERS LOCKED ON TARGET." << endl;
    cout << "ENERGY AVAILABLE = " << enterpriseEnergy << endl;
    cout << "NUMBER OF UNITS TO FIRE = ";
    while (!(cin >> firePhasers) || (firePhasers > 3000))
    {
        cin.clear();
        cin.ignore();
        cout << "INVALID NUMBER OF UNITS" << endl;
        cout << "ENERGY AVAILABLE = " << enterpriseEnergy << endl;
        cout << "\nNUMBER OF UNITS TO FIRE =  ";
        continue;            
    }

    cout << firePhasers << " UNIT HIT ON KLINGON AT SECTOR 0 , 0" << endl;
    klingonEnergy = klingonEnergy - firePhasers;

    if (klingonEnergy == 0)
    {
        cout << "***KLINGON DESTROYED***";
        score = score + 10;
        klingonsLeft--;

        if (klingonsLeft == 0)
        {
            score = score + 100;
            cout << "\n\nCONGRATULATIONS, CAPTAIN!"
                 << "\n\nTHE LAST KLINGON BATTLE CRUISER MENACING THE FEDERATION HAS BEEN DESTROYED."
                 << "\n\nYOUR EFFICIENCY RATING IS: " << score;
        }
    }
}

void EnterpriseTorpedoes::torpedoes()
{
    cout << "TORPEDO TRACK: " << endl;
    klingonEnergy = klingonEnergy - 1000;

    if (klingonEnergy == 0)
    {
        cout << "***KLINGON DESTROYED***";
        score = score + 10;
        klingonsLeft--;

        if (klingonsLeft == 0)
        {
            score = score + 100;
            cout << "\n\nCONGRATULATIONS, CAPTAIN!"
                 << "\n\nTHE LAST KLINGON BATTLE CRUISER MENACING THE FEDERATION HAS BEEN DESTROYED."
                 << "\n\nYOUR EFFICIENCY RATING IS: " << score;
        }
    }
}

void Klingon::attack()
{
    int klingonDamageMin = 100;
    int klingonDamageMid = 200;
    int klingonDamageMax = klingonDamageMid - klingonDamageMin + 1;

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
