#include "pch.h"
#include "newGameMenu.hpp"

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