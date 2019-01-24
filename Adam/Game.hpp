#ifndef _GAME_HPP
#define _GAME_HPP

#include "Collision.h"
#include "Character.h"
#include "Movable.h"
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
#include "levelManager.h"
#include "Audio.hpp"

using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f

class Game {
private:
	std::vector<Character*> enemies;
	sf::RenderWindow & window;
	HUD & hud;
	levelManager lvls;
	sf::View main_camera;

	sf::View main_HUD;

	sf::Texture char_alpha;
	sf::Texture char_alpha_invert;
	sf::Texture menuTex;
	Character & player;
	Audio & geluidje;

	sf::Sprite bgMain;
	int bounce_velocity = 1;
	sf::Clock Clock;
	sf::Clock aiClock;
	

	Adam::collision_handler cln_h;

	Adam::physics world_physics;

	std::shared_ptr<Enemy> enemy;

	std::shared_ptr<npc> np;

	std::shared_ptr<AI> ai;
	

	std::shared_ptr<Menu> currentMenu;
	AnimationManager & ani;
	enum class STATE { MENU, PLAYING, GAMEOVER };
	enum STATE state;

public:

	Game(sf::RenderWindow &w, Character &player, HUD &hud, AnimationManager & ani, Audio & geluidje);

	void handleInput();
	void update();
	void render();
	sf::RenderWindow & getWindow() {
		return window;
	}



};



#endif  _GAME_HPP
