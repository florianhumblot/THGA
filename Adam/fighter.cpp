#include "pch.h"
#include "fighter.h"


fighter::fighter() {}

fighter::fighter(sf::Vector2f &position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic health_c,  int lvl_c):
	movable(position, scale, textureFile, velocity)
{
	health = health_c;
	lvl = lvl_c;
}


fighter::fighter(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture, sf::Vector2f velocity, statistic health_c, int lvl_c):
	movable(position, scale, texture, velocity)
{
	health = health_c;
	lvl = lvl_c;
}

