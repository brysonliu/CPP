#ifndef fraction_hpp
#define fraction_hpp

class FractionCalc
{
    public:
        int fraction[2] = { numerator, denominator };
        int numerator, denominator;

        FractionCalc();
        ~FractionCalc();

        void fractionAdd();
        void fractionSubtract();
        void fractionNegation();
        void fractionMultiply();
        void fractionInverse();
        void fractionDivide();
        void calculateUsingInteger();
        void calculateUsingString();
        void integerOrStringInput();

    private:
        int mNumeratorOne;
        int mNumeratorTwo;
        int mDenominatorOne;
        int mDenominatorTwo;
};

#endif