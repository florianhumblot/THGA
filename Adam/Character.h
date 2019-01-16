#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "statistic.hpp"
#include "Movable.h"

class Character : public movable
{
	statistic mana = statistic(100,100);
	statistic health = statistic(100, 100);
	statistic exp = statistic(0, 100);
	int lvl = 0;

public:
	statistic  mana;
	statistic health;
	statistic exp;

	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	Character() {}
	Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, 
									statistic mana = statistic(100,100), statistic health = statistic(100, 100), statistic exp = statistic(0, 100));

	~Character();
//	operator sf::Sprite() { return sprite; }
};

