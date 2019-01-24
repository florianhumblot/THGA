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

	/*
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
	menuChoices[4].setPosition(sf::Vector2f((width / 2)* 0.85, (numberOfTiles + 1) * 110)); */

	selectedItem = 0;
	setMain();
	//current_state = menu_states::s_mainMenu;
	//gameStarted = 0;
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

int mainMenu::chooseTile(int & selectTile, std::shared_ptr<Menu> &currentMenu, Character & player, sf::Window & window, AnimationManager & ani)
{
	if (selectTile == 0) {
		currentMenu = std::make_shared<newGameMenu>(window.getSize().x, window.getSize().y, player);
		//menu_states = menu_states::NEWGAME;
		setNewGame();
		std::cout << "set newGAMe \n";
	}
	else if (selectTile == 1) {
		//state = STATE::PLAYING;
		std::cout << "set ingame \n";
		//menu_states = menu_states::INGAME;
		setInGame();
		return 2;
	}
	else if (selectTile == 2) {
		std::cout << "not made yet";
	}
	else if (selectTile == 3) {
		std::cout << "option menu not made yet" << std::endl;
	}
	return 0;
}