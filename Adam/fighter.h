#pragma once

#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"

class fighter : public movable
{
public:
	int lvl;
	statistic health;

	fighter();
	fighter(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture, sf::Vector2f velocity, statistic health_c = statistic(100, 100), int lvl_c = 1);

	virtual void update_info(int new_lvl) {}
	virtual void update_info_pos(sf::RenderWindow & window) {}
	virtual void updateFollowPosition(int x) {}
	virtual void fight() {}
};