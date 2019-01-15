#include "Game.hpp"

Game::Game(sf::RenderWindow &w) :

	window(w)

{
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture tex;
	Collision::CreateTextureAndBitmask(tex, "assets/background.png");
	sf::Sprite bg(tex);

	sf::Texture tex2;
	Collision::CreateTextureAndBitmask(tex2, "assets/gradient.png");
	sf::Sprite bg2(tex2);


	sf::Texture char_alpha;
	sf::Texture char_alpha_invert;
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	player = Character(sf::Vector2f(100, 100), sf::Vector2f(0.15, 0.15), "assets/char_alpha.png", sf::Vector2f(0, 0));

	background.setTexture(tex2);
	terrain.setTexture(tex);
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
	window.draw(background);
	window.draw(player);

}