#include "pch.h"
#include "projectile.hpp"

projectile::projectile(sf::Vector2f &position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f &velocity, float dmg = 0):
	movable(position, scale, animations["FIREBALLright"].textures[0], velocity),
	Animateable(animations),
	fighter(statistic(50, 50)),
	dmg(dmg)
{
	death = true;
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

void projectile::revive() {
	live = 50;
	death = false;
}

bool projectile::fight(fighter * opponent) {
	if (fighter::fight(opponent)) {
		if (opponent->checkDead()) {
			return true;
		}
	}

	return false;
}

sf::Sprite projectile::getBox()
{
	return sf::Sprite();
}

sf::Sprite projectile::makeFightBox()
{
	return drawable::operator sf::Sprite();
}

void projectile::die()
{
	death = true;
}
