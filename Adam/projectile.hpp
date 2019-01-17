#pragma once
#include "Movable.h"

class projectile : public movable {
private:
	float dmg;
	bool death = false;
	int live = 50;
public:
	projectile() {}
	projectile(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, float dmg);
	void setDamage(float dmg);
	void setLive(int newLive);
	float getDamage();
	void updateLive( int minus = 1);
	bool isDeath();

};