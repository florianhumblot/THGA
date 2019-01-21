#include "pch.h"
#include "Game.hpp"
#include "Menu.hpp"

Game::Game(sf::RenderWindow &w, Character &player, HUD &hud) :

	window(w),
	player(player),
	hud(hud)

{

	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	char_alpha = sf::Texture();
	char_alpha_invert = sf::Texture();
	menuTex = sf::Texture();
	Collision::CreateTextureAndBitmask(tex, "assets/backgrounds/underground_cave_c.png");
	bg = Sprite(tex);
	Collision::CreateTextureAndBitmask(tex2, "assets/backgrounds/underground_cave_b.png");
	bg2 = Sprite(tex2);
	Collision::CreateTextureAndBitmask(menuTex, "assets/backgrounds/forest.png");
	bgMain = Sprite(menuTex);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	playerAnimation = AnimationManager("assets/animations/animations.txt");
//	currentAnimation = playerAnimation.animations["gunwoman"]["IDLEleft"];
	
	main_camera.setCenter(player.getPosition());
	main_camera.setSize(700, 350);

	enemy = std::make_shared<Enemy>(v2(2050, 700), v2(0.025, 0.025), "assets/char_alpha.png", v2(0, 0), statistic(200, 200));

	this->cln_h = Adam::collision_handler(bg);
	this->world_physics = Adam::physics(&player, cln_h);

	background.setTexture(tex2);
	ground.setTexture(tex);
	bgMain.setTexture(menuTex);
	pos = player.getPosition();

	
	currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y);

//	std::cout << pos.x << " <posx ";

	ai = std::make_shared<AI>();

	gravity = v2(0, 1);
	Collision::CreateTextureAndBitmask(slimeChar, "assets/slimeTest.png");
	for (int i = 0; i < 5; i++) {
		Character* n = new Character(sf::Vector2f(500 + 100 * i, 1500), sf::Vector2f(0.025, 0.025), "assets/slimeTest.png", sf::Vector2f(0, 0));
		enemies.push_back(n);
		world_physics.moveables.push_back(n);
	}
	world_physics.moveables.push_back(&*enemy);

	state = STATE::MENU;
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
					{
						switch (ev.key.code)
						{
							case sf::Keyboard::Up:
							{
								currentMenu->moveUp();
								break;
							}
							case sf::Keyboard::Down:
							{
								currentMenu->moveDown();
								break;
							}
							case sf::Keyboard::Enter:
							{
								switch (currentMenu->selectedItem)
								{
									case 0:
									{

										if (currentMenu->current_state == Menu::menu_states::s_mainMenu)
										{
											currentMenu = std::make_shared<newGameMenu>(window.getSize().x, window.getSize().y);
										}
										else if (currentMenu->current_state == Menu::menu_states::s_ingameMenu)
										{
											state = STATE::PLAYING;
										}
										break;
									}
									case 1:
									{
										if (currentMenu->current_state == Menu::menu_states::s_mainMenu)
										{
											state = STATE::PLAYING;
										}
										else if (currentMenu->current_state == Menu::menu_states::s_newGameMenu)
										{
											std::cout << "warrior has been chosen" << '\n';
											state = STATE::PLAYING;
										}
										else if (currentMenu->current_state == Menu::menu_states::s_ingameMenu)
										{
											std::cout << "option not made yet" << '\n';
										}

										break;
									}
									case 2:
									{
										if (currentMenu->current_state == Menu::menu_states::s_mainMenu)
										{
											std::cout << "not made yet";
										}
										else if (currentMenu->current_state == Menu::menu_states::s_newGameMenu)
										{
											std::cout << "hunter has been chosen" << '\n';
											state = STATE::PLAYING;

										}
										else if (currentMenu->current_state == Menu::menu_states::s_ingameMenu)
										{

										}
										break;
									}
									case 3:
									{
										if (currentMenu->current_state == Menu::menu_states::s_mainMenu)
										{
											std::cout << "option menu not made yet" << std::endl;
										}
										else if (currentMenu->current_state == Menu::menu_states::s_ingameMenu)
										{
											std::cout << "option menu not made yet" << std::endl;

										}
										break;
									}
									case 4:
									{
										window.close();
										break;
									}

								}
								break;
							}
							case sf::Keyboard::BackSpace:
							{
								currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y);
								break;
							}
						}
						break;
					}
				}
			}
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
					player.setVelocity(sf::Vector2f(player.getVelocity().x, -9));
					player.update_exp(2);
					player.update_info();
					hud.update();
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				state = STATE::MENU;
				currentMenu = std::make_shared<inGameMenu>(window.getSize().x, window.getSize().y);
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (player.getCurrentAnimation() != player.getAnimation("WALKright")) {
					player.setAnimation("WALKright");
				}

				player.setScale(sf::Vector2f(0.2, 0.2));
				player.setVelocity(sf::Vector2f(4, player.getVelocity().y));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (player.getCurrentAnimation() != player.getAnimation("WALKright")) {
					player.setAnimation("WALKright");
				}
				player.setScale(sf::Vector2f(-0.2, 0.2));

				player.setVelocity(sf::Vector2f(-4, player.getVelocity().y));

			}
			else
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
				if (player.getVelocity().y == 0) {
					if (player.getCurrentAnimation() != player.getAnimation("IDLEright")) {
						player.setAnimation("IDLEright");
					}
				}
			}

			
			ai->shouldFollow_followDirection(*enemy, player);
			

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
			if (Clock.getElapsedTime().asMilliseconds() >= 100) {
				player.setTexture(player.currentAnimation.nextFrame());
			//	std::cout << sf::Sprite(player).getGlobalBounds().height << ", :w";
				Clock.restart();
			}

			world_physics.step_x_moveables();
			world_physics.step_y_moveables();
			if (player.getPosition().y > 4000) player.setPosition(v2(100, 100));
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

		window.clear();
		window.draw(bgMain);
		currentMenu->draw(window);
		window.display();

		break;
	}


	case STATE::PLAYING:
	{
		window.clear();
		window.draw(background);
		//sf::Vector2f pos_info = sf::Vector2f(player.getPosition().x, player.getPosition().y - 100);
		//player.update_info_pos(window,pos_info);
		window.draw(sf::Sprite(player));
		window.draw(sf::Sprite(*enemy));
		for (auto & enemy : enemies) {
			//				std::cout << enemy->getPosition().y << ", <POSy " << enemy->getPosition().x << ", <POSx ";
			//				std::cout << enemy->getVelocity().y << ", <VEL \n";
			window.draw(enemy->operator sf::Sprite());


		}
		enemy->update_info_pos(window);
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
	return;
}