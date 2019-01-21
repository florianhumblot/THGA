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
	float accumulator = 0.f; //total to consume cou
	float ft = 0.0f; //frame time 
	sf::Clock timer;

	Character player(v2(890, 690), v2(0.2, 0.2), ani.animations["mage"], v2(0, 0), statistic(200, 200), statistic(300, 300), statistic(80, 0));
//	Character player(v2(890, 690), v2(0.025, 0.025), "assets/char_alpha.png", v2(0, 0), statistic(200, 200), statistic(300, 300), statistic(80, 0));
	HUD hud(player);
	Game game(window, player, hud);

	while (window.isOpen())
	{
		game.handleInput();
		game.update();
		game.render();
	}
	cout << "done";

	return 0;
}