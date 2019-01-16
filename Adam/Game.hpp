#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include "Windows.h"
#include "Collision.h"
#include <iostream>
#include <cmath>
#include "Character.h"
#include "Movable.h"
#include "mainMenu.hpp"
#include "statistic.hpp"
#include "physics.h"
#include "HUD.hpp"

using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f

class Game {
private:
	std::vector<Character> gameObjects;
	sf::RenderWindow & window;
	mainMenu & menu;
	HUD & hud;
	sf::CircleShape shape;
	sf::View main_camera;
	sf::Texture tex;
	sf::View main_HUD;
	Sprite bg;
	Sprite bg2;
	sf::Texture tex2;
	sf::Texture char_alpha;
	sf::Texture char_alpha_invert;
	Character & player;
	sf::Sprite background;
	sf::Sprite ground;

	sf::Texture slimeChar;

	Adam::collision_handler cln_h;
	Adam::physics world_physics;

	v2 pos;
	v2 gravity;

	enum class STATE { MENU, PLAYING, GAMEOVER };
	enum STATE state;



public:

	Game(sf::RenderWindow &w, Character &player, mainMenu &mainmenu, HUD &hud);

	void handleInput();
	void update();
	void render();

	sf::RenderWindow & getWindow() {
		return window;
	}



};



#endif  _GAME_HPP

