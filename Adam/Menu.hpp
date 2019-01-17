#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

class Menu {

public:
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void chooseTile(int & tileSelect) = 0;


};


#endif
