#include "stdafx.h"
#include "Calculate.h"
#include "Fraction.h"
#include <map>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

static const regex numberRX{ "^-?((\\d+ )?\\d+/\\d+|\\d+)" };
static const regex assignRX{ "^\\s*([a-zA-Z]+)\\s*=\\s*" };
static const regex variableRX{ "^\\s*([a-zA-Z]+)" };
static const regex subexprstartRX{ "^\\s*\\(\\s*" };
static const regex subexprendRX{ "^\\s*\\)\\s*" };
static const regex sumRX{ "^\\s*(\\+|-)\\s*" };
static const regex productRX{ "^\\s*(\\*|/)\\s*" };

Calculate::Calculate() 
{
	logging = false;
}

Calculate::~Calculate()
{
}

void Calculate::log(const char *message) const
{
	if (logging)
	{
		cout << "Calculate: " << message << "\n";
		cout << "  [" << inputLine.substr(0, parsePoint - inputLine.cbegin()) << "|" << inputLine.substr(parsePoint - inputLine.cbegin()) << "]\n";
	}
}

bool Calculate::matchAndConsume(const regex &re, smatch &match) 
{
	bool matched = regex_search(parsePoint, inputLine.cend(), match, re);
	if (matched)
	{
		parsePoint += match[0].length();
	}
	return matched;
}

Fraction Calculate::evaluate(const std::string &expr) 
{
	inputLine = expr;
	parsePoint = inputLine.begin();

	return parseExpr();
}

bool Calculate::tryEvaluate(const std::string &expr, Fraction &result)
{
	try {
		result = evaluate(expr);
		return true;
	}
	catch (char *e) {
		if (logging) cout << "ERROR: " << e << endl;
		return false;
	}
}

Fraction Calculate::parseExpr() 
{
	log("Begin evaluate");
	smatch match;
	bool isAssignment = matchAndConsume(assignRX, match);
	if (isAssignment) log("We have an assignment, continuing.");
	Fraction result = parseSum();
	log("After parseSum");
	if (isAssignment) 
	{
		variables[match[1].str()] = result;
		if (logging) 
		{
			cout << "Assigning to: " << match[1].str() << " value: " << result << "\n";
		}
	}
	return result;
}

Fraction Calculate::parseSum() 
{
	log("about to parseSum");
	Fraction result = parseProduct();
	smatch op;
	while (matchAndConsume(sumRX, op)) 
	{
		log("found an add/sub op");
		Fraction secondProduct = parseProduct();
		if (op[1].str() == "+")
			result = result + secondProduct;
		if (op[1].str() == "-")
			result = result - secondProduct;
	}
	return result;
}

Fraction Calculate::parseProduct() 
{
	log("about to parseProduct");
	Fraction result = parseTerm();
	smatch op;
	while (matchAndConsume(productRX, op)) 
	{
		log("Found a mult/div op");
		Fraction secondProduct = parseProduct();
		if (op[1].str() == "*")
			result = result * secondProduct;
		if (op[1].str() == "/")
			result = result / secondProduct;
	}
	return result;
}

Fraction Calculate::parseTerm() 
{
	log("about to parseTerm");
	smatch match;
	if (matchAndConsume(numberRX, match))
		return Fraction{ match[0].str() };
	if (matchAndConsume(variableRX, match))
		return variables[match[0].str()];
	if (matchAndConsume(subexprstartRX, match))
	{
		Fraction result = parseSum();
		if (!matchAndConsume(subexprendRX, match))
			throw string{ "Expected close paren ')'." };
		return result;
	}

	throw string{ "Cannot parse input." };
}

