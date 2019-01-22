#include "pch.h"
#include "newGameMenu.hpp"

newGameMenu::newGameMenu(float width, float heigth)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	menuChoices[0].setFont(font);
	menuChoices[0].setFillColor(sf::Color::Red);
	menuChoices[0].setString(
		"What class do you want to play?");
	menuChoices[0].setCharacterSize(111);
	menuChoices[0].setPosition(sf::Vector2f((width / 2) * 0.85, (newGameTiles + 1) * 30));

	menuChoices[1].setFont(font);
	menuChoices[1].setString(
		"The Warrior! A stalward defender of justice and honor. Skilled with the sword! Has more health than the mage.");
	menuChoices[1].setFillColor(sf::Color::Yellow);
	menuChoices[1].setCharacterSize(55);
	menuChoices[1].setPosition(sf::Vector2f((width / 8) * 0.85, (newGameTiles + 1) * 60));

	menuChoices[2].setFont(font);
	menuChoices[2].setString(
		"The Mage! A fireball shooting spellcaster, burning all enemies in his wake!, Has more speed than the warrior.");
	menuChoices[2].setFillColor(sf::Color::White);
	menuChoices[2].setCharacterSize(55);
	menuChoices[2].setPosition(sf::Vector2f((width / 8) * 0.85, (newGameTiles + 1) * 90));

	menuChoices[3].setFont(font);
	menuChoices[3].setString(
		"Choose your Class and venture forth into the world!");
	menuChoices[3].setFillColor(sf::Color::Red);
	menuChoices[3].setCharacterSize(77);
	menuChoices[3].setPosition(sf::Vector2f((width / 2) * 0.85, (newGameTiles + 1) * 120));

	selectedItem = 1;
	current_state = menu_states::s_newGameMenu;
}

void newGameMenu::draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < newGameTiles; i++)
	{
		window.draw(menuChoices[i]);
	}
}

void newGameMenu::moveUp()
{
	menuChoices[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem - 1 >= 1)
	{
		selectedItem--;
	}
	else
	{
		selectedItem = newGameTiles - 3;
	}
	menuChoices[selectedItem].setFillColor(sf::Color::Yellow);
}

void newGameMenu::moveDown()
{
	menuChoices[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem + 1 < newGameTiles-2)
	{

		selectedItem++;

	}
	else
	{
		selectedItem = 1;
	}
	menuChoices[selectedItem].setFillColor(sf::Color::Yellow);
}

void newGameMenu::chooseTile(int & tileSelect)
{

}