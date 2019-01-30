#pragma once
// ==========================================================================
//
// File      : Character.h
//
// ==========================================================================

// this file contains Doxygen lines
///file Character.h
/// \brief Playable character class.

#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "Animated.hpp"
#include "Audio.h"
#include "fighter.h"
#include "projectile.hpp"
#include "shooter.hpp"


class Character :  public fighter, public Animateable, public movable, public shooter
{
public:
	/// \brief container for the mana points of the character
	statistic mana;
	/// \brief container for the experience points of the character
	statistic exp;
	/// \brief The spawn point of the character
	/// \detail
	/// The spawn point changes per level and is used by the respawn() function when the character dies or switches level to reset it's position to the starting point of that level.
	sf::Vector2f spawn = sf::Vector2f(890,690);
	/// \brief The selected class of the character
	std::string role;
	/// \brief Updates the experience of the player by the specified amount.
	bool update_exp(int amount);
	/// \brief Resets the player's position to the spawn point and resets it's health to it's maximum.
	void respawn();

	/// \brief update the spawnpoint coordinates of the player.
	void set_spawn(sf::Vector2f new_spawn);

	/// \brief fight an opponent.
	/// \details
	/// Sets the correct animation for fighting if it isn't already set
	/// Tries to fight the given opponent and returns true if their was a hit and false in all other cases.
	bool fight(fighter * opponent, Audio & sound) override;

	/// \brief gets the collision box used for collision with the world from the drawable parent instance.
	sf::Sprite getBox() override;
	/// \brief makes and returns a sprite used for fighting
	/// \detail
	/// the hitbox for collision with the environment and for collision with the opponent are different.
	/// This fightbox is used to detect whether or not the player's attack collides with an enemy, which if it does, would be considered a hit.
	sf::Sprite makeFightBox() override;
	/// \brief gets the hitbox that the opponents use to attack a player.
	/// \detail 
	/// This hitbox is used to detect whether or not the enemy's attack collides with us, which if it does, would be considered a hit.
	sf::Sprite getHitbox() override;

	/// \brief shoots a projectile 
	void shootProjectile(sf::Vector2f pos, sf::Vector2f direction, float angle) ;
	/// \brief Make the player die
	/// \detail
	/// Makes the player undergo the DYING animation
	/// Once the animation is done, we "actually" die, and respawn.
	void die();
	/// \brief construct a character. 
	Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, int prjSize, statistic mana_c = statistic(100, 100), statistic health_c = statistic(100, 100), statistic exp_c = statistic(0, 100));
	/// \brief default destructor.
	~Character();
};

