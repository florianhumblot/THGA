#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP
#include <vector>

#include "menu.hpp"
#include "Character.h"
#include "game.hpp"

#define pauseOptions 4

class inGameMenu: public Menu
{
private:
	float width;
	float heigth;
	sf::Font font;
	sf::Text pauseScreen[pauseOptions];
	sf::Sprite sprite;
	sf::Texture texture;
	Character &player;
public:
	inGameMenu(float width, float heigth, Character &player):
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
		pauseScreen[0].setPosition(sf::Vector2f((player.getPosition().x)-100, (player.getPosition().y)-100));

		pauseScreen[1].setFont(font);
		pauseScreen[1].setString("Load Game");
		pauseScreen[1].setFillColor(sf::Color::White);
		pauseScreen[1].setCharacterSize(80);
		pauseScreen[1].setPosition(sf::Vector2f((player.getPosition().x), (player.getPosition().y)-50));

		pauseScreen[2].setFont(font);
		pauseScreen[2].setString("Options");
		pauseScreen[2].setFillColor(sf::Color::White);
		pauseScreen[2].setCharacterSize(80);
		pauseScreen[2].setPosition(sf::Vector2f((player.getPosition().x), (player.getPosition().y)));

		pauseScreen[3].setFont(font);
		pauseScreen[3].setString("Quit Game");
		pauseScreen[3].setFillColor(sf::Color::White);
		pauseScreen[3].setCharacterSize(80);
		pauseScreen[3].setPosition(sf::Vector2f((player.getPosition().x), (player.getPosition().y)+50));


		current_state = menu_states::s_ingameMenu;
		selectedItem = 0;
		std::cout << " constructed ingame menu" << std::endl;
	}

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & titleSelect) override;
};


#endif INGAMEMENU_HPP