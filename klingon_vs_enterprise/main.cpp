#include "klingon.hpp"
#include <iostream>
using namespace std;

int main()
{
    ////////////////
    // Enterprise //
    ////////////////
    EnterprisePhasers ph;
    EnterpriseTorpedoes pt;
    EnterpriseAttack* ptrPhasers = &ph;
    EnterpriseAttack* ptrTorpedo = &pt;

    //////////////
    // Klingons //
    //////////////
    Enemy* ptrKlingon1 = new Klingon();
    Enemy* ptrKlingon2 = new Klingon();
    Enemy* ptrKlingon3 = new Klingon();
    Enemy* ptrKlingon4 = new Klingon();
    
    ptrPhasers->phasers();
    // ptrTorpedo->torpedoes();

    ptrKlingon1->attack();
    // ptrKlingon2->attack();
    // ptrKlingon3->attack();
    // ptrKlingon4->attack();

    delete ptrKlingon2;
}