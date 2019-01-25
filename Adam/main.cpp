#include "pch.h"
#include "mainMenu.hpp"
#include "Collision.h"
#include "Character.h"
#include "Game.hpp"
#include "HUD.hpp"
#include "statistic.h"
#include "AnimationManager.h"
#include "Audio.hpp"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1920, 1080, 32), "Project: ADAM", sf::Style::None);
	
	sf::Sprite loading_screen;
	sf::Texture loading;
	loading.loadFromFile("assets/loading.png");
	loading_screen.setTexture(loading);
	window.draw(loading_screen);
	window.display();
	AnimationManager ani("assets/animations/animations.txt");
	

	sf::Event e;
	while (window.pollEvent(e))
	{
		window.clear(sf::Color::Yellow);
	}

	Character player(sf::Vector2f(890, 690), sf::Vector2f(0.2, 0.2), ani.animations["mage"], sf::Vector2f(0, 0), statistic(200, 200), statistic(300, 300), statistic(80, 0));
	Audio geluidje;

	HUD hud(player);
	Game game(window, player, hud, ani, geluidje);
	
	while (window.isOpen())
	{
		game.handleInput();
		game.update();
		game.render();

	}

	return 0;
}