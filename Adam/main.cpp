#include <stdlib.h>
#include "mainMenu.hpp"
#include "SFML/Graphics.hpp"
#include "Windows.h"
#include "Collision.h"
#include <iostream>
#include <cmath>
#include "Character.h"
#include "Game.hpp"
using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f


int main()
{
		//mainMenu mainmenu(window.getSize().x, window.getSize().y);

	RenderWindow window(VideoMode(1920, 1080, 32), "APPLICATION");
	


	float dt = 1.f / 60.f; //fixed physics step
	float accumulator = 0.f; //total to consume from
	float ft = 0.0f; //frame time 
	sf::Clock timer;
	Character player(v2(100, 100), v2(0.15, 0.15), "assets/char_alpha.png", v2(0, 0));
	Game game(window, player);
	mainMenu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			switch (ev.type)
			{
			case sf::Event::KeyReleased:
				switch (ev.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;

				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				}
			}
		}

		ft = timer.getElapsedTime().asSeconds();
		timer.restart();
		accumulator += ft;
		//std::cout << "acc: " << accumulator << std::endl;
		//menu.draw(window);
		while (accumulator >= dt)
		{
			//game.handleInput();
			//game.update();
			accumulator -= dt;
		}
		window.clear();
		menu.draw(window);
		window.display();
		//draw everything
		//game.render();
	}
	cout << "done";

	return 0;
}