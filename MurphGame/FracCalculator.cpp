#include "stdafx.h"
#include "fraction.h"
#include <iostream>
#include <iomanip>
#include <regex>

using namespace std;


class Fraction
{
private:
	int whole;
	int num;
	int den;
	char dummychar; //A throwaway variable to hold the “/” character
public:
	void getFrac() //Method for obtaining the fraction 
	{
		cout << "Enter whole number : \n";
		cin >> whole;
		cout << "Enter a fraction : e.g. 3/4, or 9/16 \n";
		cin >> num >> dummychar >> den;




	}
	Fraction addFraction(Fraction f3) //Method for adding two fractions
	{
		f3.whole = (f3.whole + whole);
		f3.num = ((num * f3.den) + (den * f3.num));
		f3.den = (den * f3.den);
		return f3;
	}
	Fraction subFraction(Fraction f4) //Method for subtracting two fractions
	{
		f4.whole = (whole - f4.whole);
		f4.num = ((num * f4.den) –(den * f4.num));
		f4.den = (den * f4.den);
		return f4;
	}
	Fraction mulFraction(Fraction f5) //Method for multiplying two fractions
	{
		f5.whole = (whole * f5.whole);
		f5.num = (num * f5.num);
		f5.den = (den * f5.den);
		return f5;
	}
	Fraction divFraction(Fraction f6) //Method for dividing two fractions
	{
		f6.whole = (whole / f6.whole);
		f6.num = (num * f6.den);
		f6.den = (den * f6.num);
		return f6;
	}
	void Fraction::lowterms() //Method for reducing the fractions
	{
		long whole, tnum, tden, temp, gcd; // GCD = greatest common divisor
		tnum = labs(num);
		tden = labs(den);
		if (tden == 0)
		{
			cout << "Illegal fraction : Division by 0";
			exit(1);
		}
		else if (tnum == 0)
		{
			num = 0; den = 1; return;
		}

		while (tnum != 0)
		{
			if (tnum < tden)
			{

				temp = tnum; tnum = tden; tden = temp;
			}
			if (tnum > tden)
			{
				whole = (whole + (tnum % tden)); // check this later.
				temp = tnum; tnum = tden; tden = temp;
			}

			tnum = (tnum – tden);
		}
		gcd = tden;
		num = num / gcd;
		den = den / gcd;
	}
	void showFrac() const //Method for displaying the results
	{
		cout << "The result is " << whole << " " << num << " / " << den << endl;
	}
};

int main()
{
	Fraction f1, f2, f3, f4, f5, f6;

	cout << "The results displayed will be the sum, difference, product and quotient.\n " << endl;
	f1.getFrac();
	f2.getFrac();
	f3 = f1.addFraction(f2); //Adds the two fractions
	f3.lowterms(); //Takes the result and reduces it
	f3.showFrac();
	f4 = f1.subFraction(f2); //Subtracts the two fractions
	f4.lowterms(); //Takes the result and reduces it
	f4.showFrac();
	f5 = f1.mulFraction(f2); //Multiplies the two fractions
	f5.lowterms(); //Takes the result and reduces it
	f5.showFrac();
	f6 = f1.divFraction(f2); //Divides the two fractions
	f6.lowterms(); //Takes the result and reduces it
	f6.showFrac();

	return 0;
}
