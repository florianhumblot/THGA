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

int main()
{
	RenderWindow window(VideoMode(1920, 1080, 32), "Project: ADAM");
	AnimationManager ani("assets/animations/animations.txt");

	Character player(sf::Vector2f(890, 690), sf::Vector2f(0.2, 0.2), ani.animations["mage"], sf::Vector2f(0, 0), statistic(200, 200), statistic(300, 300), statistic(80, 0));
	HUD hud(player);
	Game game(window, player, hud, ani);
	
	while (window.isOpen())
	{
		game.handleInput();
		game.update();
		game.render();
	}

	return 0;
}