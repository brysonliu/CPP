#pragma once
#include <vector>
#include "stdafx.h"
#include "Fraction.h"
class RecentResults
{
	std::vector<Fraction> recentlist;
public:
	RecentResults();
	~RecentResults();
	int addResult(const Fraction &f);
	Fraction operator[](int i);
	int i;
	
};









/*  class RecentResults
{
public:
	RecentResults();
	~RecentResults();
	int addResult(const Fraction &f);
	Fraction operator[](int i);
};  */

