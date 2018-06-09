//
//  Kyle Samson
//  C++ Programming II
//  Super Star Trek Attack Header
//

#ifndef klingon_hpp
#define klingon_hpp

//////////////////////
// Enterprise Class //
//////////////////////
class EnterpriseAttack
{
    public: 
        virtual void phasers(){}
        virtual void torpedoes(){}
};

class EnterprisePhasers: public EnterpriseAttack
{
    public:
        void phasers();
};

class EnterpriseTorpedoes: public EnterpriseAttack
{
    public:
        void torpedoes();
};

///////////////////
// Klingon Class //
///////////////////
class Enemy
{
    public: 
        virtual void attack(){}
};

class Klingon: public Enemy
{
    public:
        void attack();
};

#endif