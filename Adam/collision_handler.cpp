#include "collision_handler.h"
#include "Collision.h"
#include <iostream>
#include "SFML/Graphics.hpp"

namespace Adam
{
	collision_handler::collision_handler(sf::Sprite & collision_layer)
		:collision_layer(collision_layer)
	{

	}

	collision_handler::~collision_handler()
	{

	}

	bool collision_handler::handle_world_collision(Character &object)
	{
		return Collision::PixelPerfectTest(collision_layer, object);
	}

	bool collision_handler::handle_sprite_collision(sf::Sprite & object1, sf::Sprite & object2)
	{
		return Collision::PixelPerfectTest(object1, object2);
	}
}
