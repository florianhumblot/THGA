#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic health_c) :
	movable(position, scale, textureFile, velocity)
{
	health = health_c;
	Collision::CreateTextureAndBitmask(texture, textureFile);
	std::cout << position.x << " <charPosX";
}


Enemy::~Enemy()
{
}

void Enemy::update_info()
{
	t[0] = std::to_string(health.current) + "/" + std::to_string(health.max) + '\n';
	t[1] = "  lvl: " + std::to_string(lvl);
	for (unsigned int k = 0; k < 2; k++)
	{
		text[k].setString(t[k]);

	}
}

void Enemy::update_info_pos(sf::RenderWindow & window, sf::Vector2f characters_pos)
{
	for (unsigned int j = 0; j < 2; j++)
	{
		text[j].setPosition(sf::Vector2f(characters_pos.x, characters_pos.y + j * 24));
		window.draw(text[j]);
	}
}