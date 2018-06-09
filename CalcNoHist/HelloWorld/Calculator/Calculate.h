#pragma once
#include "Fraction.h"
#include <string>
#include <map>
#include <regex>

class Calculate
{
	std::map<std::string, Fraction> variables;
	std::string inputLine;
	std::string::const_iterator parsePoint;

	bool logging;

	void log(const char *message) const;
	bool matchAndConsume(const std::regex &, std::smatch &);
	Fraction parseExpr();
	Fraction parseSum();
	Fraction parseProduct();
	Fraction parseTerm();

public:
	Calculate();
	~Calculate();

	void set_logging(bool l) { logging = l; }

	Fraction evaluate(const std::string &);
	bool tryEvaluate(const std::string &, Fraction &);

	Fraction getVariable(const std::string &name) { return variables[name]; }
	void setVariable(const std::string &name, const Fraction &val) { variables[name] = val; }
};

