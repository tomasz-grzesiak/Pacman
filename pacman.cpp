#include "pacman.h"
#include <iostream>


pacman::pacman()
{
	pacman_textures[0][0].loadFromFile("img/pacman1_up.png");
	pacman_textures[0][1].loadFromFile("img/pacman2_up.png");
	pacman_textures[0][2].loadFromFile("img/pacman3_up.png");
	pacman_textures[1][0].loadFromFile("img/pacman1_down.png");
	pacman_textures[1][1].loadFromFile("img/pacman2_down.png");
	pacman_textures[1][2].loadFromFile("img/pacman3_down.png");
	pacman_textures[2][0].loadFromFile("img/pacman1_left.png");
	pacman_textures[2][1].loadFromFile("img/pacman2_left.png");
	pacman_textures[2][2].loadFromFile("img/pacman3_left.png");
	pacman_textures[3][0].loadFromFile("img/pacman1_right.png");
	pacman_textures[3][1].loadFromFile("img/pacman2_right.png");
	pacman_textures[3][2].loadFromFile("img/pacman3_right.png");
	scale(0.1, 0.1);
	direction = dir_null;
	coord_x = 12;
	coord_y = 10;
	setTexture(pacman_textures[3][1]);
	setPosition(340, 280);
	eating_phase = 1;
}

pacman::~pacman()
{
}

void pacman::selfMove()
{
	if (direction == dir_up)
	{
		if (gameboard_matrix[coord_y - 1][coord_x] == 0)
		{
			move(0, -0.15);
			for (int i = 0; i < 17; i++)
				if (int(getGlobalBounds().top) == 30 * i + 10)
				{
					coord_y = i + 1;
					return;
				}
		}
		return;
	}
	if (direction == dir_down)
	{
		if (gameboard_matrix[coord_y + 1][coord_x] == 0)
		{
			move(0, 0.15);
			for (int i = 0; i < 17; i++)
				if (int(getGlobalBounds().top) == 30 * i + 10)
				{
					coord_y = i + 1;
					return;
				}
		}
		return;
	}
	if (direction == dir_left)
	{
		if (gameboard_matrix[coord_y][coord_x - 1] == 0)
		{
			move(-0.15, 0);
			for (int i = 0; i < 24; i++)
				if (int(getGlobalBounds().left) == 30 * i + 10)
				{
					coord_x = i + 1;
					return;
				}
		}
		return;
	}
	if (direction == dir_right)
	{
		if (gameboard_matrix[coord_y][coord_x + 1] == 0)
		{
			move(0.15, 0);
			for (int i = 0; i < 24; i++)
				if (int(getGlobalBounds().left) == 30 * i + 10)
				{
					coord_x = i + 1;
					return;
				}
		}
		return;
	}
}

int pacman::getCoordX()
{
	return coord_x;
}

int pacman::getCoordY()
{
	return coord_y;
}

void pacman::setDirection(direc n)
{
	if (n == dir_up && (gameboard_matrix[coord_y - 1][coord_x] == 1 || int(getGlobalBounds().left) < 30 * (coord_x-1) + 8 || int(getGlobalBounds().left) > 30 * (coord_x - 1) + 12))
		return;
	if (n == dir_down && (gameboard_matrix[coord_y + 1][coord_x] == 1 || int(getGlobalBounds().left) < 30 * (coord_x-1) + 8 || int(getGlobalBounds().left) > 30 * (coord_x - 1) + 12))
		return;
	if (n == dir_left && (gameboard_matrix[coord_y][coord_x - 1] == 1 || int(getGlobalBounds().top) < 30 * (coord_y-1) + 8 || int(getGlobalBounds().top) > 30 * (coord_x - 1) +12))
		return;
	if (n == dir_right && (gameboard_matrix[coord_y][coord_x + 1] == 1 || int(getGlobalBounds().top) < 30 * (coord_y-1) + 8 || int(getGlobalBounds().top) > 30 * (coord_y - 1) + 12))
		return;
	direction = n;
}

void pacman::checkTexture()
{
	if (direction == dir_up)
	{
		if (gameboard_matrix[coord_y - 1][coord_x] == 0)
			setTexture(pacman_textures[0][0]);
		return;
	}
	if (direction == dir_down)
	{
		if (gameboard_matrix[coord_y + 1][coord_x] == 0)
			setTexture(pacman_textures[1][0]);
		return;
	}
	if (direction == dir_left)
	{
		if (gameboard_matrix[coord_y][coord_x - 1] == 0)
			setTexture(pacman_textures[2][0]);
		return;
	}
	if (direction == dir_right)
	{
		if (gameboard_matrix[coord_y][coord_x + 1] == 0)
			setTexture(pacman_textures[3][0]);
		return;
	}
}

void pacman::eat()
{
	if (eating_phase == 0)
	{
		eating_phase = 1;
		if (direction == dir_up)
		{
			setTexture(pacman_textures[0][1]);
			return;
		}
		if (direction == dir_down)
		{
			setTexture(pacman_textures[1][1]);
			return;
		}
		if (direction == dir_left)
		{
			setTexture(pacman_textures[2][1]);
			return;
		}
		if (direction == dir_right)
		{
			setTexture(pacman_textures[3][1]);
			return;
		}
	}
	if (eating_phase == 1)
	{
		eating_phase = 2;
		if (direction == dir_up)
		{
			setTexture(pacman_textures[0][2]);
			return;
		}
		if (direction == dir_down)
		{
			setTexture(pacman_textures[1][2]);
			return;
		}
		if (direction == dir_left)
		{
			setTexture(pacman_textures[2][2]);
			return;
		}
		if (direction == dir_right)
		{
			setTexture(pacman_textures[3][2]);
			return;
		}
	}
	if (eating_phase == 2)
	{
		eating_phase = 3;
		if (direction == dir_up)
		{
			setTexture(pacman_textures[0][1]);
			return;
		}
		if (direction == dir_down)
		{
			setTexture(pacman_textures[1][1]);
			return;
		}
		if (direction == dir_left)
		{
			setTexture(pacman_textures[2][1]);
			return;
		}
		if (direction == dir_right)
		{
			setTexture(pacman_textures[3][1]);
			return;
		}
	}
	if (eating_phase == 3)
	{
		eating_phase = 0;
		if (direction == dir_up)
		{
			setTexture(pacman_textures[0][0]);
			return;
		}
		if (direction == dir_down)
		{
			setTexture(pacman_textures[1][0]);
			return;
		}
		if (direction == dir_left)
		{
			setTexture(pacman_textures[2][0]);
			return;
		}
		if (direction == dir_right)
		{
			setTexture(pacman_textures[3][0]);
			return;
		}
	}
}

