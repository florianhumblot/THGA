#ifndef NEWGAMEMENU_HPP
#define NEWGAMEMENU_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

#define newGameTiles 5

class newGameMenu
{
private:
	float width;
	float heigth;
	int selectedItem;
	sf::Font font;
	sf::Text menuChoices[newGameTiles];
	sf::Sprite sprite;
	sf::Texture texture;
public:
	newGameMenu(float width, float heigth)

	{
		if (!font.loadFromFile("fonts/strangers.ttf"))
		{
			std::cout << "error loading font" << std::endl;
		}

		menuChoices[0].setFont(font);
		menuChoices[0].setString("What class do you want to play?");
		menuChoices[0].setFillColor(sf::Color::Red);
		menuChoices[0].setCharacterSize(100);
		menuChoices[0].setPosition(sf::Vector2f((width / 2) * 0.85, (newGameTiles + 1) * 30));

		menuChoices[1].setFont(font);
		menuChoices[1].setString(
			"The Warrior! A stalward defender of justice and honor. Skilled with the sword and shield. Has more health than the hunter");
		menuChoices[1].setFillColor(sf::Color::Yellow);
		menuChoices[1].setCharacterSize(45);
		menuChoices[1].setPosition(sf::Vector2f((width / 8) * 0.85, (newGameTiles + 1) * 60));

		menuChoices[2].setFont(font);
		menuChoices[2].setString("The Hunter! Happy trigger fingers make the Hunter a deadly opponent! Is quicker than the warrior");
		menuChoices[2].setFillColor(sf::Color::White);
		menuChoices[2].setCharacterSize(45);
		menuChoices[2].setPosition(sf::Vector2f((width / 8) * 0.85, (newGameTiles + 1) * 90));

		menuChoices[3].setFont(font);
		menuChoices[3].setString("Choose your Class and venture forth into the world!");
		menuChoices[3].setFillColor(sf::Color::Red);
		menuChoices[3].setCharacterSize(75);
		menuChoices[3].setPosition(sf::Vector2f((width / 2) * 0.85, (newGameTiles + 1) * 120));

		selectedItem = 1;
	}

	void draw(sf::RenderWindow & window);
	void moveUp();
	void moveDown();
	void chooseTile(int & tileSelect);
};



#endif NEWGAMEMENU_HPP
