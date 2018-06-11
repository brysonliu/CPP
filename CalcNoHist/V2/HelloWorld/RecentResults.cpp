
#include <vector>
#include "stdafx.h"
#include "RecentResults.h"
#include "Fraction.h"
#include "Calculate.h"

RecentResults::RecentResults() : recentList{}
{

}


int RecentResults::addResult(const Fraction & f)
{
	recentList.push_back(f);
	return recentList.size() - 1;
}

Fraction RecentResults::operator[](int i)
{
	return recentList[i] ;
}