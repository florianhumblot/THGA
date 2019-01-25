#include "pch.h"
#include "projectile.hpp"

projectile::projectile(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, float dmg = 0):
	movable(position, scale, animations["FIREBALLright"].textures[0], velocity),
	Animateable(animations),
	dmg(dmg)
{
	death = false;
}



void projectile::setDamage(float dmg) {
	dmg = dmg;
}

void projectile::setLive(int newLive) {
	live = newLive;
}

float projectile::getDamage() {
	return dmg;
}

void projectile::updateLive(int minus){
	live -= minus;
	if (live <= 0) {
		death = true;
	}
}

bool projectile::isDeath() {
	return death;
}