#pragma once
#include "projectile.hpp"

class shooter
{
protected:
	std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation> a)> shoot = [&](sf::Vector2f pos1, sf::Vector2f pos2, std::map<std::string, Animation> animations) {return std::make_shared<projectile>(projectile());};
	int size = 1;
	std::map<std::string, Animation> projectileAnimations;
public:
	std::vector<std::shared_ptr<projectile>> projectiles;
	shooter();
	shooter(int &size, std::map<std::string, Animation> projectileAnimations);
	void shootProjectile(sf::Vector2f position, sf::Vector2f direction, float angle);
	void setProjectile(std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation>)> newS, std::map<std::string, Animation> & animations);

	~shooter();
};

