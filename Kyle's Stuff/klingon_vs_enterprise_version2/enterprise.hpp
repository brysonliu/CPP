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
        //void torpedoes();

        string playerInput;
        int firePhasers;
        //int fireTorpedoes;

    private:
        Klingon* mPtrPhasers;

        int mQuadrantRow = 4;
        int mQuadrantColumn = 5;

        //int mTorpedo;
        int mEnterpriseEnergy;
        //int mKlingonEnergy;
        //int mKlingonsLeft;
};

#endif

