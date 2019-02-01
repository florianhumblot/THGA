#pragma once
/// @file

#include "Movable.h"
#include "Animated.hpp"
#include "fighter.h"
#include "Audio.h"

class projectile : public movable, public Animateable, public fighter {
private:
	float dmg;
	bool death = true;
	int live = 50;
	std::function<void(sf::Vector2f&)> movDeco = [&](sf::Vector2f &mov)->void {};
	std::function<void(sf::Vector2f&)> veloDeco = [&](sf::Vector2f &velo)->void {};
public:
	std::string impact_name = "";
	std::string animation_name = "";

	/// \brief
	/// default constructor
	projectile() {}

	/// \brief
	/// constructs a projectile
	/// \details
	/// takes aniations, scale, velocity, position, and dmg to construct a projectile
	/// calls movable, ANimateable and fighter constructors
	projectile(sf::Vector2f &position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f &velocity, float dmg);

	/// \brief
	/// sets impact name
	/// \details
	/// takes a string and sets the impact name used for the impact animation
	void setImpactName(const std::string & name);

	/// \brief
	/// moves the projectile
	/// \details
	/// first calls the movDeco lambda and then movable::move()
	void move();

	/// \brief
	/// sets the velocity
	/// \details
	/// first calls veloDeco lambda and then movable::setVelocity()
	void setVelocity(sf::Vector2f newVel);

	/// \brief
	/// sets the damgage
	/// \details
	/// takes a float and sets the damage
	void setDamage(float dmg);

	/// \brief
	/// sets life 
	/// \details
	/// sets life wich is called live because writer is a dyslectic piece of shit
	void setLive(int newLive);

	/// \brief
	/// sets movDeco
	/// \details
	/// sets a new lambda for movDeco
	void setMovDeco(std::function<void(sf::Vector2f&)> NmovDeco);

	/// \brief
	/// sets veloDeco
	/// \details
	/// sets a new lambda for veloDeco
	void setVeloDeco(std::function<void(sf::Vector2f&)> NveloDeco);

	/// \brief
	/// returns damage
	float getDamage();

	/// \brief
	/// updates life 
	/// \details
	/// updates live with an value wich is standard 1
	void updateLive( int minus = 1);

	/// \brief
	/// returns wether the projectile has passed his expiration
	/// \details
	/// returns a bool witch is true when the projectile is dead 
	/// dead is called death because again, dyslectic programmer
	bool isDeath();

	/// \brief
	/// revives the projectile
	/// \details
	/// sets death to false and live to 50
	void revive();

	/// \brief
	/// fights an enemy
	/// \details
	/// works a lot like character.fight(), but returns only true when the enemy has died
	/// also sets death to true
	bool fight(fighter * opponent, Audio & sound) override;

	/// \brief
	/// returns box sprite
	sf::Sprite getBox() override;

	/// \brief
	/// returns fight box
	sf::Sprite makeFightBox() override;

	/// \brief
	/// returns hitbox
	sf::Sprite getHitbox() override;

	/// \brief
	/// kills the projectile
	/// \details
	/// sets death to true, is actualy a seter
	void die() override;
	
};