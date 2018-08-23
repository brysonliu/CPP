#include "Menu.hpp"

Menu::Menu()
{
	randomDifficulty = false;
}

Menu::~Menu()
{

}

void Menu::introduction()
{
    system("clear");
    
    cout << endl;
	cout << "WELCOME TO THE MAZE! \n \n" <<
			"Your goal is to get your sprite (@) from the start of the maze (S) \n" <<
			"to the end of the maze (E) while avoiding enemies (&, %, !). \n" <<
			"Enemies will deal 20 damage to your sprite upon contact. If it loses \n" <<
            "all 100 hit points, you shall lose! Good luck!" << endl << endl;
	cout << "Controls: W - Up \n" <<
			"          A - Left \n" <<
			"          S - Down \n" <<
			"          D - Right \n" <<
			"          Q - (QUIT) \n" << endl;
	
    do
    {
        cout << "Press ENTER to continue . . . \n";
    } while (cin.get() != '\n');

    sizeMenu();
}

void Menu::sizeMenu()
{
    system("clear");

    int size;

    cout << "How adventurous are you feeling? \n" << endl;
	cout << "1: Small Maze \n" <<
			"2: Medium Maze \n" <<
			"3: Large Maze \n" <<
			"4: EXIT \n" << endl;
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

	difficultyMenu();
}

void Menu::difficultyMenu()
{
	system("clear");

    int difficulty;

    cout << "What level of challenge are you looing for? \n" << endl;
	cout << "1: Easy Enemies        (&) - 10 Damage \n" <<
			"2: Moderate Enemies    (%) - 20 Damage \n" <<
			"3: Difficult Enemies   (!) - 25 Damage \n" <<
			"4: Random Enemies \n" <<
			"5: EXIT \n" << endl;
	cout << "Enter number of choice here: ";
	
	while(true)
	{
		cin >> difficulty;

		if (difficulty >= 1 && difficulty <= 3)
		{
			break;
		}
		else if (difficulty == 4)
		{
			randomDifficulty = true;
			break;
		}
		else if (difficulty == 5)
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
	
	switch(difficulty)
	{
		case 1:
			enemySprite = '&';
			break;
		case 2:
			enemySprite = '%';
			break;
		case 3:
			enemySprite = '!';
			break;
	}
}