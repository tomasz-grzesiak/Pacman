#include "red.h"



red::red(sf::Texture * textures)
{
	up = textures[0];
	down = textures[1];
	left = textures[2];
	right = textures[3];
	setScale(0.1, 0.1);
	setTexture(right);
	direction = dir_null;
	coord_x = 17;
	coord_y = 1;
}

red::~red()
{
}

int red::getCoordX()
{
	return coord_x;
}

int red::getCoordY()
{
	return coord_y;
}

void red::selfMove(pacman * pac)
{
	if (pac->getGlobalBounds().top - this->getGlobalBounds().top < 0.3 && gameboard_matrix[coord_y - 1][coord_x] == 0 && (int(this->getGlobalBounds().left - 10)) % 30 <= 1)
	{
		setTexture(up);
		move(0, -0.1);
		for (int i = 0; i < 17; i++)
			if (int(getGlobalBounds().top) == 30 * i + 10)
			{
				coord_y = i + 1;
				return;
			}
		return;
	}
	if (pac->getGlobalBounds().top - this->getGlobalBounds().top > -0.3 && gameboard_matrix[coord_y + 1][coord_x] == 0 && (int(this->getGlobalBounds().left - 10)) % 30 <= 1)
	{
		setTexture(down);
		move(0, 0.1);
		for (int i = 0; i < 17; i++)
			if (int(getGlobalBounds().top) == 30 * i + 10)
			{
				coord_y = i + 1;
				return;
			}
		return;
	}
	if (pac->getGlobalBounds().left - this->getGlobalBounds().left < 0.3 && gameboard_matrix[coord_y][coord_x - 1] == 0 && (int(this->getGlobalBounds().top - 10)) % 30 <= 1)
	{
		setTexture(left);
		move(-0.1, 0);
		for (int i = 0; i < 24; i++)
			if (int(getGlobalBounds().left) == 30 * i + 10)
			{
				coord_x = i + 1;
				return;
			}
		return;
	}
	if (pac->getGlobalBounds().left  - this->getGlobalBounds().left > -0.3 && gameboard_matrix[coord_y][coord_x + 1] == 0 && (int(this->getGlobalBounds().top - 10)) % 30 <= 1)
	{
		setTexture(right);
		move(0.1, 0);
		for (int i = 0; i < 24; i++)
			if (int(getGlobalBounds().left) == 30 * i + 10)
			{
				coord_x = i + 1;
				return;
			}
		return;
	}
}

void red::setDirection(direc n)
{
	direction = n;
}