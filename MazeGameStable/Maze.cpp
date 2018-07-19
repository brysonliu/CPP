#include "Maze.hpp"

Maze::Maze()
{
    mHasntWon = true;
    mHitPoints = 100;
	mEnemySprite = '!';
}

Maze::~Maze()
{
	delete mPlayer;
	for (int e = 0; e < mEnemy.size(); e++)
	{
		delete mEnemy[e];
	}
}

void Maze::introduction()
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
			mMazeSize = 20;
			mEnemyCount = 5;
			break;
		case 2:
			mMazeSize = 30;
			mEnemyCount = 10;
			break;
		case 3:
			mMazeSize = 40;
			mEnemyCount = 15;
			break;
	}
}

void Maze::mazeTemplate()
{
	maze.resize(mMazeSize, vector<char>(mMazeSize, '#'));

	mMap = new Map(mMazeSize);
	mMap->create();
	for(int i = 0; i < mMazeSize; ++i)
	{
		for(int j = 0; j < mMazeSize; ++j)
		{
			maze[i][j] = mMap->getMap(i, j);
		}
    }

	delete mMap;
}

void Maze::displayMazeInitial()
{
	system("clear");

	cout << endl;
	for(int i = 0; i < mMazeSize; ++i)
	{
		for(int j = 0; j < mMazeSize; ++j)
		{
			cout << maze[i][j] << " ";
			usleep(5500);
			cout.flush();
		}

		cout << endl;
    }
}

void Maze::displayMazePlaying()
{
	system("clear");

	cout << endl;
	for(int i = 0; i < mMazeSize; ++i)
	{
		for(int j = 0; j < mMazeSize; ++j)
		{
			cout << maze[i][j] << " ";
		}

		cout << endl;
    }

	cout << endl << "HitPoints: " << mHitPoints << endl;
	cout << "Last User Input: ";
}

int Maze::endPoints()
{
	for (int x = 0; x < mMazeSize; x++)
	{
		for (int y = 0; y < mMazeSize; y++)
		{
			if (maze[x][y] == 'E')
			{
				mEndX = y;
				mEndY = x;
			}
		}
	}
}

char Maze::getch()
{
  system("stty raw");
  char input = getchar();
  system("stty cooked");
  return input;
}

void Maze::play()
{
	introduction();
	mazeTemplate();
	endPoints();
	
	mPlayer = new Player('@');

	mEnemy.resize(mEnemyCount);
	
	for (int e = 0; e < mEnemy.size(); e++)
	{
		mEnemy[e] = new Enemy(maze, mMazeSize, mEnemySprite);
	}
	
	displayMazeInitial();
	
	while (mHasntWon)
	{
		if (maze[mPlayer->y][mPlayer->x] == ' ' &&
			maze[mPlayer->y][mPlayer->x] != 'E' &&
			maze[mPlayer->y][mPlayer->x] != 'S')
		{
			maze[mPlayer->y][mPlayer->x] = mPlayer->sprite;
		}

		for (int e = 0; e < mEnemy.size(); e++)
		{
			maze[mEnemy[e]->y][mEnemy[e]->x] = mEnemy[e]->sprite;
		}
		
		displayMazePlaying();
		
		char key = getch();
		
		cout << endl;

		switch(key)
		{
			case 'a':
				if (maze[mPlayer->y][mPlayer->x - 1] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->x--;
					if (maze[mPlayer->y][mPlayer->x - 1] == mEnemySprite)
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 'w':
				if (maze[mPlayer->y - 1][mPlayer->x] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->y--;
					if (maze[mPlayer->y - 1][mPlayer->x] == mEnemySprite)
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 's':
				if (maze[mPlayer->y + 1][mPlayer->x] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->y++;
					if (maze[mPlayer->y + 1][mPlayer->x] == mEnemySprite)
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 'd':
				if (maze[mPlayer->y][mPlayer->x + 1] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->x++;
					if (maze[mPlayer->y][mPlayer->x + 1] == mEnemySprite)
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 'q':
				displayMazePlaying();
				cout << endl << endl << "Maze Run Terminated." << endl << endl;
				mHasntWon = false;
				exit(0);
				break;
		}

		for (int e = 0; e < mEnemy.size(); e++)
		{
			mEnemy[e]->resetMove();
		}
		
		for (int i = 0; i < mMazeSize; i++)
		{
			for (int j = 0; j < mMazeSize; j++)
			{
				for (int e = 0; e < mEnemy.size(); e++)
				{
					maze[i][j] = mEnemy[e]->move(maze, i, j);
				}
			}
		}

		for (int e = 0; e < mEnemy.size(); e++)
		{
			if (mPlayer->x == mEnemy[e]->x && mPlayer->y == mEnemy[e]->y)
			{
				mHitPoints = mHitPoints - 20;
			}
		}
		
		if (mHitPoints <= 0)
		{
			displayMazePlaying();
			cout << endl << endl << "YOU LOSE!" << endl << endl;
			mHasntWon = false;
		}

		if (mPlayer->x == mEndX && mPlayer->y == mEndY)
		{
			displayMazePlaying();
			cout << endl << endl << "YOU WIN!" << endl << endl;
			mHasntWon = false;
		}
	}
}