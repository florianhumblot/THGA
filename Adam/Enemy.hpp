#ifndef  _ENEMY_HPP
#define _ENEMY_HPP
#include "pch.h"
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Audio.h"
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

	enum class STATE { IDLE, WALKING, FOLLOWING, DEAD };

	STATE state = STATE::IDLE;

public:

	sf::Vector2f originPos;
	int lastDirection;
//	enum class direction { LEFT, RIGHT };
//	direction current_direction = direction::RIGHT;

	/// \brief 
	/// Updates the health and level of the enemy
	/// \detail
	/// Updates the health and level of the enemy
	void update_info() override;

	/// \brief 
	/// Updates the position of the HP and level of the enemy
	/// \detail
	/// Updates the position of the HP and level of the enemy, it depends on the place of the enemy
	void update_info_pos(sf::RenderWindow & window) override;
	/// \brief construct a character. 
	Enemy() {}
	/// \brief construct a character. 
	Enemy(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, statistic health_c = statistic(100, 100));

	bool isWalking();
	void updateState();

	/// \brief fights with an opponent.
	/// \detail
	/// fights with an opponent, updates audio, makes fight animation
	bool fight(fighter * opponent, Audio & sound) override;

	/// \brief returns the Sprite with dimensions of your fightrange
	sf::Sprite makeFightBox() override;
	/// \brief returns the Sprite with dimensions of your normal range
	sf::Sprite getBox() override;
	/// \brief returns the Sprite with dimensions of the box where you can get hit
	sf::Sprite getHitbox() override;

	/// \brief set your new velocity
	/// \details
	/// set your new velocity, unless you are dead
	void setVelocity(sf::Vector2f newVel) override;

	/// \brief Make your enemy move.
	/// \details
	///  make the enemy move, x is the direction (x is 0, 1, or -1)
	void updateFollowPosition(int x) override;

	/// \brief Make the enemy die
	/// \detail
	/// Makes the enemy undergo the DYING animation
	/// Once the animation is done, we "actually" die, and lie still.
	void die();

	/// \brief Draw the enemy on the RenderTarget
	void draw(sf::RenderTarget &w);

	/// \brief Enemy destructor
	~Enemy();
};

#endif

