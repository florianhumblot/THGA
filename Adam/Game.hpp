#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include "Windows.h"
#include "Collision.h"
#include <iostream>
#include <cmath>
#include "Character.h"

using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f

class Game {
private:

	sf::RenderWindow & window;
	sf::CircleShape shape;

	sf::View main_camera;
	sf::Texture tex;
	Sprite bg;
	Sprite bg2;
	sf::Texture tex2;
	sf::Texture char_alpha;
	sf::Texture char_alpha_invert;
	Character & player;
	sf::Sprite background;
	sf::Sprite ground;

	v2 pos;
	v2 gravity;

	const struct {
		sf::Keyboard::Key key;
		std::function<void(void)> actionLambda;
	} actions[4] = {
	   { sf::Keyboard::A,  []() {} },
	   { sf::Keyboard::D, []() {} },
	   { sf::Keyboard::Escape,[this]() {getWindow().close();} },
	   { sf::Keyboard::Space, []() {}  }
	};



public:
	
	Game(sf::RenderWindow &w, Character &player);
	
	void handleInput();
	void update();
	void render();

	sf::RenderWindow & getWindow() {
		return window;
	}

	

};



#endif // _GAME_HPP

