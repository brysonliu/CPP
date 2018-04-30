#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
	int numerator1;
	int numerator2;
	int denominator1;
	int denominator2;

    while (true)
    {
        cin >> str;
        smatch m;

		regex e("([[:w:]]+)[/]([[:w:]]+)([+|*|/]|[\-])([[:w:]]+)[/]([[:w:]])");

        bool found = regex_search(str, m, e);

        cout << "m.size() " << m.size() << endl;

        for (int n = 0; n < m.size(); n++)
        {
            cout << "m[" << n << "]: str()=" << m[n].str() << endl;
        }

		numerator1 = stoi(m[1].str());
		numerator2 = stoi(m[2].str());
		denominator1 = stoi(m[4].str());
		denominator2 = stoi(m[5].str());
	
		cout << endl;
		cout << "String to Integer using stoi(): " << endl;
		cout << numerator1 << endl;
		cout << numerator2 << endl;
		cout << denominator1 << endl;
		cout << denominator2 << endl << endl;

		if (m[3].str() == "+")
		{
			cout << "You are using Addition" << endl << endl;
		}
		if (m[3].str() == "-")
		{
			cout << "You are using Subtraction" << endl << endl;
		}
		if (m[3].str() == "*")
		{
			cout << "You are using Multiplication" << endl << endl;
		}
		if (m[3].str() == "/")
		{
			cout << "You are using Division" << endl << endl;
		}
    }
}