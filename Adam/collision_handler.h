#pragma once
#include "Character.h"

/// @file

//! I'm the only one that actually uses this namespace :(
namespace Adam
{
	/// \brief
	/// Collision handling class
	/// \details
	/// "Helper" class that's mainly used for executing a function on a collision condition.
	/// Keeps a pointer to the game's collision layer, so it can be changed when changing levels.
	class collision_handler
	{
	public:

		sf::Sprite * collision_layer;

		/// \details
		/// Constructor for the collision_handler class, takes a reference to the sprite to be used for world collision.
		collision_handler(sf::Sprite & collision_layer);

		collision_handler();
		~collision_handler();

		/// \brief
		/// handle collision function
		/// \details 
		/// Executes a lambda function if the condition is met.
		template<typename LAMBDA>
		bool handle_collision(bool condition, LAMBDA f)
		{
			if (condition) f();
			return condition;
		}

		/// \details
		/// Abstracts the pixelperfecttest function to assist in checking collision.
		bool collides_with_world(movable* object);


		/// \details
		/// Abstracts the pixelperfecttest function to assist in checking collision.
		bool collides_with_sprite(const sf::Sprite & object1, const sf::Sprite & object2);

	};
}

