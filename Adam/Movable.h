#pragma once
#include "Drawable.h"

///@file

/// \brief
/// movable class
/// \details
/// Provides an inheritable interface for the game entities to be moved in the game.
/// extends to form drawable
class movable : public drawable {
protected:
	sf::Vector2f velocity;
	
public:
	bool collide_others = true;
	bool canJump = true;
	int jumpCount = 0;

	/// \brief
	/// enum class of directions
	/// \details
	/// an enum class to indicate the direction of the movable
	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;

	/// \brief
	/// constructs a movable
	/// \details
	/// 
	movable(sf::Vector2f &position, sf::Vector2f &scale, sf::Texture &texture, sf::Vector2f &velocity);

	movable() {}
	virtual void setVelocity(sf::Vector2f newVel);
	sf::Vector2f getVelocity();
	void move(sf::Vector2f direction);
	void move();
	void setScale(sf::Vector2f scale);
	

};