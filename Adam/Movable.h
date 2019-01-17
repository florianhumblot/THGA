#pragma once
#include "Drawable.h"

class movable : public drawable {
protected:
	sf::Vector2f velocity;
	
public:
	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	movable(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity);
	movable() {}
	void setVelocity(sf::Vector2f newVel);
	sf::Vector2f getVelocity();
	void move(sf::Vector2f direction);
	void move();
	void setScale(sf::Vector2f scale);
	

};