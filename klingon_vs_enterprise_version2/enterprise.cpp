//
//  Kyle Samson
//  C++ Programming II
//  enterprise.cpp
// 

#include "enterprise.hpp"
#include "klingon.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Enterprise::Enterprise()
{
    cout << "ENTERPRISE BEING CREATED. " << this <<  endl << endl;
    // mPtrPhasers = new Klingon(firePhasers);
    //mTorpedo = 10;
    mEnterpriseEnergy = 3000;
    //mKlingonEnergy = 200;
    //mKlingonsLeft = 1;
    //mScore = 0;
}

Enterprise::~Enterprise()
{
    cout << "ENTERPRISE BEING DELETED. " << this;
}

void Enterprise::play()
{
    enterpriseInput();
};

void Enterprise::enterpriseInput()
{
    cout << "COMMAND? ";
    cin >> playerInput;

    if (playerInput == "PHA" || playerInput == "pha")
    {
        phasers();
    }

    /*
    else if (playerInput == "TOR" || playerInput == "tor")
    {
        torpedoes();
    }
    */

    else
    {
        cout << "\nSCIENCE OFFICER SPOCK REPORTS: BEG YOUR PARDON, CAPTAIN?\n"
                "TYPE 'HLP' FOR AVAILABLE COMMANDS.\n";
        enterpriseInput();
    }
};

void Enterprise::phasers()
{
    cout << "PHASERS LOCKED ON TARGET." << endl;
    cout << "ENERGY AVAILABLE = " << mEnterpriseEnergy << endl;
    cout << "NUMBER OF UNITS TO FIRE = ";
    while (!(cin >> firePhasers) || (firePhasers > 3000))
    {
        cin.clear();
        cin.ignore();
        cout << "INVALID NUMBER OF UNITS" << endl;
        cout << "ENERGY AVAILABLE = " << mEnterpriseEnergy << endl;
        cout << "\nNUMBER OF UNITS TO FIRE =  ";
        continue;            
    }
    
    mPtrPhasers = new Klingon(firePhasers);
    delete mPtrPhasers;
    enterpriseInput();
};

/*
void Enterprise::torpedoes()
{
    cout << "PHOTON TORPEDOES LEFT = " << mTorpedo << endl;
    cout << "TORPEDOES TO FIRE? ";
    while (!(cin >> fireTorpedoes) || (fireTorpedoes > 10))
    {
        cin.clear();
        cin.ignore();
        cout << "INVALID NUMBER OF TORPEDOES." << endl;
        cout << "PHOTON TORPEDOES LEFT = " << mTorpedo << endl;
        cout << "\nTORPEDOES TO FIRE? ";
        continue;            
    }

    mTorpedo = mTorpedo - fireTorpedoes;
    cout << "\nPHOTON TORPEDOES LEFT = " << mTorpedo << endl;
    cout << "TORPEDO TRACK: " << endl;
    mKlingonEnergy = mKlingonEnergy - 200;

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
        }
    }
}
*/