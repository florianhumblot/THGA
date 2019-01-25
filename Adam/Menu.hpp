#ifndef MENU_HPP
#define MENU_HPP

#include "Character.h"
#include "AnimationManager.h"
#include "levelManager.h"
#include "Enemy.hpp"

class Menu {
private:
	enum class menu_states { MAIN, NEWGAME, INGAME };
	enum menu_states menu_states = menu_states::MAIN;
	//static bool gameStarted;
public:
	int selectedItem;
	
	

	//enum menu_states {s_newGameMenu, s_mainMenu, s_ingameMenu};
	//menu_states current_state;
	
	virtual void draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player) {}
	virtual void draw(sf::RenderWindow & window, levelManager & lvls, std::shared_ptr<Enemy> & enemy) {}
	virtual void draw(sf::RenderWindow & window, levelManager & lvls, std::shared_ptr<Enemy> & enemy, sf::View & main_camera, sf::Sprite & bgMain, Character & player) {
		if (menu_states == menu_states::INGAME) {
			draw(window, lvls, enemy);
		}
		else {
			draw(window, main_camera, bgMain, player);
		}
	}
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


#endif
