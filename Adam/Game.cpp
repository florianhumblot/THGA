#include "pch.h"
#include "Game.hpp"
#include "Menu.hpp"
#include "npc.hpp"

Game::Game(sf::RenderWindow &w, Character &player, HUD &hud, AnimationManager & ani) :

	window(w),
	player(player),
	hud(hud)

{
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	char_alpha = sf::Texture();
	char_alpha_invert = sf::Texture();
	menuTex = sf::Texture();
	//Collision::CreateTextureAndBitmask(tex, "assets/backgrounds/UBGv2.png");
	//bg = Sprite(tex);
	//Collision::CreateTextureAndBitmask(tex2, "assets/backgrounds/underground_cave_bv2.png");
	//bg2 = Sprite(tex2);
	//Collision::CreateTextureAndBitmask(tex3, "assets/backgrounds/underground_cave_spikesLayer.png");
	//bg3 = Sprite(tex3);
	Collision::CreateTextureAndBitmask(menuTex, "assets/backgrounds/forest.png");
	bgMain = Sprite(menuTex);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");
	lvls.make_lvl("lvl1");
	
	main_camera.setCenter(player.getPosition());
	main_camera.setSize(640, 360);

	np = std::make_shared<npc>(v2(890, 690), v2(0.25, 0.25), ani.animations["skull"], v2(0, 0), statistic(200, 200));
	enemy = std::make_shared<Enemy>(v2(2050, 700), v2(0.2, 0.2), ani.animations["skull"], v2(0, 0), statistic(200, 200));

	this->cln_h = Adam::collision_handler(lvls.bg);
	//this->cln_h2 = Adam::collision_handler(bg3);
	this->world_physics = Adam::physics(&player, cln_h);

	//background.setTexture(tex2);
	//ground.setTexture(tex);
	//damage_background.setTexture(tex3);
	bgMain.setTexture(menuTex);

	
	currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y);


	ai = std::make_shared<AI>();

	world_physics.moveables.push_back(&*enemy);
	world_physics.moveables.push_back(&*np);

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
											window.close();

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
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				state = STATE::MENU;
				currentMenu = std::make_shared<inGameMenu>(window.getSize().x, window.getSize().y, player);
				
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				//window.close();
				state = STATE::MENU;
				currentMenu = std::make_shared<inGameMenu>(window.getSize().x, window.getSize().y, player);
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (player.getCurrentAnimation() != std::string("WALKright")) {
					player.setAnimation("WALKright");
					player.setTexture(player.currentAnimation.nextFrame());
				}

				player.setScale(sf::Vector2f(0.2, 0.2));
				player.setVelocity(sf::Vector2f(4, player.getVelocity().y));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (player.getCurrentAnimation() != std::string("WALKright")) {
					player.setAnimation("WALKright");
					player.setTexture(player.currentAnimation.nextFrame());
				}
				player.setScale(sf::Vector2f(-0.2, 0.2));

				player.setVelocity(sf::Vector2f(-4, player.getVelocity().y));

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
				player.fight(enemy.get());
				std::cout << "health enemÿ: " << enemy.get()->health.current << "\n";
			}
			else
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
				if (player.getVelocity().y == 0) {
					if (player.getCurrentAnimation() != std::string("IDLEright")) {
						player.setAnimation("IDLEright");
						player.setTexture(player.currentAnimation.nextFrame());
					}
				}
			}

			ai->shouldFollow_followDirection(enemy.get(), &player);

			
			break;
		}
	}


}

void Game::update() {

	switch (state) 
	{
		case STATE::MENU:
		{
			break;
		}

		case STATE::PLAYING:
		{
			if (Clock.getElapsedTime().asMilliseconds() >= 100) {
				player.setTexture(player.currentAnimation.nextFrame());
				enemy->setTexture(enemy->currentAnimation.nextFrame());
				Clock.restart();
			}

			world_physics.step_x_moveables();
			world_physics.step_y_moveables();
			if (Collision::PixelPerfectTest(lvls.fg_dmg, player))
			{
				player.health.sub(1);

			}
			hud.update();
			if (player.health.is_zero())
			{
				player.setPosition(sf::Vector2f(890, 690));
				player.health.current = player.health.max;
			}
			enemy->update_info_pos(window);
			player.checkDead();
			enemy.get()->checkDead();

		}
		break;

	}
}

void Game::render() {
	switch (state)
	{

	case STATE::MENU:
	{

		if (currentMenu->current_state == Menu::menu_states::s_ingameMenu)
		{
			window.clear();
			window.draw(lvls.background);
			window.draw(lvls.ground);
			window.draw(lvls.damage_background);
			window.draw(sf::Sprite(player));
			window.draw(sf::Sprite(*enemy));
			currentMenu->draw(window);
			window.display();
		}
		else
		{
			window.clear();
			window.draw(bgMain);
			currentMenu->draw(window);
			window.display();
		}
		break;
	}


	case STATE::PLAYING:
	{
		window.clear();
		window.draw(lvls.background);
		window.draw(sf::Sprite(player));
		window.draw(sf::Sprite(*enemy));
		for (auto & enemy : enemies) {
			window.draw(enemy->operator sf::Sprite());
		}
		window.draw(lvls.ground);
		window.draw(lvls.damage_background);
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