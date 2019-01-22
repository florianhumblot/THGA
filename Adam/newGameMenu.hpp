#ifndef NEWGAMEMENU_HPP
#define NEWGAMEMENU_HPP

#include "menu.hpp"

#define newGameTiles 5

class newGameMenu : public Menu
{
private:
	float width;
	float heigth;
	sf::Font font;
	sf::Text menuChoices[newGameTiles];
public:
	newGameMenu(float width, float heigth);

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & tileSelect) override;
};



#endif NEWGAMEMENU_HPP
