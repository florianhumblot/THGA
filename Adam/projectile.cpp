#include "projectile.hpp"

projectile::projectile(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, float dmg = 0):
	movable(position, scale, textureFile,velocity)
{
	dmg = dmg;
}

void projectile::setDamage(float dmg) {
	dmg = dmg;
}

float projectile::getDamage() {
	return dmg;
}