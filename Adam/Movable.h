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
	/// class constructor that sets the velocity and calls 
	movable(sf::Vector2f &position, sf::Vector2f &scale, sf::Texture &texture, sf::Vector2f &velocity);

	movable() {}

	/// \brief
	/// sets Velocity
	/// \details 
	/// sets Velocity to a new value
	virtual void setVelocity(sf::Vector2f newVel);

	/// \brief
	/// return velocity
	/// \details
	/// returns the velocity of the movable
	sf::Vector2f getVelocity();

	/// \brief
	/// moves the movable
	/// \details
	/// moves the movable with an direction
	/// don't use it will probably break the game
	void move(sf::Vector2f direction);

	/// \brief 
	/// moves the movable
	/// \details
	/// moves the movable based on the velocity set
	/// will not break the game
	void move();

	/// \brief
	/// sets the scale
	/// \details
	/// sets the scale and is most of the time used to flip textures
	/// it does not change the direction, why tho?
	void setScale(sf::Vector2f scale);
	

};