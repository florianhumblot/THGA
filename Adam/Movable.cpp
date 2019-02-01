#include "pch.h"
#include "Movable.h"


movable::movable(sf::Vector2f &position, sf::Vector2f & scale, sf::Texture & texture, sf::Vector2f & velocity):
	drawable(position, scale, texture),
	velocity(velocity)
{
}


void movable::setVelocity(sf::Vector2f newVel) {
	velocity = newVel;
}
sf::Vector2f movable::getVelocity() {
	return velocity;
}
void movable::move(sf::Vector2f direction) {
	position += direction;
	sprite.setPosition(position);
}
void movable::move() {
	position += velocity;
	sprite.setPosition(position);
}

void movable::setScale(sf::Vector2f scale)
{
	if (scale.x < 0) {
		sprite.setOrigin(texture.getSize().x, 0);
	}
	else {
		sprite.setOrigin(sf::Vector2f(0, 0));
	}
	sprite.setScale(scale);
}
