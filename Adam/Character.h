#pragma once
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"
#include "fighter.h"

class Character :  public Animateable, public fighter
{
public:
	statistic mana;
	statistic exp;

	void update_exp(int amount);
	Character() {}

	Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic mana_c = statistic(100, 100), statistic health_c = statistic(100, 100), statistic exp_c = statistic(0, 100));
	~Character();
};

