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
	
}

void Maze::introduction()
{
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

Player Maze::createPlayer(char sprite)
{
	Player newPlayer;
	newPlayer.sprite = sprite;
	newPlayer.x = 1;
	newPlayer.y = 0;

	while (maze[newPlayer.y][newPlayer.x] != 'S')
	{
		newPlayer.y++;
	}

	return newPlayer;
}

Enemy Maze::createEnemy(char sprite)
{
	Enemy newEnemy;
	newEnemy.sprite = sprite;
	newEnemy.x = rand() % mMazeSize;
	newEnemy.y = rand() % mMazeSize;
	newEnemy.pastDirX = Left;
	newEnemy.pastDirY = Up;

	while (maze[newEnemy.y][newEnemy.x] != ' ')
	{
		newEnemy.x = rand() % mMazeSize;
		newEnemy.y = rand() % mMazeSize;
	}

	if (maze[newEnemy.y][newEnemy.x] == ' ')
	{
		maze[newEnemy.y][newEnemy.x] = newEnemy.sprite;
	}

	return newEnemy;
}

//enemy movement algorithm
char Maze::MoveEnemy(Enemy& enemy, vector< vector<char> >& maze, int i, int j, string& smove, bool& nc)
{
	if (nc)
	{
		bool goUp = false;
		//possible directions
		bool psbUp = false;
		bool psbDown = false;
		bool psbRight = false;
		bool psbLeft = false;

		//check possible directions
		if (maze[enemy.y][enemy.x + 1] != '#' && maze[enemy.y][enemy.x + 1] != 'E') //RIGHT
		{
			psbRight = true;
		}
		if (maze[enemy.y][enemy.x - 1] != '#' && maze[enemy.y][enemy.x - 1] != 'E') //LEFT
		{
			psbLeft = true;
		}
		if (maze[enemy.y + 1][enemy.x] != '#' && maze[enemy.y + 1][enemy.x] != 'E') //DOWN
		{
			psbDown = true;
		}
		if (maze[enemy.y - 1][enemy.x] != '#' && maze[enemy.y - 1][enemy.x] != 'E') //UP
		{
			psbUp = true;
		}

		//movement tracking
		enum Mv { up, right, down, left, NA };
		Mv move = NA;

		//previous movement
		if (smove == "up")
		{
			move = up;
		}
		else if (smove == "right")
		{
			move = right;
		}
		else if (smove == "down")
		{
			move = down;
		}
		else if (smove == "left")
		{
			move = left;
		}
		else
		{
			move = NA;
		}

		//prevent repetitive enemy movement
		if (enemy.pastDirX == Right && !psbRight)
		{
			if (enemy.pastDirY == Up) //if past move was up
			{
				if (psbUp) //check possible up
				{
					move = up;
				}
				else if (psbDown && move != up) //check possible down
				{
					move = down;
				}
				else if (psbLeft) //check possible left
				{
					move = left;
				}
				else //move down if down and left fail
				{
					move = down;
				}
			}

			else //if past movement down
			{
				if (psbDown) //check possible down
				{
					move = down;
				}
				else if (psbUp && move != down) //check possible up
				{
					move = up;
				}
				else if (psbLeft) //check possible left
				{
					move = left;
				}
				else //move up if all checks fail
				{
					move = up;
				}
			}
		}

		else if (enemy.pastDirX == Right && psbRight)
		{
			move = right;
		}

		else if (enemy.pastDirX == Left && !psbLeft)
		{
			if (enemy.pastDirY == Up)
			{
				if (psbUp)
				{
					move = up;
				}
				else if (psbDown && move != up)
				{
					move = down;
				}
				else if (psbRight)
				{
					move = right;
				}
				else
				{
					move = down;
				}
			}

			else
			{
				if (psbDown)
				{
					move = down;
				}
				else if (psbUp && move != down)
				{
					move = up;
				}
				else if (psbRight)
				{
					move = right;
				}
				else
				{
					move = up;
				}
			}
		}

		else if (enemy.pastDirX == Left && psbLeft)
		{
			move = left;
		}

		else if (enemy.pastDirY == Up && !psbUp)
		{
			if (enemy.pastDirX == Right)
			{
				if (psbRight)
				{
					move = right;
				}
				else if (psbLeft && move != right)
				{
					move = left;
				}
				else if (psbDown)
				{
					move = down;
				}
				else
				{
					move = left;
				}
			}

			else
			{
				if (psbLeft)
				{
					move = left;
				}
				else if (psbRight && move != left)
				{
					move = right;
				}
				else if (psbDown)
				{
					move = down;
				}
				else
				{
					move = right;
				}
			}
		}

		else if (enemy.pastDirY == Up && psbUp)
		{
			move = up;
		}

		else if (enemy.pastDirY == Down && !psbDown)
		{
			if (enemy.pastDirX == Right)
			{
				if (psbRight)
				{
					move = right;
				}
				else if (psbLeft && move != right)
				{
					move = left;
				}
				else if (psbUp)
				{
					move = up;
				}
				else
				{
					move = left;
				}
			}

			else
			{
				if (psbLeft)
				{
					move = left;
				}
				else if (psbRight && move != left)
				{
					move = right;
				}
				else if (psbRight)
				{
					move = up;
				}
				else
				{
					move = right;
				}
			}
		}

		else if (enemy.pastDirY == Down && psbDown)
		{
			move = down;
		}

		switch (move) {
		case up:
			maze[enemy.y][enemy.x] = ' ';
			enemy.pastDirY = Up;
			smove = "up";
			enemy.y--;
			break;
		case right:
			maze[enemy.y][enemy.x] = ' ';
			enemy.pastDirX = Right;
			smove = "right";
			enemy.x++;
			break;
		case down:
			maze[enemy.y][enemy.x] = ' ';
			enemy.pastDirY = Down;
			smove = "down";
			enemy.y++;
			break;
		case left:
			maze[enemy.y][enemy.x] = ' ';
			enemy.pastDirX = Left;
			smove = "left";
			enemy.x--;
			break;
		case NA:
			smove = "NA";
			break;
		}
	}
	nc = false;
	return maze[i][j];
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
	
	Player player = createPlayer('@');
	
	Enemy enemy1 = createEnemy('X');
	Enemy enemy2 = createEnemy('X');
	Enemy enemy3 = createEnemy('X');
	Enemy enemy4 = createEnemy('X');
	Enemy enemy5 = createEnemy('X');

	string prevmove1 = "NA";
	string prevmove2 = "NA";
	string prevmove3 = "NA";
	string prevmove4 = "NA";
	string prevmove5 = "NA";

	displayMaze();

	while (mHasntWon)
	{
		system("clear");

		if (maze[player.y][player.x] == ' ')
		{
			maze[player.y][player.x] = player.sprite;
		}

		maze[enemy1.y][enemy1.x] = enemy1.sprite;
		maze[enemy2.y][enemy2.x] = enemy2.sprite;
		maze[enemy3.y][enemy3.x] = enemy3.sprite;
		maze[enemy4.y][enemy4.x] = enemy4.sprite;
		maze[enemy5.y][enemy5.x] = enemy5.sprite;

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
				if (maze[player.y][player.x - 1] != '#')
				{
					maze[player.y][player.x] = ' ';
					player.x--;
					if (maze[player.y][player.x - 1] == 'X')
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 'w':
				if (maze[player.y - 1][player.x] != '#')
				{
					maze[player.y][player.x] = ' ';
					player.y--;
					if (maze[player.y - 1][player.x] == 'X')
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 's':
				if (maze[player.y + 1][player.x] != '#')
				{
					maze[player.y][player.x] = ' ';
					player.y++;
					if (maze[player.y + 1][player.x] == 'X')
					{
						mHitPoints = mHitPoints - 20;
					}
				}
				break;
			case 'd':
				if (maze[player.y][player.x + 1] != '#')
				{
					maze[player.y][player.x] = ' ';
					player.x++;
					if (maze[player.y][player.x + 1] == 'X')
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

		//int x = newEnemy.x;
		//int y = newEnemy.y;
		bool once1 = true;
		bool once2 = true;
		bool once3 = true;
		bool once4 = true;
		bool once5 = true;

		for (int i = 0; i < mMazeSize; i++)
		{
			for (int j = 0; j < mMazeSize; j++)
			{
				maze[i][j] = MoveEnemy(enemy1, maze, i, j, prevmove1, once1);
				maze[i][j] = MoveEnemy(enemy2, maze, i, j, prevmove2, once2);
				maze[i][j] = MoveEnemy(enemy3, maze, i, j, prevmove3, once3);
				maze[i][j] = MoveEnemy(enemy4, maze, i, j, prevmove4, once4);
				maze[i][j] = MoveEnemy(enemy5, maze, i, j, prevmove5, once5);
			}
		}

		if (player.x == enemy1.x && player.y == enemy1.y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (player.x == enemy2.x && player.y == enemy2.y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (player.x == enemy3.x && player.y == enemy3.y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (player.x == enemy4.x && player.y == enemy4.y)
		{
			mHitPoints = mHitPoints - 20;
		}
		if (player.x == enemy5.x && player.y == enemy5.y)
		{
			mHitPoints = mHitPoints - 20;
		}

		if (mHitPoints <= 0)
		{
			cout << endl << "YOU LOSE!" << endl << endl;
			mHasntWon = false;
		}

		if (maze[player.x + 1][player.y] == 'E' || maze[player.x][player.y + 1] == 'E')
		{
			cout << endl << "YOU WIN!" << endl << endl;
			mHasntWon = false;
		}
	}
}