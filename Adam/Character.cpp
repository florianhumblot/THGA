#include "Character.h"



sf::Vector2f Character::getPosition()
{
	return position;
}

void Character::setVelocity(sf::Vector2f newVelocity)
{
	velocity = newVelocity;
}

sf::Vector2f Character::getVelocity()
{
	return velocity;
}

void Character::setPosition(sf::Vector2f newPos)
{
	position = newPos;
	sprite.setPosition(position);
}

void Character::move(sf::Vector2f direction)
{
	position += direction;
	sprite.setPosition(position);
}

void Character::move()
{
	position += velocity;
	sprite.setPosition(position);
}

void Character::setTexture(const std::string & textureFile)
{
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setTexture(texture);
}

void Character::setTexture(sf::Texture & texture)
{
	sprite.setTexture(texture);
	texture = texture;
}

Character::Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity)
{
	position = position;
	scale = scale;
	velocity = velocity;
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setScale(scale);
}


Character::~Character()
{
}
