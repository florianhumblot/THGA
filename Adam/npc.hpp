#pragma once
#include "Movable.h"
#include "Animated.hpp"
#include "statistic.h"
#include <cstdlib>

class npc : public movable, public Animateable{
	statistic health;
	enum class STATE {IDLE, FOLLOWING, WALKING};
	STATE state = STATE::IDLE;
public:
	int lastDirection;
	sf::Vector2f originPosition;
	npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic health_c = statistic(100, 100));
	npc() {}
	~npc();
	void updateState();
	bool isWalking();
	void walkTheOtherWay();
	int getDirection();
	friend operator sf::RenderTarget::draw(npc &n)() {
		this->draw(n.sf::Sprite());
	}

};

