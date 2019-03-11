#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include "red.h"

std::string name = "";
int score = 0;
int score_table[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
std::string players_table[10] = { "unknown", "unknown" , "unknown" , "unknown" , "unknown" , "unknown" , "unknown" , "unknown" , "unknown" , "unknown" };
int closed = 0;

void player_registration()
{
	sf::RenderWindow window(sf::VideoMode(710, 550), "PACMAN by Sid");
	sf::Font font;
	font.loadFromFile("ComicKings.ttf");
	sf::Text podaj, imie;
	podaj.setFont(font);
	podaj.setString("Podaj imie");
	podaj.setCharacterSize(40);
	podaj.setPosition(355 - podaj.getGlobalBounds().width / 2, 100);
	podaj.setFillColor(sf::Color::Yellow);
	imie.setFont(font);
	imie.setString("");
	imie.setCharacterSize(40);
	imie.setPosition(355 - imie.getGlobalBounds().width / 2, 200);
	imie.setFillColor(sf::Color::Yellow);
	while (window.isOpen())
	{
		sf::Event event;
		sf::Uint32 unicode = 0;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
				unicode = event.text.unicode;
			if (event.type == sf::Event::Closed)
			{
				window.close();
				closed = 1;
			}
		}
		if (unicode >= '\u0020' && unicode <= '\u007A' && imie.getString().getSize() < 15)
		{

			std::string str = imie.getString();
			str += unicode;
			imie.setString(str);
			imie.setPosition(355 - imie.getGlobalBounds().width / 2, 300);
		}
		if (unicode == '\u0008')
		{
			std::string str = imie.getString();
			std::string str2 = "";
			if (str.size()>0)
				for (int i = 0; i < str.size() - 1; i++)
					str2 += str[i];
			imie.setString(str2);
			imie.setPosition(355 - imie.getGlobalBounds().width / 2, 300);
		}
		if (unicode == '\u000D')
		{
			name = imie.getString();
			window.close();
		}
		window.clear();
		window.draw(podaj);
		window.draw(imie);
		window.display();
	}
	return;
}

int game(int lives, sf::CircleShape * balls)
{
	sf::RenderWindow window(sf::VideoMode(710, 550), "PACMAN by Sid");
	sf::Texture gameboard_texture;
	gameboard_texture.loadFromFile("img/gameboard.png");
	sf::Font font;
	font.loadFromFile("ComicKings.ttf");
	sf::Sprite gameboard;
	gameboard.setTexture(gameboard_texture);
	sf::Texture ghosts_textures[4][4];
	sf::Texture pacman_textures[4][3];
	sf::Texture small_pacman_texture;
	small_pacman_texture.loadFromFile("img/pacman2_left.png");
	sf::Sprite small_pacman[3];
	for (int i = 0; i < lives; i++)
	{
		small_pacman[i].setTexture(small_pacman_texture);
		small_pacman[i].setScale(0.1, 0.1);
		small_pacman[i].setPosition(660 - i * 40, 510);
	}
	load_ghosts_textures(ghosts_textures);
	red blinky(ghosts_textures[0]), pinky(ghosts_textures[3]);
	blinky.setPosition(490, 10);
	pinky.setPosition(100, 10);
	pacman pac;
	std::ostringstream ss;
	ss << score;
	sf::Text score_text;
	sf::Text points;
	points.setString("Points: ");
	points.setFillColor(sf::Color::Yellow);
	points.setFont(font);
	points.setCharacterSize(25);
	points.setPosition(20, 510);
	score_text.setString(ss.str());
	score_text.setFillColor(sf::Color::Yellow);
	score_text.setFont(font);
	score_text.setCharacterSize(25);
	score_text.setPosition(points.getGlobalBounds().left + points.getGlobalBounds().width + 10, 510);
	sf::Clock ghost_timer, pacman_timer;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				closed = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				blinky.setDirection(dir_right);
				pinky.setDirection(dir_right);
				pac.setDirection(dir_right);
				pac.checkTexture();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				blinky.setDirection(dir_left);
				pinky.setDirection(dir_left);
				pac.setDirection(dir_left);
				pac.checkTexture();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				blinky.setDirection(dir_up);
				pinky.setDirection(dir_up);
				pac.setDirection(dir_up);
				pac.checkTexture();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				blinky.setDirection(dir_down);
				pinky.setDirection(dir_down);
				pac.setDirection(dir_down);
				pac.checkTexture();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				blinky.setDirection(dir_null);
				pinky.setDirection(dir_null);
				pac.setDirection(dir_null);
			}
		}
		if (ghost_timer.getElapsedTime().asMicroseconds() > 400)
		{
			blinky.selfMove(&pac);
			pinky.selfMove(&pac);
			pac.selfMove();
			window.clear();
			window.draw(points);
			window.draw(score_text);
			for (int i = 0; i < 3; i++)
				window.draw(small_pacman[i]);
			window.draw(gameboard);
			for (int i = 0; i < 183; i++)
			{
				if (pac.getGlobalBounds().contains(balls[i].getPosition()) && balls[i].getFillColor() == sf::Color::Yellow)
				{
					balls[i].setFillColor(sf::Color::Black);
					score += 10;
					ss.str("");
					ss << score;
					score_text.setString(ss.str());
				}
				window.draw(balls[i]);
			}
			window.draw(blinky);
			window.draw(pinky);
			window.draw(pac);
			if (pac.getGlobalBounds().intersects(blinky.getGlobalBounds()) || pac.getGlobalBounds().intersects(pinky.getGlobalBounds()))
			{
				std::string str = "";
				std::ostringstream bleble;
				bleble << lives - 1;
				if (lives == 3)
				{
					str = bleble.str() + " zycia pozostaly";
				}
				else if (lives == 2)
				{
					str = bleble.str() + " zycie pozostalo";
				}
				else
				{
					str  = "Koniec gry";
					int i = 0;
					while (score >= score_table[9 - i] && i < 10)
						i++;
					for (int j = 0; j < i - 1; j++)
					{
						std::swap(score_table[9 - j], score_table[8 - j]);
						std::swap(players_table[9 - j], players_table[8 - j]);
					}
					if (i > 0)
					{
						score_table[10 - i] = score;
						players_table[10 - i] = name;
					}
				}
				sf::Text lose;
				lose.setFillColor(sf::Color::Yellow);
				lose.setFont(font);
				lose.setCharacterSize(50);
				lose.setString(str);
				lose.setPosition(355 - lose.getGlobalBounds().width / 2, 250);
				window.draw(lose);
				window.display();
				Sleep(1500);
				window.close();
			}
			window.display();
			ghost_timer.restart();
		}
		if (pacman_timer.getElapsedTime().asMilliseconds() > 100)
		{
			pac.eat();
			pacman_timer.restart();
		}
		if (score == 1830)
		{
			int i = 0;
			while (score >= score_table[9 - i] && i < 10)
				i++;
			for (int j = 0; j < i - 1; j++)
			{
				std::swap(score_table[9 - j], score_table[8 - j]);
				std::swap(players_table[9 - j], players_table[8 - j]);
			}
			if (i > 0)
			{
				score_table[10 - i] = score;
				players_table[10 - i] = name;
			}
			sf::Text lose;
			lose.setFillColor(sf::Color::Yellow);
			lose.setFont(font);
			lose.setCharacterSize(50);
			lose.setString("Wygrana!");
			lose.setPosition(355 - lose.getGlobalBounds().width / 2, 250);
			window.draw(lose);
			window.display();
			Sleep(1500);
			window.close();
		}
	}
	return lives - 1;
}

int ekran_startowy()
{
	sf::RenderWindow window(sf::VideoMode(710, 550), "PACMAN by Sid");
	sf::Font font;
	font.loadFromFile("ComicKings.ttf");
	sf::Text pacman, graj, wyniki, wyjscie;
	pacman.setFont(font);
	pacman.setString("PACMAN");
	pacman.setCharacterSize(80);
	pacman.setPosition(355 - pacman.getGlobalBounds().width / 2, 20);
	pacman.setFillColor(sf::Color::Yellow);
	graj.setFont(font);
	graj.setString("Graj");
	graj.setCharacterSize(40);
	graj.setPosition(355 - graj.getGlobalBounds().width / 2, 200);
	graj.setFillColor(sf::Color::Yellow);
	wyniki.setFont(font);
	wyniki.setString("Wyniki");
	wyniki.setCharacterSize(40);
	wyniki.setPosition(355 - wyniki.getGlobalBounds().width / 2, 330);
	wyniki.setFillColor(sf::Color::Yellow);
	wyjscie.setFont(font);
	wyjscie.setString("Koniec");
	wyjscie.setCharacterSize(40);
	wyjscie.setPosition(355 - wyjscie.getGlobalBounds().width / 2, 460);
	wyjscie.setFillColor(sf::Color::Yellow);
	while (window.isOpen())
	{
		window.clear();
		window.draw(pacman);
		window.draw(graj);
		window.draw(wyniki);
		window.draw(wyjscie);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && graj.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				window.close();
				return 1;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && wyniki.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				window.close();
				return 2;
			}
			if (event.type == sf::Event::Closed || (sf::Mouse::isButtonPressed(sf::Mouse::Left) && wyjscie.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
			{
				window.close();
				return 3;
			}
		}
	}
}

void tabela_wynikow()
{
	sf::RenderWindow window(sf::VideoMode(710, 550), "PACMAN by Sid");
	sf::Font font;
	font.loadFromFile("ComicKings.ttf");
	sf::Text numbers[10];
	sf::Text scores[10];
	sf::Text players[10];
	std::string bleee[10] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	sf::Text powrot;
	powrot.setFont(font);
	powrot.setFillColor(sf::Color::Yellow);
	powrot.setCharacterSize(30);
	powrot.setString("Powrot");
	powrot.setPosition(355 - powrot.getGlobalBounds().width / 2, 450);
	for (int i = 0; i < 10; i++)
	{
		numbers[i].setFont(font);
		numbers[i].setFillColor(sf::Color::Yellow);
		numbers[i].setCharacterSize(15);
		numbers[i].setString(bleee[i]);
		numbers[i].setPosition(200, 30 * i + 100);
		players[i].setFont(font);
		players[i].setFillColor(sf::Color::Yellow);
		players[i].setCharacterSize(15);
		players[i].setString(players_table[i]);
		players[i].setPosition(250, 30 * i + 100);
		scores[i].setFont(font);
		scores[i].setFillColor(sf::Color::Yellow);
		scores[i].setCharacterSize(15);
		std::ostringstream haha;
		haha << score_table[i];
		scores[i].setString(haha.str());
		scores[i].setPosition(500, 30 * i + 100);
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && powrot.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				window.close();
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
				closed = 1;
			}
		}
		window.clear();
		for (int i = 0; i < 10; i++)
		{
			window.draw(numbers[i]);
			window.draw(players[i]);
			window.draw(scores[i]);
		}
		window.draw(powrot);
		window.display();
	}
	return;
}
	
int main()
{
	std::ifstream plik("wyniki.txt");
	if (!plik.fail())
	{
		for(int i=0; !plik.eof(); i++)
		{
			plik >> players_table[i];
			plik >> score_table[i];
		}
	}
	int a = ekran_startowy();
	while (closed == 0)
	{
		name = "";
		score = 0;
		if (a == 1)
		{
			player_registration();
			sf::CircleShape balls[183];
			set_balls(balls);
			int lives = 3;
			while (lives > 0 && closed == 0)
				lives = game(lives, balls);
			if (closed == 0)
				a = ekran_startowy();
		}
		else if (a == 2)
		{
			tabela_wynikow();
			if (closed == 0)
				a = ekran_startowy();
		}
		else if (a == 3)
			closed = 1;
	}
	std::ofstream zapis("wyniki.txt");
	for (int i = 0; i < 10; i++)
	{
		zapis << players_table[i] << std::endl;
		zapis << score_table[i] << std::endl;
	}
	return 0;
}
