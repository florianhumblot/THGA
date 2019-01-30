#ifndef  _ENEMY_HPP
#define _ENEMY_HPP
#include "pch.h"
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "fighter.h"
#include "Animated.hpp"


// ==========================================================================
//
// File      : Enemy.hpp
//
// ==========================================================================

// this file contains Doxygen lines
///file Enemy.hpp
/// \brief Enemy class 
/// \details
/// This class is for the fighting npc's

class Enemy : public fighter, public Animateable, public movable
{
private:
	sf::Font font;
	std::array<sf::Text, 2> text;
	int teller = 0;

	enum class STATE { IDLE, FOLLOWING, DEAD };
	STATE state = STATE::IDLE;

public:
	/// \brief container for the walking direction
	enum class direction { LEFT, RIGHT };
	/// \brief variable for the current direction
	direction current_direction = direction::RIGHT;
	/// \brief 
	void update_info() override;
	void update_info_pos(sf::RenderWindow & window) override;
	Enemy() {}
	Enemy(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, statistic health_c = statistic(100, 100));

	bool fight(fighter * opponent) override;

	sf::Sprite makeFightBox() override;
	sf::Sprite getBox() override;
	sf::Sprite getHitbox() override;

	virtual void setVelocity(sf::Vector2f newVel) override;

	void updateFollowPosition(int x) override;
	void die();
	void draw(sf::RenderTarget &w);
	~Enemy();
};

#endif

