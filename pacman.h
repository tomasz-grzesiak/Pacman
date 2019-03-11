#pragma once

#include "gamecore.h"


class pacman : public sf::Sprite
{
public:
	pacman();
	~pacman();
	void selfMove();
	void setDirection(direc);
	void checkTexture();
	void eat();
	int getCoordX();
	int getCoordY();
private:
	int coord_x;
	int coord_y;
	direc direction;
	sf::Texture pacman_textures[4][3];
	int eating_phase;
	
};

