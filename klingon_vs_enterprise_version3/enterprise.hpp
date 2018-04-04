//
//  Kyle Samson
//  C++ Programming II
//  enterprise.hpp
//

#ifndef enterprise_hpp
#define enterprise_hpp

#include <string>
#include "klingon.hpp"

using namespace std;

//////////////////////
// Enterprise Class //
//////////////////////
class Enterprise 
{
    public:
        Enterprise();
        ~Enterprise();

        void play();
        void enterpriseInput();
        void phasers();
        void torpedoes();

        string playerInput;
        int phaserInput;
        int firePhasers;
        int fireTorpedoes;

        int quadrantRow = 4;
        int quadrantColumn = 5;

        Klingon* ptrPhasers;
        Klingon* ptrTorpedoes;
        Klingon* ptrKlingon1;
        Klingon* ptrKlingon2;
        Klingon* ptrKlingon3;
        Klingon* ptrKlingon4;

    private: 
        int mRow = 6;
        int mColumn = 2;
        int mTorpedo;
        int mEnterpriseEnergy;
};

#endif

