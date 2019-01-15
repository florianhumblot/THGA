#pragma once
#include "Drawable.h"

class movable : drawable {
protected:
	sf::Vector2f velocity;

public:
	movable(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity);
	void setVelocity(sf::Vector2f newVel);
	sf::Vector2f getVelocity();
	void move(sf::Vector2f direction);
	void move();


};