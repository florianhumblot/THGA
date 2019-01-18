#pragma once
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"

class Character : public movable , public Animateable
{

	
	sf::Font font;
	sf::Text text[4];
	std::string t[4];
public:
	int lvl = 1;
	statistic mana;
	statistic health;
	statistic exp;

	
	void update_info();
	void update_info_pos(sf::RenderWindow & windwo, sf::Vector2f character_pos);
	void update_exp(int amount);
	Character() {}
	Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, std::map<std::string, Animation> animations,
									statistic mana_c = statistic(100,100), statistic health_c = statistic(100, 100), statistic exp_c = statistic(0, 100));

	~Character();
//	operator sf::Sprite() { return sprite; }
};

