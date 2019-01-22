#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, statistic health_c):
	fighter(position, scale, animations["IDLEright"].textures[0], velocity, health_c, 1),
	Animateable(animations)
{
	health = health_c;
	texture = animations["IDLEright"].textures[0];

	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	update_info(3);

	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		text[i].setOutlineColor(sf::Color::Black);
		text[i].setOutlineThickness(2.0f);
		text[i].setCharacterSize(10);
	}
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::White);
}


Enemy::~Enemy()
{
}

void Enemy::update_info(int new_lvl)
{
	text[0].setString(std::to_string(health.current) + "/" + std::to_string(health.max) + '\n');
	text[1].setString("  lvl: " + std::to_string(new_lvl));
}

void Enemy::update_info_pos(sf::RenderWindow & window)
{
	text[0].setPosition(sf::Vector2f(position.x, position.y - 30));
	text[1].setPosition(sf::Vector2f(position.x, position.y - 30 + 12));
}

void Enemy::take_damage(int amount)
{
	health.current = health.current - amount;
	if (health.is_zero()) {
	}
}

void Enemy::updateFollowPosition(int x) {
	// make the enemy move (x is 0, 1, or -1)
	setVelocity(sf::Vector2f(4 * x, getVelocity().y));


}

