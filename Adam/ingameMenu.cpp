#include "pch.h"
#include "ingameMenu.hpp"

inGameMenu::inGameMenu(float width, float heigth, Character &player) :
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
	pauseScreen[0].setPosition(sf::Vector2f((player.getPosition().x) - 100, (player.getPosition().y) - 100));

	pauseScreen[1].setFont(font);
	pauseScreen[1].setString("Load Game");
	pauseScreen[1].setFillColor(sf::Color::White);
	pauseScreen[1].setCharacterSize(80);
	pauseScreen[1].setPosition(sf::Vector2f((player.getPosition().x) - 100, (player.getPosition().y) - 50));

	pauseScreen[2].setFont(font);
	pauseScreen[2].setString("return Main Menu");
	pauseScreen[2].setFillColor(sf::Color::White);
	pauseScreen[2].setCharacterSize(80);
	pauseScreen[2].setPosition(sf::Vector2f((player.getPosition().x) - 100, (player.getPosition().y)));

	pauseScreen[3].setFont(font);
	pauseScreen[3].setString("Quit Game");
	pauseScreen[3].setFillColor(sf::Color::White);
	pauseScreen[3].setCharacterSize(80);
	pauseScreen[3].setPosition(sf::Vector2f((player.getPosition().x) - 100, (player.getPosition().y) + 50));


	current_state = menu_states::s_ingameMenu;
	selectedItem = 0;
}

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
		selectedItem = pauseOptions-1;
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