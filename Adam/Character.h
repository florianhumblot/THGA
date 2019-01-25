#pragma once
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"
#include "fighter.h"
#include "projectile.hpp"

class Character :  public fighter, public Animateable, public movable
{
	std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation> a)> shoot = [&](sf::Vector2f pos1, sf::Vector2f pos2, std::map<std::string, Animation> animations) {return std::make_shared<projectile>( projectile());};
	std::map<std::string, Animation> projectileAnimations;
public:
	statistic mana;
	statistic exp;

	void update_exp(int amount);
	Character() {}
	void respawn();

	bool fight(fighter * opponent) override;

	sf::Sprite getBox() override;
	sf::Sprite makeFightBox() override;

	void setProjectile(std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation>)> newS, std::map<std::string, Animation> & animations);
	std::shared_ptr<projectile> shootProjectile(sf::Vector2f direction);

	void die();

	Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic mana_c = statistic(100, 100), statistic health_c = statistic(100, 100), statistic exp_c = statistic(0, 100));
	~Character();
};

