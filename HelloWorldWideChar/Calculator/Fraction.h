#pragma once
#include <string>

class Fraction {
	long numerator;
	long denominator;

public:
	Fraction(long numerator = 0, long denominator = 1)
		: numerator{ numerator }, denominator{ denominator } {
		if (!denominator) throw std::string{ "Divide by zero error!" };
	}
	Fraction(const Fraction &o) : numerator{ o.numerator }, denominator{ o.denominator } {}
	Fraction(std::string description);

	Fraction operator=(const Fraction &o);
	bool operator==(const Fraction &o) const;
	operator double() const;

	Fraction operator+(const Fraction &o) const;
	Fraction operator-(const Fraction &o) const;
	Fraction operator-() const;
	Fraction operator*(const Fraction &o) const;
	Fraction operator/(const Fraction &o) const;

	Fraction inverted() const;
	Fraction roundedTo(const Fraction &o) const;

private:
	Fraction normalized() const;
	friend std::ostream &operator<<(std::ostream &cout, const Fraction &f);
};

