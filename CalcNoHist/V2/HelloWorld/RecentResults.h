#pragma once
#include <vector>
#include "stdafx.h"
#include "Fraction.h"
class RecentResults
{
	std::vector<Fraction> recentList;
public:
	RecentResults();
	
	int addResult(const Fraction &f);
	Fraction operator[](int i);
	
	
};
