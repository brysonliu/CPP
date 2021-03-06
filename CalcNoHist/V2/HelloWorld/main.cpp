// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include "Fraction.h"
#include "Calculate.h"
#include "HelloWorld.h"

using namespace std;


string read_line(FILE *stream) 
{
	ostringstream line;
	char ch;
	while (1)
	{
		ch = fgetc(stream);
		if (ch == EOF)
		{
			return 0;
		}
		if (ch == '\n') 
		{
			break;
		}
		line << ch;
	}
	return line.str();
}

int main()
{
	Calculate c;
	//c.set_logging(true); 

	string line;
	while (line != "quit")
	{
		cout << "Enter an expression to evaluate.\n>";
		line = read_line(stdin);

		try 
		{
			Fraction result = c.evaluate(line);

			c.setVariable("prev", result);
			c.set_logging(c.getVariable("logging"));
			cout << "Result: prev = " << result << "\n\n";
		}
		catch (string e)
		{
			cout << "Error caught: " << e << endl;
		}
	}

	return 0;
}

