#pragma once

#include "statistic.h"
#include "Movable.h"
#include "fighter.h"
#include "Animated.hpp"

class fighter : public movable, public Animateable
{
public:
	int lvl;
	statistic health;

	sf::Texture AABB;

	fighter();
	fighter(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture, sf::Vector2f velocity, std::map<std::string, Animation> animations, statistic health_c = statistic(100, 100), int lvl_c = 1);

	virtual void update_info(int new_lvl) {}
	virtual void update_info_pos(sf::RenderWindow & window) {}
	virtual void updateFollowPosition(int x) {}
	
	bool fight(fighter * opponent) {
		
		if (Collision::PixelPerfectTest(makeFightBox(), opponent->getBox())) {
			updateFollowPosition(0);
			if (getCurrentAnimation() != "SLASHINGright") {
				setAnimation("SLASHINGright");
			}
			opponent->health.sub(1);
			return true;
		}
		return false;
		
	}
	

	sf::Sprite makeFightBox() {
		auto temp = sf::Sprite();
		temp.setPosition(position);
		temp.setTexture(AABB);
		temp.setScale(scale);
		return temp;		
	}

	void checkDead() {
		if (health.is_zero())
		{
			setPosition(sf::Vector2f(890, 690));
			health.current = health.max;
		}
	}
};