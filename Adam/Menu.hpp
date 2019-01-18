#ifndef MENU_HPP
#define MENU_HPP

class Menu {



public:
	int selectedItem;
	
	enum menu_states {s_newGameMenu, s_mainMenu, s_ingameMenu};
	menu_states current_state;

	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void chooseTile(int & tileSelect) = 0;


};


#endif
