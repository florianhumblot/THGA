#include "Character.h"


Character::Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic mana, statistic health, statistic exp): 
	movable(position, scale, textureFile, velocity)
{
//	movable(position, scale, textureFile, velocity);
	mana = mana;
	health = health;
	exp = exp;
	Collision::CreateTextureAndBitmask(texture, textureFile);
//	sprite.setPosition(position);
//	sprite.setTexture(texture);
//	sprite.setScale(scale);
}

Character::~Character()
{
}
