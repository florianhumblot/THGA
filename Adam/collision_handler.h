#pragma once
#include "Character.h"

namespace Adam
{
	class collision_handler
	{
	public:
		sf::Sprite * collision_layer;

		collision_handler(sf::Sprite & collision_layer);
		collision_handler();
		~collision_handler();

		template<typename LAMBDA>
		bool handle_collision(bool condition, LAMBDA f)
		{
			if (condition) f();
			return condition;
		}

		bool collides_with_world(movable* object);
		bool collides_with_sprite(const sf::Sprite & object1, const sf::Sprite & object2);

	};
}

