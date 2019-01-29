#pragma once
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"
#include "fighter.h"
#include "projectile.hpp"
#include "shooter.hpp"

class Character :  public fighter, public Animateable, public movable, public shooter
{
public:
	statistic mana;
	statistic exp;
	sf::Vector2f spawn = sf::Vector2f(890,690);
	std::string role;
	void update_exp(int amount);
	void respawn();
	void set_spawn(sf::Vector2f new_spawn);

	bool fight(fighter * opponent) override;

	sf::Sprite getBox() override;
	sf::Sprite makeFightBox() override;
	sf::Sprite getHitbox() override;

	void shootProjectile(sf::Vector2f position, sf::Vector2f direction, float angle);
	void die();
	Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, int prjSize, statistic mana_c = statistic(100, 100), statistic health_c = statistic(100, 100), statistic exp_c = statistic(0, 100));
	~Character();
};

