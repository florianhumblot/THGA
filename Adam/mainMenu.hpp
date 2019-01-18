#ifndef _MAINMENU_HPP
#define _MAINMENU_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

#include "menu.hpp"

#define numberOfTiles 5

class mainMenu : public Menu
{
private:
	float width;
	float heigth;
	int selectedItem;
	sf::Font font;
	sf::Text menuChoices[numberOfTiles];


public:
	mainMenu(float width, float heigth)

	{
		if (!font.loadFromFile("fonts/stranger.ttf"))
		{
			std::cout << "error loading font" << std::endl;
		}

		menuChoices[0].setFont(font);
		menuChoices[0].setString("New Game");
		menuChoices[0].setFillColor(sf::Color::Red);
		menuChoices[0].setCharacterSize(111);
		menuChoices[0].setPosition(sf::Vector2f((width / 2) * 0.85 , (numberOfTiles + 1) * 30));

		menuChoices[1].setFont(font);
		menuChoices[1].setFillColor(sf::Color::White);
		menuChoices[1].setString("Continue Game");
		menuChoices[1].setCharacterSize(111);
		menuChoices[1].setPosition(sf::Vector2f((width / 2)* 0.85, (numberOfTiles + 1) * 50));

		menuChoices[2].setFont(font);
		menuChoices[2].setFillColor(sf::Color::White);
		menuChoices[2].setString("Load Game");
		menuChoices[2].setCharacterSize(111);
		menuChoices[2].setPosition(sf::Vector2f((width / 2) * 0.85, (numberOfTiles + 1) * 70));

		menuChoices[3].setFont(font);
		menuChoices[3].setFillColor(sf::Color::White);
		menuChoices[3].setString("Options");
		menuChoices[3].setCharacterSize(111);
		menuChoices[3].setPosition(sf::Vector2f((width / 2)* 0.85, (numberOfTiles + 1) * 90));

		menuChoices[4].setFont(font);
		menuChoices[4].setFillColor(sf::Color::White);
		menuChoices[4].setString("Quit Game");
		menuChoices[4].setCharacterSize(111);
		menuChoices[4].setPosition(sf::Vector2f((width / 2)* 0.85, (numberOfTiles + 1) * 110));

		selectedItem = 0;
	}

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & tileSelect) override;

};




#endif // !MENU_HPP
