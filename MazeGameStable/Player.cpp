#include "Player.hpp"
#include <iostream>
#include <vector>
using namespace std;

Player::Player(char icon)
{
    sprite = icon;
	x = 1;
	y = 1;
}

Player::~Player()
{

}