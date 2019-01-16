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
	int lvl = 1;
	sf::Font font;
	sf::Text text[4];
	std::string t[4];
public:
	statistic  mana;
	statistic health;
	statistic exp;

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
	void update_info();
	void update_info_pos(sf::RenderWindow & window, sf::Vector2f characters_pos);
	void update_exp(int amount);
	Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, \
												statistic  mana, statistic health, statistic exp);
	~Character();
	operator sf::Sprite() { return sprite; }
};

