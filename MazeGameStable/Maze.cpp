#include "Maze.hpp"

Maze::Maze()
{
    mHasntWon = true;
    mHitPoints = 100;
}

Maze::~Maze()
{
	delete mPlayer;
	for (int e = 0; e < mEnemy.size(); e++)
	{
		delete mEnemy[e];
	}
}

void Maze::menu()
{
	mMenu = new Menu();
	
	mMenu->introduction();
	mMazeSize = mMenu->mazeSize;
	mEnemyCount = mMenu->enemyCount;
	mEnemySprite = mMenu->enemySprite;
	mEnemyRandom = mMenu->randomDifficulty;

	delete mMenu;
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

void Maze::endPoints()
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
	menu();
	mazeTemplate();
	endPoints();
	
	mPlayer = new Player('@');

	mEnemy.resize(mEnemyCount);
	
	for (int e = 0; e < mEnemy.size(); e++)
	{
		mEnemy[e] = new Enemy(maze, mMazeSize, mEnemySprite, mEnemyRandom);
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
					for (int e = 0; e < mEnemy.size(); e++)
					{
						if (maze[mPlayer->y][mPlayer->x - 1] == mEnemy[e]->sprite)
						{
							mHitPoints = mHitPoints - mEnemy[e]->damage;
							break;
						}
					}
				}
				break;
			case 'w':
				if (maze[mPlayer->y - 1][mPlayer->x] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->y--;
					for (int e = 0; e < mEnemy.size(); e++)
					{
						if (maze[mPlayer->y - 1][mPlayer->x] == mEnemy[e]->sprite)
						{
							mHitPoints = mHitPoints - mEnemy[e]->damage;
							break;
						}
					}
				}
				break;
			case 's':
				if (maze[mPlayer->y + 1][mPlayer->x] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->y++;
					for (int e = 0; e < mEnemy.size(); e++)
					{
						if (maze[mPlayer->y + 1][mPlayer->x] == mEnemy[e]->sprite)
						{
							mHitPoints = mHitPoints - mEnemy[e]->damage;
							break;
						}
					}
				}
				break;
			case 'd':
				if (maze[mPlayer->y][mPlayer->x + 1] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->x++;
					for (int e = 0; e < mEnemy.size(); e++)
					{
						if (maze[mPlayer->y][mPlayer->x + 1] == mEnemy[e]->sprite)
						{
							mHitPoints = mHitPoints - mEnemy[e]->damage;
							break;
						}
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
				mHitPoints = mHitPoints - mEnemy[e]->damage;
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