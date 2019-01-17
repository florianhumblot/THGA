#include "Game.hpp"

Game::Game(sf::RenderWindow &w, Character &player, mainMenu &menu, HUD &hud) :

	window(w),
	player(player),
	menu(menu),
	hud(hud)

{

	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	char_alpha = sf::Texture();
	char_alpha_invert = sf::Texture();
	Collision::CreateTextureAndBitmask(tex, "assets/backgrounds/tiles2.png");
	bg = Sprite(tex);
	Collision::CreateTextureAndBitmask(tex2, "assets/backgrounds/background2.png");
	bg2 = Sprite(tex2);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	main_camera.setCenter(player.getPosition());
	main_camera.setSize(1600, 900);

	this->cln_h = Adam::collision_handler(bg);
	this->world_physics = Adam::physics(&player, cln_h);

	background.setTexture(tex2);
	ground.setTexture(tex);
	pos = player.getPosition();


	gravity = v2(0, 1);
	Collision::CreateTextureAndBitmask(slimeChar, "assets/slimeTest.png");
	for (int i = 0; i < 5; i++) {
		enemies.push_back(Character(sf::Vector2f(200 + i * 100, 1500), sf::Vector2f(5.f, 5.f), "assets/slimeTest.png", sf::Vector2f(0, 0)));

	}

	state = STATE::PLAYING;
}


void Game::handleInput() {
	
	//do game stuff
	switch (state) {

		case STATE::MENU:
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
					case sf::Event::KeyPressed:
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
			menu.draw(window);
			window.display();
			break;
		}



		case STATE::PLAYING:
		{
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

				if (ev.type == Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
				{
					player.setVelocity(sf::Vector2f(player.getVelocity().x, -14));
					player.update_exp(2);
					player.update_info();
					hud.update();
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.setScale(sf::Vector2f(-1, 1));
				player.setVelocity(sf::Vector2f(8, player.getVelocity().y));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				player.setScale(sf::Vector2f(1, 1));
				player.setVelocity(sf::Vector2f(-8, player.getVelocity().y));
			}
			else
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
			}
			break;
		}
	}


}

void Game::update() {

	switch (state) {

		case STATE::MENU:
		{
			break;
		}



		case STATE::PLAYING:
		{
			world_physics.step_x_moveables();
			world_physics.step_y_moveables();
		}
		break;
	}

/*	for (auto & object : enemies) {
		object.setVelocity(object.getVelocity() + gravity);
		object.move();

	}*/


}

void Game::render() {
	switch (state) {

		case STATE::MENU:
		{
			
			break;
		}

		case STATE::PLAYING:
		{
			window.clear();
			window.draw(background);
			//sf::Vector2f pos_info = sf::Vector2f(player.getPosition().x, player.getPosition().y - 100);
			//player.update_info_pos(window,pos_info);
			window.draw(sf::Sprite(player));
			for (auto & enemy : enemies) {
				enemy.setTexture(slimeChar);
				window.draw(enemy);

			}
			window.draw(ground);
			window.setView(main_HUD);
			hud.draw(window);
			auto center = Collision::GetSpriteCenter(player);
			main_camera.setCenter(center);
			window.setView(main_camera);
			window.display();
			break;

		}
	}


}