#include "Maze.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;

Maze::Maze()
{
    mHasntWon = true;
    mHitPoints = 100;
}

Maze::~Maze()
{
	delete mPlayer;
	delete mEnemy1;
	delete mEnemy2;
	delete mEnemy3;
	delete mEnemy4;
	delete mEnemy5;

	if (mMazeSize >= 30)
	{
		delete mEnemy6;
		delete mEnemy7;
	}

	if (mMazeSize >= 40)
	{
		delete mEnemy8;
		delete mEnemy9;
	}
}

void Maze::introduction()
{
	system("clear");
	
	int size;

	cout << endl;
	cout << "WELCOME TO THE MAZE! \n \n" <<
			"Your goal is to get your sprite (@) from the start of the maze (marked by an S) \n" <<
			"to the end of the maze (marked by an E) while avoiding enemies (marked by Xs). \n" <<
			"Enemies will deal 20 damage to your sprite upon contact. If it loses all 100 hit points, \n" <<
			"you shall lose! Good luck!" << endl << endl;
	cout << "What level of challenge are you feeling up to?" << endl;
	cout << "1: Small Maze \n" <<
			"2: Medium Maze \n" <<
			"3: Large Maze \n" << endl;
	cout << "Enter number of choice here: ";
	cin >> size;
	
	while(size < 1 || size > 3)
	{
		cout << "Please enter only the number of one of the three available choices: ";
		cin >> size;
	}
	
	switch(size)
	{
		case 1:
			mMazeSize = 20;
			break;
		case 2:
			mMazeSize = 30;
			break;
		case 3:
			mMazeSize = 40;
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

void Maze::displayMaze()
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
	
	mPlayer = new Player('@');
	
	mEnemy1 = new Enemy(maze, mMazeSize, 'X');
	mEnemy2 = new Enemy(maze, mMazeSize, 'X');
	mEnemy3 = new Enemy(maze, mMazeSize, 'X');
	mEnemy4 = new Enemy(maze, mMazeSize, 'X');
	mEnemy5 = new Enemy(maze, mMazeSize, 'X');
	if (mMazeSize >= 30)
	{
		mEnemy6 = new Enemy(maze, mMazeSize, 'X');
		mEnemy7 = new Enemy(maze, mMazeSize, 'X');
	}
	if (mMazeSize >= 40)
	{
		mEnemy8 = new Enemy(maze, mMazeSize, 'X');
		mEnemy9 = new Enemy(maze, mMazeSize, 'X');
	}

	string prevmove1 = "NA";
	string prevmove2 = "NA";
	string prevmove3 = "NA";
	string prevmove4 = "NA";
	string prevmove5 = "NA";
	string prevmove6 = "NA";
	string prevmove7 = "NA";
	string prevmove8 = "NA";
	string prevmove9 = "NA";

	displayMaze();

	while (mHasntWon)
	{
		system("clear");

		if (maze[mPlayer->y][mPlayer->x] == ' ')
		{
			maze[mPlayer->y][mPlayer->x] = mPlayer->sprite;
		}

		maze[mEnemy1->y][mEnemy1->x] = mEnemy1->sprite;
		maze[mEnemy2->y][mEnemy2->x] = mEnemy2->sprite;
		maze[mEnemy3->y][mEnemy3->x] = mEnemy3->sprite;
		maze[mEnemy4->y][mEnemy4->x] = mEnemy4->sprite;
		maze[mEnemy5->y][mEnemy5->x] = mEnemy5->sprite;
		if (mMazeSize >= 30)
		{
			maze[mEnemy6->y][mEnemy6->x] = mEnemy6->sprite;
			maze[mEnemy7->y][mEnemy7->x] = mEnemy7->sprite;
		}
		if (mMazeSize >= 40)
		{
			maze[mEnemy8->y][mEnemy8->x] = mEnemy8->sprite;
			maze[mEnemy9->y][mEnemy9->x] = mEnemy9->sprite;
		}

		for (int y = 0; y < mMazeSize; y++)
		{
			cout << endl;
			for (int x = 0; x < mMazeSize; x++)
			{
				cout << maze[y][x] << " ";
			}
		}
		
		cout << endl << "HitPoints: " << mHitPoints << endl;
		cout << "Last User Input: ";

		char key = getch();
		
		cout << endl;

		switch(key)
		{
			case 'a':
				if (maze[mPlayer->y][mPlayer->x - 1] != '#')
				{
					maze[mPlayer->y][mPlayer->x] = ' ';
					mPlayer->x--;
					if (maze[mPlayer->y][mPlayer->x - 1] == 'X')
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
					if (maze[mPlayer->y - 1][mPlayer->x] == 'X')
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
					if (maze[mPlayer->y + 1][mPlayer->x] == 'X')
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
					if (maze[mPlayer->y][mPlayer->x + 1] == 'X')
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 'q':
				cout << endl << "Maze Run Terminated." << endl << endl;
				exit(0);
				break;
		}
		
		bool once1 = true;
		bool once2 = true;
		bool once3 = true;
		bool once4 = true;
		bool once5 = true;
		bool once6 = true;
		bool once7 = true;
		bool once8 = true;
		bool once9 = true;

		for (int i = 0; i < mMazeSize; i++)
		{
			for (int j = 0; j < mMazeSize; j++)
			{
				maze[i][j] = mEnemy1->move(maze, i, j, prevmove1, once1);
				maze[i][j] = mEnemy2->move(maze, i, j, prevmove2, once2);
				maze[i][j] = mEnemy3->move(maze, i, j, prevmove3, once3);
				maze[i][j] = mEnemy4->move(maze, i, j, prevmove4, once4);
				maze[i][j] = mEnemy5->move(maze, i, j, prevmove5, once5);
				if (mMazeSize >= 30)
				{
					maze[i][j] = mEnemy6->move(maze, i, j, prevmove6, once6);
					maze[i][j] = mEnemy7->move(maze, i, j, prevmove7, once7);
				}
				if (mMazeSize >= 40)
				{
					maze[i][j] = mEnemy8->move(maze, i, j, prevmove8, once8);
					maze[i][j] = mEnemy9->move(maze, i, j, prevmove9, once9);
				}
			}
		}

		if (mPlayer->x == mEnemy1->x && mPlayer->y == mEnemy1->y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (mPlayer->x == mEnemy2->x && mPlayer->y == mEnemy2->y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (mPlayer->x == mEnemy3->x && mPlayer->y == mEnemy3->y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (mPlayer->x == mEnemy4->x && mPlayer->y == mEnemy4->y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (mPlayer->x == mEnemy5->x && mPlayer->y == mEnemy5->y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (mMazeSize >= 30)
		{
			if (mPlayer->x == mEnemy6->x && mPlayer->y == mEnemy6->y)
			{
				mHitPoints = mHitPoints - 20;
			}
			if (mPlayer->x == mEnemy7->x && mPlayer->y == mEnemy7->y)
			{
				mHitPoints = mHitPoints - 20;
			}
		}
		if (mMazeSize >= 40)
		{
			if (mPlayer->x == mEnemy8->x && mPlayer->y == mEnemy8->y)
			{
				mHitPoints = mHitPoints - 20;
			}
			if (mPlayer->x == mEnemy9->x && mPlayer->y == mEnemy9->y)
			{
				mHitPoints = mHitPoints - 20;
			}
		}

		if (mHitPoints <= 0)
		{
			cout << endl << "YOU LOSE!" << endl << endl;
			mHasntWon = false;
		}

		if (maze[mPlayer->x + 1][mPlayer->y] == 'E' || maze[mPlayer->x][mPlayer->y + 1] == 'E')
		{
			cout << endl << "YOU WIN!" << endl << endl;
			mHasntWon = false;
		}
	}
}