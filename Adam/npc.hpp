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
	
	sf::Text text = sf::Text();
	struct linearDialogue {
		std::vector<std::string> dialogue;
		int index = 0;
		std::string line();
		void updateLine();
		void reset();
	} speach;
public:
	sf::Font font;
	int lastDirection;
	sf::Vector2f originPosition;
	npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, std::vector<std::string> npc_text, statistic health_c = statistic(100, 100));
	npc() {}
	~npc();
	void updateState();
	void setText(std::string str);
	void setDialogue(std::vector<std::string> & dia);
	void showText(Character &p);
	void updateText();
	bool isWalking(); 
	void walkTheOtherWay();
	int getDirection();
	void draw(sf::RenderTarget & w);
	void drawDialogue(sf::RenderTarget & w);

};

