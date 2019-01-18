#include "pch.h"
#include "collision_handler.h"
#include "Collision.h"

namespace Adam
{
	collision_handler::collision_handler(sf::Sprite & collision_layer)
		:collision_layer(&collision_layer)
	{

	}

	collision_handler::collision_handler() {}

	collision_handler::~collision_handler()
	{

	}

	bool collision_handler::collides_with_world(movable *object)
	{
		return Collision::PixelPerfectTest(*collision_layer, *object);
	}

	bool collision_handler::collides_with_sprite(sf::Sprite & object1, sf::Sprite & object2)
	{
		return Collision::PixelPerfectTest(object1, object2);
	}
}
