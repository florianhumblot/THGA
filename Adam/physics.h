#pragma once
#include "Character.h"
#include "Movable.h"
#include "collision_handler.h"

//! Apparently I'm the only one who actually uses this namespace :)
namespace Adam
{
	/// \brief
	/// Physics class
	/// \details
	/// Object that handles all movables movement and collision for the game.
	/// Uses a collision_handler to bind actions to collision detection.
	/// Collision detection is done using code provided by SFML on their github page,
	/// these functions check for pixel perfect overlap of bitmasked textures.
	/// We seperate X and Y axis movement, so we can fix the overlap according to the axis we collided.
	class physics
	{
	public:
		collision_handler * clh;						//pointer to its' collision_handler
		std::vector<movable*> moveables;				/*!< Vector of pointers to every movable in the game. */
		sf::Vector2f gravity = sf::Vector2f(0, 1);		/*!< Fixed gravity vector. */

		//empty default constructor
		physics();

		/// \brief
		/// Physics class constructor
		/// \details
		/// For now, adds only the player object to moveables. Other movables are later manually pushed back.
		physics(movable* player, collision_handler & clh_in);
		~physics();

		/// \details
		/// Applies every movables' x velocity then checks and handles collision cases.
		/// Overlap fixing is done by moving the sprite back on the collision axis until it's no longer colliding.
		void step_x_moveables();

		/// \details
		/// Applies every movables' y velocity then checks and handles collision cases.
		/// Overlap fixing is done by moving the sprite back on the collision axis until it's no longer colliding.
		void step_y_moveables();
	};
}

