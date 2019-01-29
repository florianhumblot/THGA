#pragma once

#include "statistic.h"
#include "fighter.h"
#include "Collision.h"
#include "Audio.hpp"
///@file

/// \brief
/// fighter
/// \details
/// This is a parent class for all classes that are fighters.
/// It consists all shared attributes of a fighter
class fighter
{
public:
	int lvl;
	statistic health;
	Audio &sound;
	sf::Texture AABB_H;

	/// \brief
	/// contructor
	/// \details
	/// The constructor initialize the health statistic & lvl of a fighter.
	/// Loads the boundingbox of a fighter.
	fighter(statistic health_c = statistic(100, 100), int lvl_c = 1);

	/// \brief
	/// update_info
	/// \details
	/// this is a virtual function.
	/// Can be used to implement a function that updates the info of a fighter.
	virtual void update_info() {}

	/// \brief
	/// update_info_pos
	/// \details
	/// this is a virtual function.
	/// Can be used to implement a function that updates the position of some info.
	virtual void update_info_pos(sf::RenderWindow & window) {}

	/// \brief
	/// update_info
	/// \details
	/// this is a virtual function.
	/// Can be used to implement a function to update a follow position.
	virtual void updateFollowPosition(int x) {}
	
	/// \brief
	/// fight with opponent
	/// \details
	/// If attack overlaps with opponent.
	/// oppenent takes damage & updates info
	/// returns if fighter has hit his oppenent
	virtual bool fight(fighter * opponent);

	/// \brief
	/// take damage
	/// \details
	/// Calls checkDead function.
	/// If False amount is subtrected from fighters health
	/// Else fighters health is zero
	void take_damage(int amount);

	/// \brief
	/// update_info
	/// \details
	/// this is a pure virtual function.
	/// Must be used to implement a die function.
	virtual void die() = 0;

	/// \brief
	/// update_info
	/// \details
	/// this is a pure virtual function.
	/// Must be used to implement a get function.
	virtual sf::Sprite getBox() = 0;

	/// \brief
	/// update_info
	/// \details
	/// this is a pure virtual function.
	/// Must be used to implement a makeFightBox function.
	virtual sf::Sprite makeFightBox() =0;

	virtual sf::Sprite getHitbox() = 0;

	/// \brief
	/// check if fighter is dead
	/// \details 
	/// Returns if the health of a fighter is equal or lower then zero.
	bool checkDead();
};