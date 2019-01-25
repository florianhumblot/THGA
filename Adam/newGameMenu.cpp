#include "pch.h"
#include "newGameMenu.hpp"

newGameMenu::newGameMenu(float width, float heigth, Character & player)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}

	menuChoices[0].setString("What class do you want to play?");
	menuChoices[1].setString("The Warrior! A stalward defender of justice and honor. Skilled with the sword! Has more health than the mage.");
	menuChoices[2].setString("The Mage! A fireball shooting spellcaster, burning all enemies in his wake!, Has more speed than the warrior.");
	menuChoices[3].setString("Choose your Class and venture forth into the world!");

	for (int i = 0; i < newGameTiles; i++) {
		menuChoices[i].setFont(font);
		menuChoices[i].setCharacterSize(90);
		if (i == 1 || i == 2) {
			menuChoices[i].setPosition(sf::Vector2f((player.getPosition().x - 800), (player.getPosition().y) + 200 * (i - 2) - 40));
		}
		else {
			menuChoices[i].setPosition(sf::Vector2f((player.getPosition().x - 30), (player.getPosition().y) + 230 * (i - 2) - 40));
		}
	}
	menuChoices[0].setFillColor(sf::Color::Red);
	menuChoices[1].setFillColor(sf::Color::Yellow);
	menuChoices[2].setFillColor(sf::Color::White);
	menuChoices[3].setFillColor(sf::Color::Red);

	/*
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
	*/

	selectedItem = 1;
	setNewGame();
	//current_state = menu_states::s_newGameMenu;
}

void newGameMenu::draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player)
{
	main_camera.setSize(1920, 1080);
	sf::Vector2f playerposforbg = player.getPosition();
	bgMain.setPosition(sf::Vector2f(playerposforbg.x - 960, playerposforbg.y - 540));
	window.draw(bgMain);
	for (unsigned int i = 0; i < newGameTiles; i++)
	{
		window.draw(menuChoices[i]);
	}
	window.setView(main_camera);
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

int newGameMenu::chooseTile(std::shared_ptr<Menu> & currentMenu, Character & player, sf::Window & window, AnimationManager & ani)
{
	if (selectedItem == 0) {
		
	}
	else if (selectedItem == 1) {
		std::cout << "warrior has been chosen" << '\n';
		//state = STATE::PLAYING;
		player.setAnimationMap(ani.animations["knight"]);
		player.setAnimation("IDLEright", Animation::intervals::idle);
		player.setTexture(player.currentAnimation.nextFrame());
		//menu_states = menu_states::INGAME;
		setInGame();
		//gameStarted = 1;
		return 2;
	}
	else if (selectedItem == 2) {
		std::cout << "hunter has been chosen" << '\n';
		//state = STATE::PLAYING;
		player.setAnimationMap(ani.animations["mage"]);
		player.setAnimation("IDLEright", Animation::intervals::idle);
		player.setTexture(player.currentAnimation.nextFrame());
		//menu_states = menu_states::INGAME;
		setInGame();
		//gameStarted = 1;
		return 2;
	}
	else if (selectedItem == 3) {
		std::cout << "option menu not made yet" << std::endl;
	}
	return 0;
}