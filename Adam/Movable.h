#pragma once
#include "Drawable.h"

class movable : public drawable {
protected:
	sf::Vector2f velocity;
	
public:
	bool collide_others = true;
	bool canJump = true;
	int jumpCount = 0;

	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	movable(sf::Vector2f &position, sf::Vector2f &scale, sf::Texture &texture, sf::Vector2f &velocity);

	movable() {}
	virtual void setVelocity(sf::Vector2f newVel);
	sf::Vector2f getVelocity();
	void move(sf::Vector2f direction);
	void move();
	void setScale(sf::Vector2f scale);
	

};