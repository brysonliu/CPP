//
//  Kyle Samson
//  C++ Programming II
//  main.hpp
//

#include "enterprise.hpp"

using namespace std;

int main()
{
    Enterprise* ptrEnterpriseTest = new Enterprise();
    ptrEnterpriseTest->play();
    delete ptrEnterpriseTest;

    //////////////////////////////////////////////////
    // Klingon* ptrKlingon1 = new Klingon();

    ////////////////
    // Enterprise //
    ////////////////
    // Enterprise ph;
    // Enterprise pt;
    // Enterprise* ptrPhasers = &ph;
    // Enterprise* ptrTorpedo = &pt;

    //////////////
    // Klingons //
    //////////////
    
    // Enemy* ptrKlingon2 = new Klingon();
    // Enemy* ptrKlingon3 = new Klingon();
    // Enemy* ptrKlingon4 = new Klingon();
    
    // ptrPhasers->phasers();
    // ptrTorpedo->torpedoes();

    // ptrKlingon1->attack();
    // ptrKlingon2->attack();
    // ptrKlingon3->attack();
    // ptrKlingon4->attack();

    return 0;
}