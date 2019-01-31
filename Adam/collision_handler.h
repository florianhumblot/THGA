/// @file

#pragma once
#include "Character.h"


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
		/// \brief
		/// Points to the sprite used for world collision.
		sf::Sprite * collision_layer;

		/// \brief
		/// Constructor for the collision_handler class, takes a reference to the sprite to be used for world collision.
		collision_handler(sf::Sprite & collision_layer);

		/// \brief
		/// default empty constructor
		collision_handler();

		/// \brief
		/// default empty destructor
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

		/// \brief
		/// Abstracts the pixelperfecttest function to assist in checking collision.
		bool collides_with_world(movable* object);


		/// \brief
		/// Abstracts the pixelperfecttest function to assist in checking collision.
		bool collides_with_sprite(const sf::Sprite & object1, const sf::Sprite & object2);

	};
}

