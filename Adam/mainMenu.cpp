#include "mainMenu.hpp"

void mainMenu::draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < numberOfTiles; i++)
	{
		window.draw(menuChoices[i]);
	}
}

void mainMenu::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menuChoices[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menuChoices[selectedItem].setFillColor(sf::Color::Red);
	}
}
void mainMenu::moveDown()
{
	menuChoices[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem + 1 < numberOfTiles)
	{
		
		selectedItem++;
		
	}
	else 
	{
		selectedItem = 0;
	}
	menuChoices[selectedItem].setFillColor(sf::Color::Red);
}

void mainMenu::chooseTile(int & tileSelect)
{

}