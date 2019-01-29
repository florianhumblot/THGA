#pragma once

#include "pch.h"
#include "Character.h"
#include "AnimationManager.h"
#include "LvlManager.h"
#include "Enemy.hpp"

class Menu {
private:
	enum class menu_states { MAIN, NEWGAME, INGAME };
	enum menu_states menu_states = menu_states::MAIN;
public:
	int selectedItem;

	virtual void draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player) {}
	virtual void draw(sf::RenderWindow & window, LvlManager & lvls, std::shared_ptr<Enemy> & enemy) {}
	virtual void draw(sf::RenderWindow & window, LvlManager& lvls, std::shared_ptr<Enemy> & enemy, sf::View & main_camera, sf::Sprite & bgMain, Character & player);

	virtual void moveUp() = 0;
	virtual void moveDown() = 0;

	virtual int chooseTile(std::shared_ptr<Menu> & currentMenu, Character & player, sf::Window & window, AnimationManager & ani) = 0;

	void setInGame() {
		menu_states = menu_states::INGAME;
	}
	void setMain() {
		menu_states = menu_states::MAIN;
	}
	void setNewGame() {
		menu_states = menu_states::NEWGAME;
	}
	
};
