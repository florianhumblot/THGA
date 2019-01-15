#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "statistic.hpp"
class Character
{
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Vector2f scale;
	sf::Vector2f velocity;
	statistic mana = statistic(100,100);
	statistic health = statistic(100, 100);
	statistic exp = statistic(0, 100);
	int lvl = 0;
public:
	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	sf::Vector2f getPosition();
	void setVelocity(sf::Vector2f newVelocity);
	sf::Vector2f getVelocity();
	void setPosition(sf::Vector2f newPos);
	void move(sf::Vector2f direction);
	void move();
	void setTexture(const std::string & textureFile);
	void setTexture(sf::Texture & texture);
	Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, \
									statistic mana = statistic(100,100), statistic health = statistic(100, 100), statistic exp = statistic(0, 100));
	~Character();
	operator sf::Sprite() { return sprite; }
};

