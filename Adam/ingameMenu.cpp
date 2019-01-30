#include "pch.h"
#include "ingameMenu.hpp"

inGameMenu::inGameMenu(float width, float heigth, Character &player) :
	player(player)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	
	pauseScreen[0].setString("Continue Game");
	pauseScreen[1].setString("Load Game");
	pauseScreen[2].setString("Return main menu");
	pauseScreen[3].setString("Quit Game");

	for (int i = 0; i < pauseOptions; i++) {
		pauseScreen[i].setFont(font);
		pauseScreen[i].setCharacterSize(80);
		pauseScreen[i].setFillColor(sf::Color::White);
		pauseScreen[i].setPosition(sf::Vector2f((player.getPosition().x) - 85, (player.getPosition().y) + 50 *(i-2)-70));
	}
	pauseScreen[0].setFillColor(sf::Color::Red);


	setInGame();
	//current_state = menu_states::s_ingameMenu;
	selectedItem = 0;
}

void inGameMenu::draw(sf::RenderWindow & window, LvlManager & lvls, std::shared_ptr<Enemy> & enemy)
{
	auto level = lvls.getLevel();
	window.draw(level->getLayer("background"));
	window.draw(level->getLayer("foreground"));
	window.draw(level->getLayer("foreground_dmg"));
	window.draw(level->getLayer("foreground_bounce"));

	window.draw(sf::Sprite(player));
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

int inGameMenu::chooseTile(std::shared_ptr<Menu> & currentMenu, Character & player, sf::Window & window, AnimationManager & ani)
{
	if (selectedItem == 0) {
		//state = STATE::PLAYING;
		return 2;
	}
	else if (selectedItem == 1) {
		std::cout << "option not made yet" << '\n';
	}
	else if (selectedItem == 2) {
		currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y, player);
		std::cout << "terug naar menu";
		setMain();
		//menu_states = menu_states::MAIN;
	}
	else if (selectedItem == 3) {
		window.close();
	}

	return 0;
}