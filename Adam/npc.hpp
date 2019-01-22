#pragma once
#include "Movable.h"
#include "Animated.hpp"
#include "statistic.h"
#include <cstdlib>

class npc : public movable, Animateable{
	statistic health;
	enum class STATE {IDLE, FOLLOWING, WALKINGRIGHT, WALKINGLEFT};
	STATE state = STATE::IDLE;
public:
	sf::Vector2f originPosition;
	npc(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic health_c = statistic(100, 100));
	npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic health_c = statistic(100, 100));
	npc() {}
	~npc();
	void updateState();
	bool isWalking();
	void walkTheOtherWay();
	int getDirection();
};
