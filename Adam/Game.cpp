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
	menuTex = sf::Texture();
	Collision::CreateTextureAndBitmask(tex, "assets/backgrounds/tiles2.png");
	bg = Sprite(tex);
	Collision::CreateTextureAndBitmask(tex2, "assets/backgrounds/background2.png");
	bg2 = Sprite(tex2);
	Collision::CreateTextureAndBitmask(menuTex, "assets/backgrounds/forest.png");
	bgMain = Sprite(menuTex);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	main_camera.setCenter(player.getPosition());
	main_camera.setSize(1600, 900);

	enemy = std::make_shared<Enemy>(v2(1900, 100), v2(0.15, 0.15), "assets/char_alpha.png", v2(0, 0), statistic(200, 200));

	this->cln_h = Adam::collision_handler(bg);
	this->world_physics = Adam::physics(&player, cln_h);

	background.setTexture(tex2);
	ground.setTexture(tex);
	bgMain.setTexture(menuTex);
	pos = player.getPosition();

	
	currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y);

	ai = std::make_shared<AI>();

	std::cout << pos.x << " <posx ";

	gravity = v2(0, 1);
	Collision::CreateTextureAndBitmask(slimeChar, "assets/slimeTest.png");
	for (int i = 0; i < 5; i++) {
		Character* n = new Character(sf::Vector2f(500 + 100 * i, 1500), sf::Vector2f(5.f, 5.f), "assets/slimeTest.png", sf::Vector2f(0, 0));
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
					switch (ev.key.code)
					{
						case sf::Keyboard::Up:
							currentMenu->moveUp();
							break;

						case sf::Keyboard::Down:
							currentMenu->moveDown();
							break;

						case sf::Keyboard::Enter:
							// change menu
							currentMenu = std::make_shared<newGameMenu>(window.getSize().x, window.getSize().y);
							break;

						case sf::Keyboard::BackSpace:
							// change menu
							currentMenu = std::make_shared<mainMenu>(window.getSize().x, window.getSize().y);
							break;
						case sf::Keyboard::P:
							// change menu
							state = STATE::PLAYING;
							break;
						case sf::Keyboard::O:
								// ingameMenu hack
							currentMenu = std::make_shared<inGameMenu>(window.getSize().x, window.getSize().y);
					
					}
				}

				window.draw(bgMain);
				currentMenu->draw(window);
				window.display();
				break;
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
					player.setVelocity(sf::Vector2f(player.getVelocity().x, -14));
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

			
			ai->shouldFollow_followDirection(*enemy, player);
			
			/*
			if (enemy->current_direction == Enemy::direction::RIGHT) {
				enemy->updatePosition(8);
			}
			else {
				enemy->updatePosition(-8);
			}

			if ((enemy->getPosition() - player.getPosition()).x <= 100) {
				enemy->updateFollowPosition(-1);
			}
			else if ((enemy->getPosition() - player.getPosition()).x >= -100) {
				enemy->updateFollowPosition(1);
			}*/

			


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