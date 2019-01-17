#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.hpp"

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
public:
	inGameMenu(float width, float heigth)
	{
		if (!font.loadFromFile("fonts/strangers.ttf"))
		{
			std::cout << "error loading font" << std::endl;
		}

		pauseScreen[0].setFont(font);
		pauseScreen[0].setString("Continue Game");
		pauseScreen[0].setFillColor(sf::Color::Red);
		pauseScreen[0].setCharacterSize(75);

		pauseScreen[1].setFont(font);
		pauseScreen[1].setString("Load Game");
		pauseScreen[1].setFillColor(sf::Color::White);
		pauseScreen[1].setCharacterSize(75);

		pauseScreen[2].setFont(font);
		pauseScreen[2].setString("Options");
		pauseScreen[2].setFillColor(sf::Color::White);
		pauseScreen[2].setCharacterSize(75);

		pauseScreen[3].setFont(font);
		pauseScreen[3].setString("Quit Game");
		pauseScreen[3].setFillColor(sf::Color::White);
		pauseScreen[3].setCharacterSize(75);

		selectedItem = 0;
	}

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & titleSelect) override;
};


#endif INGAMEMENU_HPP