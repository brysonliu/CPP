//
//  Kyle Samson
//  C++ Programming II
//  klingon.hpp
//

#ifndef klingon_hpp
#define klingon_hpp

class Klingon
{
    public:
        Klingon(int firePhasers);
        ~Klingon();

        int klingonHealthPHA();
        // int klingonHealthTOR();
        // void attack();

    private:
        int mKlingonQuadrantRow = 4;
        int mKlingonQuadrantColumn = 5;

        int mFirePhasers;
        //int mFireTorpedoes;
        int mScore;

        int mKlingonEnergy;
        int mKlingonsLeft;
        //int mDamageMin;
        //int mDamageMid;
        //int mDamageMax;
};

#endif