#include "fraction.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

string integerStringOption;
string fractionStringOne;
string arithmeticOperator;

FractionCalc::FractionCalc()
{
    cout << "Creating Fraction Object" << endl;
}

FractionCalc::~FractionCalc()
{
    cout << "Deleting Fraction Object" << endl;
}

// 
// integer calculation starts here
// 

void FractionCalc::fractionAdd()
{
   int firstNumeratorAdd = mNumeratorOne * mDenominatorTwo;
   int secondNumeratorAdd = mNumeratorTwo * mDenominatorOne;

   numeratorResultAdd =  firstNumeratorAdd + secondNumeratorAdd;
   denominatorResultAdd = mDenominatorOne * mDenominatorTwo;
   cout << "\nYour result: " << numeratorResultAdd << "/" << denominatorResultAdd << endl;
   if (numeratorResultAdd > denominatorResultAdd)
   {
	   fractionRoundingAdd(numeratorResultAdd, denominatorResultAdd);
   }
   else
   {
	   integerOrStringInput();
   }
};

void FractionCalc::fractionSubtract()
{
   int firstNumeratorSubtract = mNumeratorOne * mDenominatorTwo;
   int secondNumeratorSubtract = mNumeratorTwo * mDenominatorOne;

   numeratorResultSubtract =  secondNumeratorSubtract - firstNumeratorSubtract;
   denominatorResultSubtract = mDenominatorOne * mDenominatorTwo;
   cout << "\nYour result: " << numeratorResultSubtract << "/" << denominatorResultSubtract << endl;
   if (numeratorResultSubtract > denominatorResultSubtract)
   {
	   fractionRoundingSubtract(numeratorResultSubtract, denominatorResultSubtract);
   }
   else
   {
	   integerOrStringInput();
   }
};

void FractionCalc::fractionMultiply()
{
   int numeratorMultiply = mNumeratorOne * mNumeratorTwo;
   int denominatorResultMultiply = mDenominatorOne * mDenominatorTwo;

   cout << "\nYour result: " << numeratorMultiply << "/" << denominatorResultMultiply << endl;
   if (numeratorMultiply > denominatorResultMultiply)
   {
	   fractionRoundingMultiply(numeratorMultiply, denominatorResultMultiply);
   }
   else
   {
	   integerOrStringInput();
   }
};

void FractionCalc::fractionDivide()
{
	numeratorDivide = mNumeratorOne * mDenominatorTwo;
	denominatorDivide = mDenominatorOne * mNumeratorTwo;

	cout << "\nYour result: " << numeratorDivide << "/" << denominatorDivide << endl;
    if (numeratorMultiply > denominatorResultMultiply)
    {
		fractionRoundingDivide(numeratorDivide, denominatorDivide);
    }
    else
    {
		integerOrStringInput();
    }
};

//
// Fraction rounding code begins here
//

void FractionCalc::fractionRoundingAdd(int numeratorResultAdd, int denominatorResultAdd)
{
	int testWholeNumber = numeratorResultAdd / denominatorResultAdd;
	int mixedNumerator = numeratorResultAdd % denominatorResultAdd;
	// cout << fixed << showpoint << setprecision(0);
	cout << "Mixed Fraction Result: " << testWholeNumber << " " << mixedNumerator << "/" << denominatorResultAdd << endl;
	integerOrStringInput();
};

void FractionCalc::fractionRoundingSubtract(int numeratorResultSubtract, int denominatorResultSubtract)
{
	int testWholeNumber = numeratorResultSubtract / denominatorResultSubtract;
	int mixedNumerator = numeratorResultSubtract % denominatorResultSubtract;
	cout << "Mixed Fraction Result: " << testWholeNumber << " " << mixedNumerator << "/" << denominatorResultSubtract << endl;
	integerOrStringInput();
};

void FractionCalc::fractionRoundingMultiply(int numeratorMultiply, int denominatorResultMultiply)
{
	int testWholeNumber = numeratorMultiply / denominatorResultMultiply;
	int mixedNumerator = numeratorMultiply % denominatorResultMultiply;
	cout << "Mixed Fraction Result: " << testWholeNumber << " " << mixedNumerator << "/" << denominatorResultMultiply << endl;
	integerOrStringInput();
};

void FractionCalc::fractionRoundingDivide(int numeratorDivide, int denominatorDivide)
{
	int testWholeNumber = numeratorDivide / denominatorDivide;
	int mixedNumerator = numeratorDivide % denominatorDivide;
	cout << "Mixed Fraction Result: " << testWholeNumber << " " << mixedNumerator << "/" << denominatorDivide << endl;
	integerOrStringInput();
};

//
// Fraction rounding code ends here
//

void FractionCalc::fractionNegation()
{
    int negativeNumeratorOne = mNumeratorOne * -1;
    int negativeNumeratorTwo = mNumeratorTwo * -1;

    cout << negativeNumeratorOne << "/" << mDenominatorOne << endl;
    cout << negativeNumeratorTwo << "/" << mDenominatorTwo << endl;
	integerOrStringInput();
};

void FractionCalc::fractionInverse()
{
    int inverseFractionNumeratorOne = mNumeratorOne;
    int inverseFractionDenominatorOne = mDenominatorOne;
    int inverseFractionNumeratorTwo = mDenominatorTwo;
    int inverseFractionDenominatorTwo = mNumeratorTwo;

    cout << inverseFractionDenominatorOne << "/" << inverseFractionNumeratorOne << endl;
    cout << inverseFractionDenominatorTwo << "/" << inverseFractionDenominatorTwo << endl;
	integerOrStringInput();
};

// 
// integer calculation begins here
// 

void FractionCalc::calculateUsingInteger()
{
    cout << "\nEnter Numerator 1: ";
    cin >> mNumeratorOne;
    cout << "Enter Denominator 1: ";
    cin >> mDenominatorOne;
    cout << "\nEnter Numerator 2: ";
    cin >> mNumeratorTwo;
    cout << "Enter Denominator 2: ";
    cin >> mDenominatorTwo;
	cout << "Enter + to add,"
		 << "\n- to subtract,"
		 << "\n* to multiply,"
		 << "\n/ to divide,"
		 << "\ni to inverse fractions,"
		 << "\nor n to negate fractions: ";
	cin >> arithmeticOperator;

    cout << endl;
	
    cout << "Fraction 1: " << mNumeratorOne << "/" << mDenominatorOne << endl;
    cout << "Fraction 2: " << mNumeratorTwo << "/" << mDenominatorTwo << endl;

    cout << endl;

	if (arithmeticOperator == "+")
	{
		fractionAdd();
	}
	if (arithmeticOperator == "-")
	{
		fractionSubtract();
	}
	if (arithmeticOperator == "*")
	{
		fractionMultiply();
	}
	if (arithmeticOperator == "/")
	{
		fractionDivide();
	}
	if (arithmeticOperator == "i")
	{
		fractionInverse();
	}
	if (arithmeticOperator == "n")
	{
		fractionNegation();
	}
};

// 
// integer calculation ends here
// 

//
// string calculation begins here
//
void FractionCalc::calculateUsingString()
{
    cout << "Enter your fraction equation. Use two fractions: ";
    cin >> fractionStringOne;

    // read in a line of string such as 2/3+5/6 then 
    regex fractionResult("([[:w:]]+)[/]([[:w:]]+)([+|*|/]|[\-])([[:w:]]+)[/]([[:w:]])");
	smatch results;

	bool found = regex_search(fractionStringOne, results, fractionResult);
	
	// convert the the numbers in the string to integers
	mNumeratorOne = stoi(results[1].str());
	mNumeratorTwo = stoi(results[4].str());
	mDenominatorOne = stoi(results[2].str());
	mDenominatorTwo = stoi(results[5].str());

	if (results[3].str() == "+")
	{
		fractionAdd();
	}
	if (results[3].str() == "-")
	{
		fractionSubtract();
	}
	if (results[3].str() == "*")
	{
		fractionMultiply();
	}
	if (results[3].str() == "/")
	{
		fractionDivide();
	}

	/*
	cout << endl;
	cout << "String to Integer using stoi(): " << endl;
	cout << mNumeratorOne << endl;
	cout << mNumeratorTwo << endl;
	cout << mDenominatorOne << endl;
	cout << mDenominatorTwo << endl << endl;
	
	if (results[3].str() == "+")
	{
		cout << "You are using Addition" << endl << endl;
	}
	if (results[3].str() == "-")
	{
		cout << "You are using Subtraction" << endl << endl;
	}
	if (results[3].str() == "*")
	{
		cout << "You are using Multiplication" << endl << endl;
	}
	if (results[3].str() == "/")
	{
		cout << "You are using Division" << endl << endl;
	}
	*/
};

int FractionCalc::integerOrStringInput()
{
	cout << "\n(Type 'Integer' or 'String' to calculate."
		 << "\nType 'Exit' to exit the program.)" << endl;
    cout << "Input Fractions in Integer or String? ";
    cin >> integerStringOption;
    if (integerStringOption == "INTEGER" || integerStringOption == "integer" || integerStringOption == "Integer")
    {
        calculateUsingInteger();
    }
    if (integerStringOption == "STRING" || integerStringOption == "string" || integerStringOption == "String")
    {
        calculateUsingString();
    }
	if (integerStringOption == "EXIT" || integerStringOption == "exit" || integerStringOption == "Exit")
	{
		cout << endl;
		return 0;
	}
};