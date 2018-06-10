#pragma once
class RecentResults
{
	
public:
	RecentResults();
	~RecentResults();
	int addResult(const Fraction &f);
	Fraction operator[](int i);
	
};









/*  class RecentResults
{
public:
	RecentResults();
	~RecentResults();
	int addResult(const Fraction &f);
	Fraction operator[](int i);
};  */

