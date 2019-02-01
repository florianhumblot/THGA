#include "pch.h"
#include "newGameMenu.hpp"

newGameMenu::newGameMenu(float width, float heigth, Character & player)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}

	menuChoices[0].setString("What class do you want to play?");
	menuChoices[1].setString("The Warrior! A stalward defender of justice and honor. Skilled with the sword!");
	menuChoices[2].setString("The Mage! A fireball shooting spellcaster, burning all enemies in her wake!");
	menuChoices[3].setString("Choose your Class and venture forth into the world!");

	for (int i = 0; i < newGameTiles; i++) {
		menuChoices[i].setFont(font);
		menuChoices[i].setCharacterSize(90);
		if (i == 1 || i == 2) {
			menuChoices[i].setPosition(sf::Vector2f((player.getPosition().x - 800), (player.getPosition().y) + 200 * (i - 2) - 40));
		}
		else {
			menuChoices[i].setPosition(sf::Vector2f((player.getPosition().x - 30), (player.getPosition().y) + 230 * (i - 2) - 40));
		}
	}
	menuChoices[0].setFillColor(sf::Color::Red);
	menuChoices[1].setFillColor(sf::Color::Yellow);
	menuChoices[2].setFillColor(sf::Color::White);
	menuChoices[3].setFillColor(sf::Color::Red);

	selectedItem = 1;
	setNewGame();
}

void newGameMenu::draw(sf::RenderWindow & window, sf::View & main_camera, sf::Sprite & bgMain, Character & player)
{
	main_camera.setSize(1920, 1080);
	sf::Vector2f playerposforbg = player.getPosition();
	bgMain.setPosition(sf::Vector2f(playerposforbg.x - 960, playerposforbg.y - 540));
	window.draw(bgMain);
	for (unsigned int i = 0; i < newGameTiles; i++)
	{
		window.draw(menuChoices[i]);
	}
	window.setView(main_camera);
}

void newGameMenu::moveUp()
{
	menuChoices[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem - 1 >= 1)
	{
		selectedItem--;
	}
	else
	{
		selectedItem = newGameTiles - 3;
	}
	menuChoices[selectedItem].setFillColor(sf::Color::Yellow);
}

void newGameMenu::moveDown()
{
	menuChoices[selectedItem].setFillColor(sf::Color::White);
	if (selectedItem + 1 < newGameTiles-2)
	{

		selectedItem++;

	}
	else
	{
		selectedItem = 1;
	}
	menuChoices[selectedItem].setFillColor(sf::Color::Yellow);
}

int newGameMenu::chooseTile(std::shared_ptr<Menu> & currentMenu, Character & player, sf::Window & window, AnimationManager & ani)
{
	if (selectedItem == 0) {
		
	}
	else if (selectedItem == 1) {
		player.setAnimationMap(ani.animations["knight"]);
		player.setAnimation("IDLEright", Animation::intervals::idle);
		player.setTexture(player.currentAnimation.nextFrame());
		player.setTexture(player.currentAnimation.nextFrame());
		player.role = "knight";
		player.setProjectile([&](sf::Vector2f pos1, sf::Vector2f pos2, std::map<std::string, Animation> animations) 
		{
			sf::Vector2f direction(pos2.x - pos1.x, pos2.y - pos1.y);
			direction.y = (direction.y * 5) / direction.x;
			direction.x = 5;
			std::shared_ptr<projectile> prj = std::make_shared<projectile>(projectile(pos1, sf::Vector2f(0.2, 0.2), animations, direction, 10.0));
			prj->setAnimation("AXEright", Animation::intervals::idle);
			prj->setImpactName("AXEimpact");
			prj->animation_name = "AXEright";
			return prj;
		}
		, ani.animations["projectile"]);

		player.setVeloDeco([&](sf::Vector2f &velo) {velo.x = velo.x *0.5; velo.y = velo.y *0.5;});
		player.setMovDeco([&](sf::Vector2f &mov) {mov.y = mov.y + 0.3;});
		setMain();
		return 2;
	}
	else if (selectedItem == 2) {
		player.setAnimationMap(ani.animations["mage"]);
		player.setAnimation("IDLEright", Animation::intervals::idle);
		player.setTexture(player.currentAnimation.nextFrame());
		player.role = "mage";
		player.lvl = 1;
		player.exp.zero();
		player.setProjectile(
			[&](sf::Vector2f pos1, sf::Vector2f pos2, std::map<std::string, Animation> animations) 
		{
			sf::Vector2f direction(pos2.x - pos1.x, pos2.y - pos1.y);
			direction.y = (direction.y * 5) / direction.x;
			direction.x = 5;
			std::shared_ptr<projectile> prj = std::make_shared<projectile>(projectile(pos1, sf::Vector2f(1.0, 1.0), animations, direction, 10.0));
			prj->setAnimation("FIREBALLright", Animation::intervals::idle);
			prj->setImpactName("FIREBALLimpact");
			prj->animation_name = "FIREBALLright";
			return prj;
		}
		, ani.animations["projectile"]);

		setMain();
		return 2;
	}
	else if (selectedItem == 3) {
	}
	return 0;
}