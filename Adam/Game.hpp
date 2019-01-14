#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
private:

	const struct {
		sf::Keyboard::Key key;
		float x; float y;
	} actions[] = {
	   { sf::Keyboard::Left,  -1.0,  0.0 },
	   { sf::Keyboard::Right, +1.0,  0.0 },
	   { sf::Keyboard::Up,     0.0, -1.0 },
	   { sf::Keyboard::Down,   0.0, +1.0 }
	};



public:
	
	Game() {}
	
	void handleInput() {

	}
	void update() {}
	void Render() {}

	

};



#endif // _GAME_HPP

