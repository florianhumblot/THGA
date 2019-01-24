#pragma once

#include "statistic.h"
#include "Movable.h"
#include "fighter.h"
#include "Animated.hpp"

class fighter
{
public:
	int lvl;
	statistic health;

	sf::Texture AABB_H;

	fighter(statistic health_c = statistic(100, 100), int lvl_c = 1);

	virtual void update_info() {}
	virtual void update_info_pos(sf::RenderWindow & window) {}
	virtual void updateFollowPosition(int x) {}
	
	virtual bool fight(fighter * opponent);
	void take_damage(int amount);
	virtual void die() = 0;

	virtual sf::Sprite getBox() = 0;
	virtual sf::Sprite makeFightBox() =0;

	bool checkDead();
};