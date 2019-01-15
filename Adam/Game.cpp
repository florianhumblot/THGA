#include "Game.hpp"

Game::Game(sf::RenderWindow &w) :

	window(w)

{
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);
}


void Game::handleInput() {
	for (auto& action : actions) {
		if (sf::Keyboard::isKeyPressed(action.key)) {
			action.actionLambda();
		}
	}

}


void Game::update() {

	window.clear();
	window.draw(shape);
	window.display();

}

void Game::render() {


}