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
	geluidje(geluidje),
	lvl(std::make_shared<AnimationManager>(ani)),
	cln_h(lvl.getLevel()->getLayer("foreground")),
	world_physics(&player, cln_h)
{
	char_alpha = sf::Texture();
	char_alpha_invert = sf::Texture();
	menuTex = sf::Texture();

	Collision::CreateTextureAndBitmask(menuTex, "assets/backgrounds/forest.png");
	bgMain = Sprite(menuTex);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	tex.loadFromFile("assets/slimeTest.png");
	lvl.getLevel()->setCharacterSpawn(player);
	enemies = lvl.getLevel()->getEnemies();
	npcs = lvl.getLevel()->getNPCs();
	main_camera.setCenter(player.getPosition());
	main_camera.setSize(640, 360);

	np = std::make_shared<npc>(v2(890, 690), v2(0.2, 0.2), ani.animations["boy"], v2(0, 0), statistic(200, 200));
	enemy = std::make_shared<Enemy>(v2(2050, 700), v2(0.2, 0.2), ani.animations["skull"], v2(0, 0), statistic(200, 200));

	bgMain.setTexture(menuTex);
	sf::Vector2f playerposforbg = player.getPosition();
	bgMain.setPosition(sf::Vector2f(playerposforbg.x - 960, playerposforbg.y - 540));

	mouse_texture.loadFromFile("assets/cursor.png");
	cursor.setTexture(mouse_texture);
	cursor.setScale(sf::Vector2f(0.03f,0.03f));

	currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y, player);


	ai = std::make_shared<AI>();
	for (auto & enemy : enemies) {
		world_physics.moveables.push_back(&enemy);
	}
	for (auto & np : npcs) {
		world_physics.moveables.push_back(&np);
	}


	world_physics.moveables.push_back(&*enemy);
	world_physics.moveables.push_back(&*np);
	geluidje.playMusic("audio/music1.wav", 20.0);
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
					int menuResult = currentMenu->chooseTile(currentMenu, player, window, ani);
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
				if (!player.checkDead() && player.jumpCount < 2)
				{
					geluidje.playSoundTwo("jump", 77.0);
					player.setVelocity(sf::Vector2f(player.getVelocity().x, -6));
					player.jumpCount++;
				}
			}


			else if (ev.type == Event::KeyPressed && ev.key.code == sf::Keyboard::K && !player.checkDead())
			{
				player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
				//player.fight(enemy.get());
				for (auto & enemy : enemies) {
					if (player.fight(&enemy))
					{
						geluidje.playSoundTwo("Sword", 75.0);
						geluidje.playSound("maleAttack", 75.0);
						if (player.getPosition().x < enemy.getPosition().x)
						{
							enemy.setVelocity(sf::Vector2f(player.getVelocity().x + 4, -4));
						}
						else
						{
							enemy.setVelocity(sf::Vector2f(player.getVelocity().x - 4, -4));
						}

					}
				}
				std::cout << "health enem�: " << enemy.get()->health.current << "\n";

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
				player.setAnimation("WALKright", Animation::intervals::walk);
				player.setTexture(player.currentAnimation.nextFrame());
			}
			//geluidje.playSound("footStep", 25.0);
			//geluidje.playSoundTwo("footStep", 25.0);

			player.setScale(sf::Vector2f(0.2, 0.2));
			player.setVelocity(sf::Vector2f(3, player.getVelocity().y));

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !player.checkDead())
		{
			if (player.getCurrentAnimation() != std::string("WALKright")) {
				player.setAnimation("WALKright", Animation::intervals::walk);
				player.setTexture(player.currentAnimation.nextFrame());

			}
			//geluidje.playSound("footStep", 25.0);
			player.setScale(sf::Vector2f(-0.2, 0.2));

			player.setVelocity(sf::Vector2f(-3, player.getVelocity().y));

		}

		else if (player.currentAnimation.isDone() || player.getCurrentAnimation() == std::string("WALKright"))
		{
			player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
			if (player.getVelocity().y == 0) {
				if (player.getCurrentAnimation() != std::string("IDLEright") && player.getCurrentAnimation() != std::string("DYINGright")) {
					player.setAnimation("IDLEright", Animation::intervals::idle);
					player.setTexture(player.currentAnimation.nextFrame());
				}
			}
		}

		if (ev.type == sf::Event::KeyReleased) {
			if (ev.key.code == sf::Keyboard::W && !player.checkDead()) {
				np->updateText();
			}
		}

		if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Button::Left) {

			if (ev.key.code == sf::Mouse::Left && !player.checkDead()) {
				auto mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				auto delta = mouse_pos - player.getPosition();
				float angle_r = atan2(delta.y, delta.x);
				auto angle_degrees = angle_r * (180 / 3.14);
				std::cout << angle_r << std::endl;
				auto delta_normalized = delta / sqrt(pow(delta.x, 2) + pow(delta.y, 2));
				sf::Vector2f shoot_vector(delta_normalized * 15.f);

				std::shared_ptr<projectile> prj = player.shootProjectile(shoot_vector); //TODO: expensive operation, drops FPS
				prj->setRotation(angle_degrees);
				prj->setVelocity(shoot_vector);

				prj->setOrigin(sf::Vector2f(prj->getSize().x /2, prj->getSize().y /2));
				projectiles.push_back(prj);
				if (player.role == "mage")
				{
					geluidje.playSoundTwo("Fireball", 75.0);
				}
				else
				{
					geluidje.playSoundTwo("maleAttack", 77.0);
				}
				if (player.getCurrentAnimation() != "SLASHINGright") {
					player.setAnimation("SLASHINGright", Animation::intervals::attack);
					player.setTexture(player.currentAnimation.nextFrame());
				}
				if (mouse_pos.x < player.getPosition().x) player.setScale(sf::Vector2f(-0.2, 0.2));
				else player.setScale(sf::Vector2f(0.2, 0.2));

			}
		}

		if (!enemy.get()->checkDead()) {

			ai->shouldFollow_followDirection(enemy.get(), &player);
		}
			if (aiClock.getElapsedTime().asMilliseconds() >= 300)
			{
				if (!enemy.get()->checkDead())
				{

				}
			}
		for (auto & enemy : enemies) {
			if (!enemy.checkDead()) {

				ai->shouldFollow_followDirection(&enemy, &player);
				if (aiClock.getElapsedTime().asMilliseconds() >= 300)
				{
					if (!enemy.checkDead())
					{
						ai->shouldFollow_followDirection(&enemy, &player);
					}
					aiClock.restart();
				}

			}
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


		for (auto & np : npcs) {
			ai->walkRandomly(&np);
			if (np.updateAnimation())
			{
				np.setTexture(np.currentAnimation.getCurrentFrame());
			}
		}
		if (player.updateAnimation())
		{
			player.setTexture(player.currentAnimation.getCurrentFrame());
		}
		for (auto & enemy : enemies) {
			if (enemy.updateAnimation())
			{
				enemy.setTexture(enemy.currentAnimation.getCurrentFrame());
			}
		}

		world_physics.step_x_moveables();
		world_physics.step_y_moveables();
		if (lvl.check_interaction(player)) {
			cln_h.collision_layer = &lvl.getLevel()->getLayer("foreground");
			world_physics.clh = &cln_h;
			enemies = lvl.getLevel()->getEnemies();
			npcs = lvl.getLevel()->getNPCs();
			world_physics.moveables.clear();
			world_physics.moveables.push_back(&player);
			for (auto & enemy : enemies) {
				world_physics.moveables.push_back(&enemy);
			}
			for (auto & np : npcs) {
				world_physics.moveables.push_back(&np);
			}

		}

		hud.update();


		std::shared_ptr<projectile> tobedeleted;

		for (auto prj : projectiles) {
			if (prj->isDeath()) {
				tobedeleted = prj;
			}
			prj->updateLive(1);
			prj->setTexture(prj->currentAnimation.nextFrame());
			prj->move();
		}
		projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), tobedeleted), projectiles.end());

		for (auto & np : npcs) {
			np.showText(player);
		}
		hud.update();
			
		for (auto & enemy : enemies) {
			enemy.update_info_pos(window);
			if (enemy.checkDead()) {
				enemy.die();
			}
		}
		if (player.checkDead()) {
			player.die();
		}

		if (player.health.current <= 0)
		{
			geluidje.playSound("death", 55.0);

		}
		if (enemy.get()->checkDead()) {
			enemy.get()->die();
		}
		if (player.getPosition().y > 30000) {
			player.respawn();
			geluidje.playSound("revive", 88);
			player.setVelocity(sf::Vector2f(0, 0));
		}

	}
	break;

	}
	rerender = true;
}

void Game::render() {
	switch (state)
	{

	case STATE::MENU:
	{
		window.clear();
		currentMenu->draw(window, lvl, enemy, main_camera, bgMain, player);
		window.display();
		break;
	}


	case STATE::PLAYING:
	{

		if (rerender) {

			window.clear();
			auto level = lvl.getLevel();
			window.draw(level->getLayer("background"));
			for (auto & npc : npcs) {
				npc.draw(window);
			}
			for (auto & enemy : enemies) {
				enemy.draw(window);
			}
			player.draw(window);

			window.draw(level->getLayer("foreground"));

			window.draw(level->getLayer("foreground_dmg"));
			window.draw(level->getLayer("foreground_bounce"));

			for (auto prj : projectiles) {
				prj->draw(window);
			}

			window.draw(level->getLayer("lvl_end"));

			auto mouse_pos = sf::Mouse::getPosition(window);
			auto mouse_pos_relative_to_view = window.mapPixelToCoords(mouse_pos);
			cursor.setPosition(mouse_pos_relative_to_view);
			window.draw(cursor);
			window.setView(main_HUD);
			hud.draw(window);

			auto center = Collision::GetSpriteCenter(player);
			main_camera.setCenter(center);
			window.setView(main_camera);

			rerender = false;
			window.display();

		}

		
		
		break;
	}
	}
	return;
}
