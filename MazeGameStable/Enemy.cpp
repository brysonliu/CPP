#include "Enemy.hpp"

Enemy::Enemy(vector< vector<char> > &maze, int size, char icon, bool isRandom)
{
	if (isRandom)
	{
		shuffle();
	}
	else
	{
		sprite = icon;
	}
	
	difficulty(sprite);
	x = rand() % size;
	y = rand() % size;
	once = true;
	prevMove = "NA";
	pastDirX = Left;
	pastDirY = Up;

	while (maze[y][x] != ' ')
	{
		x = rand() % size;
		y = rand() % size;
	}
	
	if (maze[y][x] == ' ')
	{
		maze[y][x] = sprite;
	}
}

Enemy::~Enemy()
{

}

void Enemy::shuffle()
{
	int randDiff = rand() % 3;

	switch(randDiff)
	{
		case 0:
			sprite = '&';
			break;
		case 1:
			sprite = '%';
			break;
		case 2:
			sprite = '!';
			break;
	}
}

void Enemy::difficulty(char spr)
{
	switch(spr)
	{
		case '&':
			damage = 10;
			break;
		case '%':
			damage = 20;
			break;
		case '!':
			damage = 25;
			break;
	}
}

void Enemy::resetMove()
{
	once = true;
}

//enemy movement algorithm
char Enemy::move(vector< vector<char> > &maze, int i, int j)
{
	if (once)
	{
		bool goUp = false;
		//possible directions
		bool psbUp = false;
		bool psbDown = false;
		bool psbRight = false;
		bool psbLeft = false;

		//check possible directions
		if (maze[y][x + 1] != '#' && maze[y][x + 1] != 'E') //RIGHT
		{
			psbRight = true;
		}
		if (maze[y][x - 1] != '#' && maze[y][x - 1] != 'E') //LEFT
		{
			psbLeft = true;
		}
		if (maze[y + 1][x] != '#' && maze[y + 1][x] != 'E') //DOWN
		{
			psbDown = true;
		}
		if (maze[y - 1][x] != '#' && maze[y - 1][x] != 'E') //UP
		{
			psbUp = true;
		}

		//movement tracking
		enum Mv { up, right, down, left, NA };
		Mv move = NA;

		//previous movement
		if (prevMove == "up")
		{
			move = up;
		}
		else if (prevMove == "right")
		{
			move = right;
		}
		else if (prevMove == "down")
		{
			move = down;
		}
		else if (prevMove == "left")
		{
			move = left;
		}
		else
		{
			move = NA;
		}

		//prevent repetitive enemy movement
		if (pastDirX == Right && !psbRight)
		{
			if (pastDirY == Up) //if past move was up
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

		else if (pastDirX == Right && psbRight)
		{
			move = right;
		}

		else if (pastDirX == Left && !psbLeft)
		{
			if (pastDirY == Up)
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

		else if (pastDirX == Left && psbLeft)
		{
			move = left;
		}

		else if (pastDirY == Up && !psbUp)
		{
			if (pastDirX == Right)
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

		else if (pastDirY == Up && psbUp)
		{
			move = up;
		}

		else if (pastDirY == Down && !psbDown)
		{
			if (pastDirX == Right)
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

		else if (pastDirY == Down && psbDown)
		{
			move = down;
		}

		switch (move) {
		case up:
			maze[y][x] = ' ';
			pastDirY = Up;
			prevMove = "up";
			y--;
			break;
		case right:
			maze[y][x] = ' ';
			pastDirX = Right;
			prevMove = "right";
			x++;
			break;
		case down:
			maze[y][x] = ' ';
			pastDirY = Down;
			prevMove = "down";
			y++;
			break;
		case left:
			maze[y][x] = ' ';
			pastDirX = Left;
			prevMove = "left";
			x--;
			break;
		case NA:
			prevMove = "NA";
			break;
		}
	}
	once = false;
	return maze[i][j];
}