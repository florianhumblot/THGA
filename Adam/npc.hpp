#pragma once
#include "Movable.h"
#include "Animated.hpp"
#include "statistic.h"
#include "Character.h"
#include <cstdlib>

class npc : public movable, public Animateable{
	statistic health;
	enum class STATE {IDLE, FOLLOWING, WALKING};
	STATE state = STATE::IDLE;
	sf::Font font;
	sf::Text text = sf::Text();
public:
	int lastDirection;
	sf::Vector2f originPosition;
	npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic health_c = statistic(100, 100));
	npc() {}
	~npc();
	void updateState();
	void setText(std::string str);
	void updateText(Character &p);
	bool isWalking(); 
	void walkTheOtherWay();
	int getDirection();
	void draw(sf::RenderTarget & w);

};

