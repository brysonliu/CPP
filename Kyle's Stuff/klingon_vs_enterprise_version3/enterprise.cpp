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
    cout << "ENTERPRISE BEING CREATED. " << this << endl;
    mTorpedo = 10;
    mEnterpriseEnergy = 3000;
    ptrKlingon1 = new Klingon(firePhasers, fireTorpedoes);
    // ptrKlingon2 = new Klingon(firePhasers, fireTorpedoes, phaserTargetRow, phaserTargetColumn, torpedoTargetRow, torpedoTargetColumn);
    // ptrKlingon3 = new Klingon(firePhasers, fireTorpedoes, phaserTargetRow, phaserTargetColumn, torpedoTargetRow, torpedoTargetColumn);
    // ptrKlingon4 = new Klingon(firePhasers, fireTorpedoes, phaserTargetRow, phaserTargetColumn, torpedoTargetRow, torpedoTargetColumn);
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

    else if (playerInput == "TOR" || playerInput == "tor")
    {
        torpedoes();
    }

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
    cout << "NUMBER OF UNITS TO FIRE (MAX 200 UNITS) = ";
    while (!(cin >> phaserInput) || (phaserInput < 0) || (phaserInput > 200))
    {
        cin.clear();
        cin.ignore();
        cout << "INVALID NUMBER OF UNITS" << endl;
        cout << "ENERGY AVAILABLE = " << mEnterpriseEnergy << endl;
        cout << "NUMBER OF UNITS TO FIRE =  ";
        continue;
    }

    firePhasers = phaserInput;
    mEnterpriseEnergy = mEnterpriseEnergy - phaserInput;

    if (phaserInput == 0)
    {
        enterpriseInput();
    }

    else if (phaserInput >= 1 && phaserInput <= 200)
    {
        ptrKlingon1->klingonHealthPHA();
        /*
        cout << "CHOOSE TARGET SECTOR X: ";
        while (!(cin >> phaserTargetRow) || (phaserTargetRow < 0) || (phaserTargetRow > 8))
        {
            cin.clear();
            cin.ignore();
            cout << "INVALID COORDINATE" << endl;
            cout << "CHOOSE TARGET SECTOR X: ";
            continue;
        }

        cout << "CHOOSE TARGET SECTOR Y: ";
        while (!(cin >> phaserTargetColumn) || (phaserTargetColumn < 0) || (phaserTargetColumn > 8))
        {
            cin.clear();
            cin.ignore();
            cout << "INVALID COORDINATE" << endl;
            cout << "CHOOSE TARGET SECTOR Y: ";
            continue;
        }
        */
    }
};

void Enterprise::torpedoes()
{
    cout << "PHOTON TORPEDOES LEFT = " << mTorpedo << endl;
    cout << "TORPEDOES TO FIRE? ";
    while ((cin >> fireTorpedoes && fireTorpedoes < 0 && fireTorpedoes > 10))
    {
        cin.clear();
        cin.ignore();
        cout << "INVALID NUMBER OF TORPEDOES." << endl;
        cout << "PHOTON TORPEDOES LEFT = " << mTorpedo << endl;
        cout << "\nTORPEDOES TO FIRE? ";
        continue;            
    }

    mTorpedo = mTorpedo - fireTorpedoes;

    if (fireTorpedoes == 0)
    {
        enterpriseInput();
    }

    else if (fireTorpedoes >= 1 && fireTorpedoes <= 10)
    {
        ptrKlingon1->klingonHealthTOR();
    }
};