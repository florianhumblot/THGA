#include "pch.h"
#include "shooter.hpp"

shooter::shooter()
{
}

shooter::shooter(int & size, std::map<std::string, Animation> projectileAnimations):
	size(size),
	projectileAnimations(projectileAnimations)
{
	for (int i = 0; i < size; i++) {
		projectiles.push_back(shoot(sf::Vector2f(1, 1), sf::Vector2f(1, 1), projectileAnimations));
	}
}

void shooter::shootProjectile(sf::Vector2f position, sf::Vector2f direction, float angle){
	for (auto &prj : projectiles) {
		if (prj->isDeath()) {
			std::cout << "hier ";
			prj->revive();
			prj->setPosition(position);
			prj->setRotation(angle);
			prj->setVelocity(direction);
			return;
		}
	}
}

void shooter::setProjectile(std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation>)> newS, std::map<std::string, Animation>& animations){
	shoot = newS;
	projectileAnimations = animations;
	for (auto & prj: projectiles) {
		prj = shoot(sf::Vector2f(1,1), sf::Vector2f(1,1), projectileAnimations);
	}
}


shooter::~shooter()
{
}
