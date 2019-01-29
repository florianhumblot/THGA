#pragma once
#include "Movable.h"
#include "Animated.hpp"

class projectile : public movable, public Animateable {
private:
	float dmg;
	bool death = true;
	int live = 50;
public:
	projectile() {}
	projectile(sf::Vector2f &position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f &velocity, float dmg);
	void setDamage(float dmg);
	void setLive(int newLive);
	float getDamage();
	void updateLive( int minus = 1);
	bool isDeath();

};