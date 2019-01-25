#pragma once
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"
#include "fighter.h"

class Character :  public fighter, public Animateable, public movable
{
public:
	statistic mana;
	statistic exp;
	sf::Vector2f spawn = sf::Vector2f(890,690);

	void update_exp(int amount);
	Character() {}
	void respawn();
	void set_spawn(sf::Vector2f new_spawn);

	bool fight(fighter * opponent) override;

	sf::Sprite getBox() override;
	sf::Sprite makeFightBox() override;

	void die();

	Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic mana_c = statistic(100, 100), statistic health_c = statistic(100, 100), statistic exp_c = statistic(0, 100));
	~Character();
};

