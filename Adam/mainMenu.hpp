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
	mainMenu(float width, float heigth, Character &player);

	void draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player) override;
	void moveUp() override;
	void moveDown() override;
	int chooseTile(std::shared_ptr<Menu> &currentMenu, Character & player, sf::Window & window, AnimationManager & ani) override;

};




#endif // !MENU_HPP
