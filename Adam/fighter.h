#pragma once

#include "statistic.h"
#include "Movable.h"
#include "fighter.h"

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
	
	virtual void fight(fighter & opponent) {
		opponent.health.sub(1);
	}

	void checkDead() {
		if (health.is_zero())
		{
			setPosition(sf::Vector2f(890, 690));
			health.current = health.max;
		}
	}
};