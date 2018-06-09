//
//  Kyle Samson
//  C++ Programming II
//  klingon.hpp
//

#ifndef klingon_hpp
#define klingon_hpp
#include <string>
using namespace std;

class Klingon
{
    public:
        Klingon(int firePhasers, int fireTorpedoes);
        ~Klingon();

        int klingonHealthPHA();
        int klingonHealthTOR();
        // void attack();

        int klingonQuadrantRow;
        int klingonQuadrantColumn;
        int klingonsLeft = 4;

    private:
        int mFirePhasers;
        int mFireTorpedoes;
        int mScore;

        int mKlingonRow;
        int mKlingonColumn;

        int mKlingonEnergy;
        //int mDamageMin;
        //int mDamageMid;
        //int mDamageMax;
};

/*
class KlingonOne
{
    public:
        int klingonHealthPHA();
        int klingonHealthTOR();
        // void attack();

        int klingonQuadrantRow;
        int klingonQuadrantColumn;
        int klingonsLeft;

    private:
        int mFirePhasers;
        int mFireTorpedoes;
        int mScore = 0;

        int mKlingonRow;
        int mKlingonColumn;

        int mKlingonEnergy = 200;
        //int mDamageMin;
        //int mDamageMid;
        //int mDamageMax;
};

class KlingonTwo
{

};

class KlingonThree
{

};

class KlingonFour
{

};
*/

#endif