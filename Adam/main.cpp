#include <stdlib.h>
#include "mainMenu.hpp"
#include "SFML/Graphics.hpp"
#include "Windows.h"
#include "Collision.h"
#include <iostream>
#include <cmath>
#include "Character.h"
#include "AnimationManager.h"
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



	v2 pos = player.getPosition();
	auto gravity = v2(0, 1);
	AnimationManager a("assets/animations/animations.txt");
	a.print();
	while (1) {
		for (auto elem : a.animations) {
			for (auto t : elem.second) {
				Animation anim = t.second;
				while (window.isOpen())
				{
					Event ev;
					while (window.pollEvent(ev))
					{
						switch (ev.type)
						{
						case Event::Closed:
						{
							window.close();
							break;
						}
						}
						if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); }
						if (ev.type == ev.KeyReleased && ev.key.code == sf::Keyboard::Space)
						{
							player.setVelocity(sf::Vector2f(player.getVelocity().x, -14));
						}
					}
					window.clear();
					player.setTexture(anim.nextFrame());
					window.draw(sf::Sprite(player));
					window.display();
					if (anim.isDone()) {
						break;
					}
					sf::sleep(sf::milliseconds(80));
				}
			}
		}
	}

	while (window.isOpen())
	{
		ft = timer.getElapsedTime().asSeconds();
		timer.restart();
		accumulator += ft;
		//std::cout << "acc: " << accumulator << std::endl;
		while (accumulator >= dt)
		{
			game.handleInput();
			game.update();
			accumulator -= dt;
		}

		//draw everything

		game.render();
	}
	cout << "done";

	return 0;
}