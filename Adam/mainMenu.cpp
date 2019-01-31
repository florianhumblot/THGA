#include "pch.h"
#include "mainMenu.hpp"
#include "newGameMenu.hpp"

mainMenu::mainMenu(float width, float heigth, Character &player)

{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}

	menuChoices[0].setString("New Game");
	menuChoices[1].setString("Continue Game");
	menuChoices[2].setString("Load Game");
	menuChoices[3].setString("Options");
	menuChoices[4].setString("Quit Game");

	for (int i = 0; i < numberOfTiles; i++) {
		menuChoices[i].setFont(font);
		menuChoices[i].setCharacterSize(160);
		menuChoices[i].setFillColor(sf::Color::White);
		menuChoices[i].setPosition(sf::Vector2f((player.getPosition().x) - 200, (player.getPosition().y) + 160 * (i - 2) - 120));
	}
	menuChoices[0].setFillColor(sf::Color::Red);

	selectedItem = 0;
	setMain();
}

void mainMenu::draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player)
{
	main_camera.setSize(1920, 1080);
	sf::Vector2f playerposforbg = player.getPosition();
	bgMain.setPosition(sf::Vector2f(playerposforbg.x - 960, playerposforbg.y - 540));
	window.draw(bgMain);

	for (unsigned int i = 0; i < numberOfTiles; i++)
	{
		window.draw(menuChoices[i]);
	}
	window.setView(main_camera);
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

int mainMenu::chooseTile(std::shared_ptr<Menu> &currentMenu, Character & player, sf::Window & window, AnimationManager & ani)
{
	if (selectedItem == 0) {
		currentMenu = std::make_shared<newGameMenu>(window.getSize().x, window.getSize().y, player);
		setNewGame();
	}
	else if (selectedItem == 1) {
		if (player.role == std::string("")) {
			currentMenu = std::make_shared<newGameMenu>(window.getSize().x, window.getSize().y, player);
			setNewGame();
		}
		else {
			setInGame();
			return 2;
		}
	}
	else if (selectedItem == 2) {
	}
	else if (selectedItem == 3) {
	}
	else if (selectedItem == 4) {
		window.close();
	}
	return 0;
}