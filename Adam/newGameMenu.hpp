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
	newGameMenu(float width, float heigth, Character & player);

	void draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player) override;
	void moveUp() override;
	void moveDown() override;
	int chooseTile(std::shared_ptr<Menu> & currentMenu, Character & player, sf::Window & window, AnimationManager & ani) override;
};



#endif NEWGAMEMENU_HPP
