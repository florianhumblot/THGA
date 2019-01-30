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

void projectile::setImpactName(const std::string & name)
{
	impact_name = name;
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
		if(getCurrentAnimation() != impact_name) {
			setAnimation(impact_name, Animation::intervals::dying);
		}
		death = true;
	}
}

bool projectile::isDeath() {
	return death;
}

void projectile::revive() {
	setAnimation(animation_name, Animation::intervals::idle);
	live = 50;
	death = false;
}

bool projectile::fight(fighter * opponent, Audio & sound) {
	if (fighter::fight(opponent, sound)) {
		if (getCurrentAnimation() != impact_name) {
			setAnimation(impact_name, Animation::intervals::dying);
		}
		death = true;
		if (opponent->checkDead()) {
			return true;
		}
	}

	return false;
}

sf::Sprite projectile::getBox()
{
	return drawable::operator sf::Sprite();
}


sf::Sprite projectile::makeFightBox()
{
	return drawable::operator sf::Sprite();
}

sf::Sprite projectile::getHitbox() {
	return drawable::operator sf::Sprite();
}

void projectile::die()
{
	if (getCurrentAnimation() != impact_name) {
		setAnimation(impact_name, Animation::intervals::dying);
	}
	death = true;
}

void projectile::move() {
	movDeco(velocity);
	movable::move();
}

void projectile::setVelocity(sf::Vector2f newVel) {
	veloDeco(newVel);
	movable::setVelocity(newVel);
}

void projectile::setMovDeco(std::function<void(sf::Vector2f&)> NmovDeco) {
	movDeco = NmovDeco;
}

void projectile::setVeloDeco(std::function<void(sf::Vector2f&)> NveloDeco) {
	veloDeco = NveloDeco;
}