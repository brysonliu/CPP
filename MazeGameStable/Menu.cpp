#include "Menu.hpp"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::introduction()
{
    system("clear");
	
	int size;

	cout << endl;
	cout << "WELCOME TO THE MAZE! \n \n" <<
			"Your goal is to get your sprite (@) from the start of the maze (marked by an \"S\") \n" <<
			"to the end of the maze (marked by an \"E\") while avoiding enemies (marked by \"!\"s). \n" <<
			"Enemies will deal 20 damage to your sprite upon contact. If it loses all 100 hit points, \n" <<
			"you shall lose! Good luck!" << endl << endl;
	cout << "Controls: W - Up \n" <<
			"          A - Left \n" <<
			"          S - Down \n" <<
			"          D - Right \n" <<
			"          Q - (QUIT) \n" << endl;
	cout << "What level of challenge are you feeling up to?" << endl;
	cout << "1: Small Maze \n" <<
			"2: Medium Maze \n" <<
			"3: Large Maze \n" <<
			"4: Exit \n" << endl;
	cout << "Enter number of choice here: ";
	
	while(true)
	{
		cin >> size;

		if (size >= 1 && size <= 3)
		{
			break;
		}
		else if (size == 4)
		{
			cout << endl;
			exit(0);
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter only the number of one of the three available choices: ";
		}
	}
	
	switch(size)
	{
		case 1:
			mazeSize = 20;
			enemyCount = 5;
			break;
		case 2:
			mazeSize = 30;
			enemyCount = 10;
			break;
		case 3:
			mazeSize = 40;
			enemyCount = 15;
			break;
	}
}