#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <functional>

class Game {
private:

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
	
	Game() {}
	
	void handleInput() {
		for (auto& action : actions) {
			if (sf::Keyboard::isKeyPressed(action.key)) {
				action.actionLambda();
			}
		}

	}
	void update() {}
	void render() {}

	

};



#endif // _GAME_HPP

