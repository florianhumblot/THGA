#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP

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
	Character &player;
public:
	inGameMenu(float width, float heigth, Character &player);

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & titleSelect) override;
};


#endif INGAMEMENU_HPP