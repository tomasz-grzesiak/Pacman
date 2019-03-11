#pragma once

#include <SFML/Graphics.hpp>


enum direc { dir_up, dir_down, dir_left, dir_right, dir_null };

extern int gameboard_matrix[18][25];

void load_ghosts_textures(sf::Texture[][4]);

void set_balls(sf::CircleShape *);

