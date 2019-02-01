#pragma once
// ==========================================================================
//
// File      :Menu.hpp
//
// ==========================================================================

// this file contains Doxygen lines
///file Menu.hpp
/// \brief- menu interface parent class
/// \details
/// This class serves as way to make all menu's accesible through the same family characteristics
#include "pch.h"
#include "Character.h"
#include "AnimationManager.h"
#include "LvlManager.h"
#include "Enemy.hpp"

class Menu {
public:
	enum class menu_states { MAIN, NEWGAME, INGAME };
	menu_states menu_states = menu_states::MAIN;

	int selectedItem;

	/// \brief
	/// virtual interface for drawing the menu when the menu adjust its position by the player position
	virtual void draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player) {}

	/// \brief
	/// virtual interface for drawing the menu
	virtual void draw(sf::RenderWindow & window, LvlManager & lvls) {}

	/// \brief
	/// (virtual) interface for drawing the menu.
	/// \detail
	/// This calls the right drawfuntion, by the state of the menu
	virtual void draw(sf::RenderWindow & window, LvlManager& lvls, sf::View & main_camera, sf::Sprite & bgMain, Character & player);

	/// \brief
	/// (virtual) interface for adjusting your menuchoice tile
	virtual void moveUp() = 0;

	/// \brief
	/// (virtual) interface for adjusting your menuchoice tile
	virtual void moveDown() = 0;

	/// \brief
	/// (virtual) interface for handling the chosen menuoption
	virtual int chooseTile(std::shared_ptr<Menu> & currentMenu, Character & player, sf::Window & window, AnimationManager & ani) = 0;

	/// \brief
	/// changes state to inGame
	void setInGame() {
		menu_states = menu_states::INGAME;
	}

	/// \brief
	/// changes state to main
	void setMain() {
		menu_states = menu_states::MAIN;
	}

	/// \brief
	/// changes state to newgame
	void setNewGame() {
		menu_states = menu_states::NEWGAME;
	}
	
};
