#include "pch.h"
#include "mainMenu.hpp"

mainMenu::mainMenu(float width, float heigth)

{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}

	menuChoices[0].setFont(font);
	menuChoices[0].setString("New Game");
	menuChoices[0].setFillColor(sf::Color::Red);
	menuChoices[0].setCharacterSize(111);
	menuChoices[0].setPosition(sf::Vector2f((width / 2) * 0.85, (numberOfTiles + 1) * 30));

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
	current_state = menu_states::s_mainMenu;
}

void mainMenu::draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < numberOfTiles; i++)
	{
		window.draw(menuChoices[i]);
	}
}

void mainMenu::moveUp()
{
	menuChoices[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem - 1 >= 0)
	{
		selectedItem--;
	}
	else
	{
		selectedItem = numberOfTiles - 1 ;
	}
	menuChoices[selectedItem].setFillColor(sf::Color::Red);
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

void mainMenu::chooseTile(int & selectTile)
{

}