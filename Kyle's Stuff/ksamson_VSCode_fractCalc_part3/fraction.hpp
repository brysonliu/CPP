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
        void fractionMultiply();
		void fractionDivide();
        void fractionRoundingAdd(int numeratorResultAdd, int denominatorResultAdd);
        void fractionRoundingSubtract(int numeratorResultSubtract, int denominatorResultSubtract);
        void fractionRoundingMultiply(int numeratorMultiply, int denominatorResultMultiply);
        void fractionRoundingDivide(int numeratorDivide, int denominatorDivide);
        void fractionNegation();
        void fractionInverse();
        void calculateUsingInteger();
        void calculateUsingString();
        int integerOrStringInput();

        int numeratorResultAdd;
        int denominatorResultAdd;
        int numeratorResultSubtract;
        int denominatorResultSubtract;
        int numeratorMultiply;
        int denominatorResultMultiply;
	    int numeratorDivide;
	    int denominatorDivide;

    private:
        double mNumeratorOne;
        double mNumeratorTwo;
        double mDenominatorOne;
        double mDenominatorTwo;
};

#endif