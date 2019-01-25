#include "pch.h"
#include "Game.hpp"
#include "Menu.hpp"
#include "npc.hpp"
#include "Audio.hpp"

Game::Game(sf::RenderWindow &w, Character &player, HUD &hud, AnimationManager & ani, Audio & geluidje) :

	window(w),
	player(player),
	hud(hud),
	ani(ani),
	geluidje(geluidje)
{
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	char_alpha = sf::Texture();
	char_alpha_invert = sf::Texture();
	menuTex = sf::Texture();

	Collision::CreateTextureAndBitmask(menuTex, "assets/backgrounds/forest.png");
	bgMain = Sprite(menuTex);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");
	lvls.next_lvl(player);

	main_camera.setCenter(player.getPosition());
	main_camera.setSize(640, 360);

	np = std::make_shared<npc>(v2(890, 690), v2(0.2, 0.2), ani.animations["boy"], v2(0, 0), statistic(200, 200));
	enemy = std::make_shared<Enemy>(v2(2050, 700), v2(0.2, 0.2), ani.animations["skull"], v2(0, 0), statistic(200, 200));

	this->cln_h = Adam::collision_handler(lvls.ground);

	this->world_physics = Adam::physics(&player, cln_h);

	bgMain.setTexture(menuTex);
	sf::Vector2f playerposforbg = player.getPosition();
	bgMain.setPosition(sf::Vector2f(playerposforbg.x - 960, playerposforbg.y - 540));

	currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y, player);


	ai = std::make_shared<AI>();

	world_physics.moveables.push_back(&*enemy);
	world_physics.moveables.push_back(&*np);

	state = STATE::MENU;
}




void Game::handleInput()
{
	//do game stuff
	switch (state)
	{
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
					int menuResult = currentMenu->chooseTile(currentMenu->selectedItem, currentMenu, player, window, ani);
					// if 0, do nothing
					if (menuResult == 1) {
						state = STATE::MENU;
					}
					else if (menuResult == 2) {
						main_camera.setCenter(player.getPosition());
						main_camera.setSize(640, 360);
						state = STATE::PLAYING;
					}
					else if (menuResult == 3) {
						state = STATE::GAMEOVER;
					}
					break;
				}
				case sf::Keyboard::BackSpace:
				{
					currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y, player);
					break;
				}
				}
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
				player.canJump = false;

				if (player.jumpCount < 2)
				{
					player.setVelocity(sf::Vector2f(player.getVelocity().x, -9));
					player.jumpCount++;
				}
			}


			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && !player.checkDead())
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
				player.fight(enemy.get());
				std::cout << "health enemÿ: " << enemy.get()->health.current << "\n";
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


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !player.checkDead())
		{
			if (player.getCurrentAnimation() != std::string("WALKright")) {
				player.setAnimation("WALKright");
				player.setTexture(player.currentAnimation.nextFrame());
			}

			player.setScale(sf::Vector2f(0.2, 0.2));
			player.setVelocity(sf::Vector2f(4, player.getVelocity().y));

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !player.checkDead())
		{
			if (player.getCurrentAnimation() != std::string("WALKright")) {
				player.setAnimation("WALKright");
				player.setTexture(player.currentAnimation.nextFrame());

			}
			player.setScale(sf::Vector2f(-0.2, 0.2));

			player.setVelocity(sf::Vector2f(-4, player.getVelocity().y));

		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && !player.checkDead())
		{
			player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
			player.fight(enemy.get());
			std::cout << "health enemÿ: " << enemy.get()->health.current << "\n";
		}

		else if (player.currentAnimation.isDone() || player.getCurrentAnimation() == std::string("WALKright"))
		{
			player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
			if (player.getVelocity().y == 0) {
				if (player.getCurrentAnimation() != std::string("IDLEright") && player.getCurrentAnimation() != std::string("DYINGright")) {
					player.setAnimation("IDLEright");
					player.setTexture(player.currentAnimation.nextFrame());
				}
			}
		}

		if (ev.type == sf::Event::KeyReleased) {
			if (ev.key.code == sf::Keyboard::W && !player.checkDead()) {
				np->updateText();
			}
		}

		if (!enemy.get()->checkDead())
		{
			ai->shouldFollow_followDirection(enemy.get(), &player);
			if (aiClock.getElapsedTime().asMilliseconds() >= 300)
			{
				if (!enemy.get()->checkDead())
				{
					ai->shouldFollow_followDirection(enemy.get(), &player);
				}
				aiClock.restart();
			}
			ai->walkRandomly(np.get());

			break;
		}
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
		if (Clock.getElapsedTime().asMilliseconds() >= 50) {
			player.setTexture(player.currentAnimation.nextFrame());
			enemy->setTexture(enemy->currentAnimation.nextFrame());
			np->setTexture(np->currentAnimation.nextFrame());
			Clock.restart();
		}

		world_physics.step_x_moveables();
		world_physics.step_y_moveables();
		lvls.check_interaction(player);

		np->showText(player);
		hud.update();

		enemy->update_info_pos(window);
		if (player.checkDead()) {
			player.die();
		}
		if (enemy.get()->checkDead()) {
			enemy.get()->die();
		}

	}
	break;

	}
}

void Game::render() {
	switch (state)
	{

	case STATE::MENU:
	{
		window.clear();
		currentMenu->draw(window, lvls, enemy, main_camera, bgMain, player);
		window.display();
		break;
	}


	case STATE::PLAYING:
	{
		window.clear();
		window.draw(lvls.background);
		np->draw(window);
		enemy->draw(window);
		player.draw(window);
		window.draw(lvls.ground);
		window.draw(lvls.damage_background);
		window.draw(lvls.foreground_bounce);
		window.draw(lvls.end);
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