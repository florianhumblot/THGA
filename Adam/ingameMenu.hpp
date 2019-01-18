#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP

#include "menu.hpp"
#include "Character.h"

#define pauseOptions 4

class inGameMenu: public Menu
{
private:
	float width;
	float heigth;
	int selectedItem;
	sf::Font font;
	sf::Text pauseScreen[pauseOptions];
	sf::Sprite sprite;
	sf::Texture texture;
	Character &player;
public:
	inGameMenu(float width, float heigth):
		player(player)
	{
		if (!font.loadFromFile("fonts/stranger.ttf"))
		{
			std::cout << "error loading font" << std::endl;
		}

		pauseScreen[0].setFont(font);
		pauseScreen[0].setString("Continue Game");
		pauseScreen[0].setFillColor(sf::Color::Red);
		pauseScreen[0].setCharacterSize(80);
		pauseScreen[0].setPosition(sf::Vector2f((width / 2) * 0.85, (pauseOptions + 1) * 60));

		pauseScreen[1].setFont(font);
		pauseScreen[1].setString("Load Game");
		pauseScreen[1].setFillColor(sf::Color::White);
		pauseScreen[1].setCharacterSize(80);
		pauseScreen[1].setPosition(sf::Vector2f((width / 2) * 0.85, (pauseOptions + 1) * 60));

		pauseScreen[2].setFont(font);
		pauseScreen[2].setString("Options");
		pauseScreen[2].setFillColor(sf::Color::White);
		pauseScreen[2].setCharacterSize(80);
		pauseScreen[2].setPosition(sf::Vector2f((width / 2) * 0.85, (pauseOptions + 1) * 70));

		pauseScreen[3].setFont(font);
		pauseScreen[3].setString("Quit Game");
		pauseScreen[3].setFillColor(sf::Color::White);
		pauseScreen[3].setCharacterSize(80);
		pauseScreen[3].setPosition(sf::Vector2f((width / 2) * 0.85, (pauseOptions + 1) * 80));

		selectedItem = 0;
	}

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & titleSelect) override;
};


#endif INGAMEMENU_HPP