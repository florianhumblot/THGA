#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <functional>

class Game {
private:

	sf::RenderWindow & window;
	sf::CircleShape shape;



	const struct {
		sf::Keyboard::Key key;
		std::function<void(void)> actionLambda;
	} actions[4] = {
	   { sf::Keyboard::A,  []() {} },
	   { sf::Keyboard::D, []() {} },
	   { sf::Keyboard::Escape, []() {} },
	   { sf::Keyboard::Space, []() {}  }
	};



public:
	
	Game(sf::RenderWindow &w);
	
	void handleInput();
	void update();
	void render();

	

};



#endif // _GAME_HPP

