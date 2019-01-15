#include "SFML/Graphics.hpp"
#include "Windows.h"
#include "Collision.h"
#include <iostream>
#include <cmath>
#include "Character.h"
using namespace std;
using namespace sf;

#define v2i sf::Vector2i
#define v2 sf::Vector2f


int main()
{
	RenderWindow window(VideoMode(1920, 1080, 32), "APPLICATION");
	sf::View main_camera;
	window.setVerticalSyncEnabled(true);

	float dt = 1.f / 60.f; //fixed physics step
	float accumulator = 0.f; //total to consume from
	float ft = 0.0f; //frame time 
	sf::Clock timer;

	sf::Texture tex;
	Collision::CreateTextureAndBitmask(tex, "assets/background.png");
	Sprite bg(tex);

	sf::Texture tex2;
	Collision::CreateTextureAndBitmask(tex2, "assets/gradient.png");
	Sprite bg2(tex2);

	sf::Texture char_alpha;
	sf::Texture char_alpha_invert;
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	Character player(v2(100, 100), v2(0.15, 0.15), "assets/char_alpha.png", v2(0, 0));
	

	main_camera.setCenter(player.getPosition());
	main_camera.setSize(1600, 900);

	sf::Sprite background;
	background.setTexture(tex2);

	sf::Sprite ground;
	ground.setTexture(tex);

	v2 pos = player.getPosition();
	auto gravity = v2(0, 1);

	while (window.isOpen())
	{
		ft = timer.getElapsedTime().asSeconds();
		timer.restart();
		accumulator += ft;
		std::cout << "acc: " << accumulator << std::endl;
		while (accumulator >= dt)
		{
			//do game stuff
			v2 current_pos = player.getPosition();

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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (player.current_direction != Character::direction::RIGHT)
				{
					player.current_direction = Character::direction::RIGHT;
					player.setTexture(char_alpha);
				}
				player.setVelocity(sf::Vector2f(8, player.getVelocity().y));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (player.current_direction != Character::direction::LEFT) {
					player.current_direction = Character::direction::LEFT;
					player.setTexture(char_alpha_invert);
				}
				player.setVelocity(sf::Vector2f(-8, player.getVelocity().y));
			}
			else
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
			}

			//move on x
			player.move(sf::Vector2f(player.getVelocity().x, 0));

			//if we collide, we know it's on the x axis, so we move back and set our x velocity to 0
			if (Collision::PixelPerfectTest(player, ground))
			{
				player.move(sf::Vector2f(-player.getVelocity().x, 0));
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
			}

			player.move(v2(0, player.getVelocity().y));

			if (Collision::PixelPerfectTest(player, ground) && player.getVelocity().y > 0)
			{
				while (Collision::PixelPerfectTest(player, ground))
				{
					player.move(v2(0, -0.5));
				}
				player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
			}
			else if (Collision::PixelPerfectTest(player, ground) && player.getVelocity().y < 0)
			{
				while (Collision::PixelPerfectTest(player, ground))
				{
					player.move(v2(0, 0.5));
				}
				player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
			}
			else
			{
				player.setVelocity(player.getVelocity() + gravity);
			}
			accumulator -= dt;
		}

		if (player.getPosition().y > 4000) player.setPosition(v2(100, 100));

		//draw everything
		window.clear();
		window.draw(background);
		window.draw(player);
		window.draw(ground);

		auto center = Collision::GetSpriteCenter(player);
		main_camera.setCenter(center);
		window.setView(main_camera);
		window.display();
	}

	return 0;
}