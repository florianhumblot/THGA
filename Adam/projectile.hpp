#pragma once
#include "Movable.h"

class projectile : public movable {
private:
	float dmg;
public:
	projectile() {}
	projectile(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, float dmg);
	void setDamage(float dmg);
	float getDamage();

};