#pragma once

#include "gamecore.h"
#include "pacman.h"

class red : public sf::Sprite
{
public:
	red(sf::Texture *);
	~red();
	void selfMove(pacman *);
	void setDirection(direc);
	int getCoordX();
	int getCoordY();
private:
	int coord_x;
	int coord_y;
	direc direction;
	sf::Texture up;
	sf::Texture down;
	sf::Texture left;
	sf::Texture right;
};

