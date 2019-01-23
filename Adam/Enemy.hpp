#ifndef  _ENEMY_HPP
#define _ENEMY_HPP
#include "pch.h"
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "fighter.h"
#include "Animated.hpp"

class Enemy : public fighter, public Animateable
{
private:
	sf::Font font;
	sf::Text text[2];
	int teller = 0;

	enum class STATE { IDLE, FOLLOWING };
	STATE state = STATE::IDLE;

public:

	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	void update_info(int new_lvl) override;
	void update_info_pos(sf::RenderWindow & window) override;
	Enemy() {}
	Enemy(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, statistic health_c = statistic(100, 100));

	bool fight(fighter * opponent) override;

	void take_damage(int amount) ;

	void updateFollowPosition(int x) override;
	void die();
	~Enemy();
};

#endif

