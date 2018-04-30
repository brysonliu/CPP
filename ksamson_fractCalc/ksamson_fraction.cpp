#include "fraction.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

string integerStringOption;
string fractionStringOne;

FractionCalc::FractionCalc()
{
    cout << "Creating Fraction Object" << endl;
}

FractionCalc::~FractionCalc()
{
    cout << "Deleting Fraction Object" << endl;
}

void FractionCalc::fractionAdd()
{
   int firstNumeratorAdd = mNumeratorOne * mDenominatorTwo;
   int secondNumeratorAdd = mNumeratorTwo * mDenominatorOne;

   int numeratorResultAdd =  firstNumeratorAdd + secondNumeratorAdd;
   int denominatorResultAdd = mDenominatorOne * mDenominatorTwo;
   cout << numeratorResultAdd << "/" << denominatorResultAdd << endl;
};

void FractionCalc::fractionSubtract()
{
   int firstNumeratorSubtract = mNumeratorOne * mDenominatorTwo;
   int secondNumeratorSubtract = mNumeratorTwo * mDenominatorOne;

   int numeratorResultSubtract =  secondNumeratorSubtract - firstNumeratorSubtract;
   int denominatorResultSubtract = mDenominatorOne * mDenominatorTwo;
   cout << numeratorResultSubtract << "/" << denominatorResultSubtract << endl;
};

void FractionCalc::fractionNegation()
{
    int negativeNumeratorOne = mNumeratorOne * -1;
    int negativeNumeratorTwo = mNumeratorTwo * -1;

    cout << negativeNumeratorOne << "/" << mDenominatorOne << endl;
    cout << negativeNumeratorTwo << "/" << mDenominatorTwo << endl;
};

void FractionCalc::fractionMultiply()
{
   int numeratorMultiply = mNumeratorOne * mNumeratorTwo;
   int denominatorResultMultiply = mDenominatorOne * mDenominatorTwo;

   cout << numeratorMultiply << "/" << denominatorResultMultiply << endl;
};

void FractionCalc::fractionInverse()
{
    int inverseFractionNumeratorOne = mNumeratorOne;
    int inverseFractionDenominatorOne = mDenominatorOne;
    int inverseFractionNumeratorTwo = mDenominatorTwo;
    int inverseFractionDenominatorTwo = mNumeratorTwo;

    cout << inverseFractionDenominatorOne << "/" << inverseFractionNumeratorOne << endl;
    cout << inverseFractionDenominatorTwo << "/" << inverseFractionDenominatorTwo << endl;
};

void FractionCalc::fractionDivide()
{
    int numeratorDivide = mNumeratorOne * mDenominatorTwo;
    int denominatorDivide = mDenominatorOne * mNumeratorTwo;

    cout << numeratorDivide << "/" << denominatorDivide;
};

void FractionCalc::calculateUsingInteger()
{
    FractionCalc f;
    FractionCalc g;

    cout << "\nEnter Numerator 1: ";
    cin >> mNumeratorOne;
    cout << "Enter Denominator 1: ";
    cin >> mDenominatorOne;
    cout << "\nEnter Numerator 2: ";
    cin >> mNumeratorTwo;
    cout << "Enter Denominator 2: ";
    cin >> mDenominatorTwo;

    f.fraction[0] = mNumeratorOne; // Numerator 1
    f.fraction[1] = mDenominatorOne; // Denominator 1

    g.fraction[0] = mNumeratorTwo; // Numerator 2
    g.fraction[1] = mDenominatorTwo; // Denominator 2

    cout << endl;

    cout << "Fraction 1: " << f.fraction[0] << "/" << f.fraction[1] << endl;
    cout << "Fraction 2: " << g.fraction[0] << "/" << g.fraction[1] << endl;

    cout << endl;

    cout << "Addition: " << endl;
    fractionAdd();

    cout << "\nSubtraction: " << endl;
    fractionSubtract();

    cout << "\nMultiplication: " << endl;
    fractionMultiply();

    cout << "\nDivision: " << endl;
    fractionDivide();

    cout << "\n\nInverse:" << endl;
    fractionInverse();

    cout << "\nNegation:" << endl;
    fractionNegation();

    cout << endl;
};

void FractionCalc::calculateUsingString()
{
    cout << "Enter your fraction equation. Use two fractions: ";
    cin >> fractionStringOne;

    // read in a line of string such as 2/3+5/6 then convert the
    // the numbers in the string to integers
    regex fractionResult("(\d)[/](\d)([+|\-|*|/])(\d)[/](\d)");
    // int fractionStringToInteger = stoi(fractionStringOne);

    /*
    int stringNumeratorOne = stoi();
    int stringDenominatorOne = stoi();
    int stringNumeratorTwo = stoi();
    int stringDenominatorTwo = stoi();
    */

    cout << fractionStringOne << endl;

    /*
        Numerator 1: $1
        Denominator 1: $2
        Arithmetic Operator: $3
        Numerator 2: $4
        Denominator 2: $5
    */
    
    // assign each number in a group as the numerator or denominator
    // member variables, then do the following:
        // if the operator is addition, use fractionAdd(), then output
        // if the operator is subtraction, use fractionSubtract(), then output
        // if the operator is multiplication, use fractionMultiply(), then output
        // if the operator is division, use fractionDivide(), then output
    //cout << "\nAnswer: " << fractionStringOne << '=' << fractionStringToInteger << endl << endl;


     //int returnFractionResult = regex_search(fractionStringToInteger, fractionResult)
};

void FractionCalc::integerOrStringInput()
{
    cout << "Input Fractions in Integer or String? ";
    cin >> integerStringOption;
    if (integerStringOption == "Integer")
    {
        calculateUsingInteger();
    }
    if (integerStringOption == "String")
    {
        calculateUsingString();
    }
};