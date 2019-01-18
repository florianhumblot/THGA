#include "pch.h"
#include "mainMenu.hpp"
#include "Collision.h"
#include "Character.h"
#include "Game.hpp"
#include "HUD.hpp"
#include "statistic.h"
#include "AnimationManager.h"

using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f


int main()
{
	RenderWindow window(VideoMode(1920, 1080, 32), "APPLICATION");
	AnimationManager ani("assets/animations/animations.txt");
	float dt = 1.f / 60.f; //fixed physics step
	float accumulator = 0.f; //total to consume from
	float ft = 0.0f; //frame time 
	sf::Clock timer;

	Character player(v2(110, 100), v2(1, 1), "assets/char_alpha.png", v2(0, 0), ani.animations["gunwoman"], statistic(200, 200), statistic(300, 300), statistic(80, 0));
	HUD hud(player);
	mainMenu menu(window.getSize().x, window.getSize().y);
	Game game(window, player, menu, hud);

	while (window.isOpen())
	{
		game.handleInput();
		game.update();
		game.render();
	}
	cout << "done";

	return 0;
}