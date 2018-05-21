#include "stdafx.h"
#include "Fraction.h"
#include "HelloWorld.h"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

static int match_to_i(ssub_match m)
{
	if (m.matched)
		return atoi(m.str().c_str());
	else
		return 0;
}

Fraction::Fraction(string description) 
{
	regex rx{ "^(-)?(((\\d+) )?(\\d+)/(\\d+)|(\\d+))$" };
	smatch results;
	if (!regex_match(description, results, rx)) 
	{
		throw string{ "string not parsable as a Fraction: " + description };
	}
	if (results[7].matched)
	{
		this->numerator = match_to_i(results[7]);
		this->denominator = 1;
	}
	else 
	{
		int whole = match_to_i(results[4]);
		int numerator = match_to_i(results[5]);
		int denominator = match_to_i(results[6]);

		if (!denominator) throw string{ "Divide by zero error!" };
		this->numerator = numerator + whole * denominator;
		this->denominator = denominator;
	}
	if (results[1].matched)
	{
		this->numerator *= -1;
	}
	//cout << "Successfully parsed fraction:" << *this << "\n";
}

Fraction Fraction::operator=(const Fraction &o)
{
	numerator = o.numerator;
	denominator = o.denominator;
	return *this;
}

bool Fraction::operator==(const Fraction &o) const
{
	return numerator == o.numerator && denominator == o.denominator;
}

Fraction::operator double() const
{
	return (double)numerator / denominator;
}

Fraction Fraction::operator +(const Fraction &o) const
{
	return Fraction{ numerator * o.denominator + denominator * o.numerator, denominator * o.denominator }.normalized();
}

Fraction Fraction::operator -(const Fraction &o) const
{
	return *this + -o;
}

Fraction Fraction::operator -() const 
{
	return Fraction{ -numerator, denominator };
}

Fraction Fraction::operator *(const Fraction &o) const
{
	return Fraction{ numerator * o.numerator, denominator * o.denominator }.normalized();
}

Fraction Fraction::operator /(const Fraction &o) const
{
	return *this * o.inverted();
}

Fraction Fraction::inverted() const
{
	return Fraction{ denominator, numerator };
}

Fraction Fraction::roundedTo(const Fraction &o) const
{
	double scaledNumerator = (double)(numerator * o.denominator) / (double)(denominator * o.numerator);
	return Fraction{ lround(scaledNumerator) * o.numerator, o.denominator };
}

Fraction Fraction::normalized() const 
{
	long a = abs(numerator), b = denominator;
	while (a != b) 
	{
		if (a < b) 
		{
			b -= a;
		}
		if (b < a)
		{
			a -= b;
		}
	}
	if (1 < a)
	{
		return Fraction{ numerator / a, denominator / b };
	}
	return *this;
}

ostream &operator<<(ostream &cout, const Fraction &f) 
{
	long posNumerator = abs(f.numerator);
	if (f.numerator == 0) 
	{
		cout << '0';
		return cout;
	}
	if (f.numerator < 0)
	{
		cout << '-';
	}
	if (posNumerator >= f.denominator)
	{
		cout << (posNumerator / f.denominator);
	}
	if (posNumerator > f.denominator && posNumerator % f.denominator)
	{
		cout << ' ';
	}
	if (posNumerator % f.denominator)
	{
		cout << (posNumerator % f.denominator) << '/' << f.denominator;
	}
	return cout;
}