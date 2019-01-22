#ifndef _MAINMENU_HPP
#define _MAINMENU_HPP

#include "menu.hpp"

#define numberOfTiles 5

class mainMenu : public Menu
{
private:
	float width;
	float heigth;
	sf::Font font;
	sf::Text menuChoices[numberOfTiles];


public:
	mainMenu(float width, float heigth);

	void draw(sf::RenderWindow & window) override;
	void moveUp() override;
	void moveDown() override;
	void chooseTile(int & tileSelect) override;

};




#endif // !MENU_HPP
