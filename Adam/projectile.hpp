#pragma once
#include "Movable.h"
#include "Animated.hpp"
#include "fighter.h"
#include "Audio.h"

class projectile : public movable, public Animateable, public fighter {
private:
	float dmg;
	bool death = true;
	int live = 50;
	std::function<void(sf::Vector2f&)> movDeco = [&](sf::Vector2f &mov)->void {};
	std::function<void(sf::Vector2f&)> veloDeco = [&](sf::Vector2f &velo)->void {};
public:
	std::string impact_name = "";
	std::string animation_name = "";
	projectile() {}
	projectile(sf::Vector2f &position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f &velocity, float dmg);
	void setImpactName(const std::string & name);
	void move();
	void setVelocity(sf::Vector2f newVel);
	void setDamage(float dmg);
	void setLive(int newLive);
	void setMovDeco(std::function<void(sf::Vector2f&)> NmovDeco);
	void setVeloDeco(std::function<void(sf::Vector2f&)> NveloDeco);

	float getDamage();
	void updateLive( int minus = 1);
	bool isDeath();
	void revive();
	bool fight(fighter * opponent, Audio & sound) override;
	sf::Sprite getBox() override;
	sf::Sprite makeFightBox() override;
	sf::Sprite getHitbox() override;
	void die() override;
	
};