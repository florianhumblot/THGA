#include "pch.h"
#include "fighter.h"


fighter::fighter() {
	AABB.loadFromFile("assets/AABB_H.png");
}

fighter::fighter(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture, sf::Vector2f velocity, statistic health_c, int lvl_c):
	movable(position, scale, texture, velocity)
{
	health = health_c;
	lvl = lvl_c;
	AABB.loadFromFile("assets/AABB_H.png");
}

bool fighter::fight(fighter * opponent) {

	if (Collision::PixelPerfectTest(makeFightBox(), opponent->getBox())) {
		updateFollowPosition(0);
		opponent->take_damage(20+lvl*lvl);
		opponent->update_info();
		return true;
	}
	return false;

}


void fighter::take_damage(int amount)
{
	if (!checkDead()) {
		health.current = health.current - amount;
	}
	
}

sf::Sprite fighter::makeFightBox() {
	auto temp = sf::Sprite();
	temp.setPosition(position);
	temp.setTexture(AABB);
	temp.setScale(scale);
	return temp;
}

bool fighter::checkDead() {
	return health.is_zero();
}
