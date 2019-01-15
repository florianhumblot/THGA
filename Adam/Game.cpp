#include "Game.hpp"

Game::Game(sf::RenderWindow &w, Character &player) :

	window(w),
	player(player)

{

	window.setVerticalSyncEnabled(true);
	char_alpha = sf::Texture();
	char_alpha_invert = sf::Texture();
	Collision::CreateTextureAndBitmask(tex, "assets/background.png");
	bg = Sprite(tex);
	Collision::CreateTextureAndBitmask(tex2, "assets/gradient.png");
	bg2 = Sprite(tex2);
	Collision::CreateTextureAndBitmask(char_alpha, "assets/char_alpha.png");
	Collision::CreateTextureAndBitmask(char_alpha_invert, "assets/char_alpha_invert.png");

	main_camera.setCenter(player.getPosition());
	main_camera.setSize(1600, 900);

	background.setTexture(tex2);
	ground.setTexture(tex);
	pos = player.getPosition();

	gravity = v2(0, 1);

}


void Game::handleInput() {
	/*for (auto& action : actions) {
		if (sf::Keyboard::isKeyPressed(action.key)) {
			action.actionLambda();
		}
	}*/

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

		if (ev.key.code == sf::Keyboard::Space)
		{
			player.setVelocity(sf::Vector2f(player.getVelocity().x, -14));
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape)) 
	{ 
		window.close(); 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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





}


void Game::update() {

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
	

}

void Game::render() {

	window.clear();
	window.draw(background);
	window.draw(sf::Sprite(player));
	window.draw(ground);

	auto center = Collision::GetSpriteCenter(player);
	main_camera.setCenter(center);
	window.setView(main_camera);
	window.display();
}