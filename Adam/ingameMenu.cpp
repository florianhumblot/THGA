#include "pch.h"
#include "ingameMenu.hpp"

void inGameMenu::draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < pauseOptions; i++)
	{
		window.draw(pauseScreen[i]);
	}
}

void inGameMenu::moveUp()
{
	pauseScreen[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem - 1 >= 0)
	{
		selectedItem--;
	}
	else
	{
		selectedItem = pauseOptions -1;
	}
	pauseScreen[selectedItem].setFillColor(sf::Color::Red);
}

void inGameMenu::moveDown()
{
	pauseScreen[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem + 1 < pauseOptions)
	{
		selectedItem++;
	}
	else
	{
		selectedItem = 0;
	}
	pauseScreen[selectedItem].setFillColor(sf::Color::Red);
}

void inGameMenu::chooseTile(int & titleSelect)
{

}