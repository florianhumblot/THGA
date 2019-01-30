#pragma once
// ==========================================================================
//
// File      : Game.hpp
//
// ==========================================================================

// this file contains Doxygen lines
///file Game.hpp
/// \brief Game class.


#include "Collision.h"
#include "Character.h"
#include "Movable.h"
#include "projectile.hpp"
#include "mainMenu.hpp"
//#include "statistic.h"
#include "physics.h"
#include "HUD.hpp"

#include "AnimationManager.h"

#include "menu.hpp"
#include "newGameMenu.hpp"
#include "Enemy.hpp"
#include "ingameMenu.hpp"
#include "AI.hpp"
#include "fighter.h"
#include "Audio.h"
#include "LvlManager.h"
#include "npc.hpp"

using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f

class Game {
private:
	sf::RenderWindow & window;

	std::vector<Enemy> enemies;
	std::vector<npc> npcs;
	std::vector<std::shared_ptr<projectile>> projectiles;

	LvlManager lvl;
	HUD & hud;
	bool rerender = false;
	sf::View main_camera;
	sf::View main_HUD;

	sf::Texture char_alpha;
	sf::Texture char_alpha_invert;
	sf::Texture menuTex;
	sf::Texture mouse_texture;
	sf::Texture damage_texture;

	Character & player;
	Audio & geluidje;

	sf::Sprite bgMain;
	sf::Sprite cursor;
	sf::Sprite damage_overlay;
	int bounce_velocity = 1;

	sf::Clock Clock;
	sf::Clock aiClock;
	sf::Clock manaClock;
	sf::Clock healthClock;

	Adam::collision_handler cln_h;
	Adam::physics world_physics;

	std::shared_ptr<Enemy> enemy;
	std::shared_ptr<npc> np;
	std::shared_ptr<Menu> currentMenu;

	sf::Texture tex;

	std::shared_ptr<AI> ai;
	
	AnimationManager & ani;
	enum class STATE { MENU, PLAYING, GAMEOVER };
	enum STATE state;

public:

	/// \brief construct a game class. 
	Game(sf::RenderWindow &w, Character &player, HUD &hud, AnimationManager & ani, Audio & geluidje);

	/// \brief Handle the gameinput
	/// \detail
	/// Inputhandling depends on the state (menu or playing)
	/// It also depends on the players state
	void handleInput();

	/// \brief Update gameplay
	/// \detail
	/// Inputhandling depends on the state (menu or playing)
	/// Only when the state is Playing, the game will be updated
	void update();

	/// \brief Render game
	/// \detail
	/// Rendering depends on the state (menu or playing) 
	/// State menu shows the current menu
	/// state playing shows the game
	void render();

	/// \brief Returns game
	sf::RenderWindow & getWindow() {
		return window;
	}
};


