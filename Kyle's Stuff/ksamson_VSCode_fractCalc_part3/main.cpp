#include "fraction.hpp"

int main()
{
    FractionCalc* ptrFractionCalc = new FractionCalc();
    ptrFractionCalc->integerOrStringInput();
    delete ptrFractionCalc;

    return 0;
}