#include "pch.h"
#include "collision_handler.h"
#include "Collision.h"

namespace Adam
{
	collision_handler::collision_handler(sf::Sprite & layer)
	{
		collision_layer = &layer;
	}

	collision_handler::collision_handler() {}

	collision_handler::~collision_handler() {}

	
	bool collision_handler::collides_with_world(movable *object)
	{
		return Collision::PixelPerfectTest(*collision_layer, object->getBox());
	}

	bool collision_handler::collides_with_sprite(const sf::Sprite & object1, const sf::Sprite & object2)
	{
		return Collision::PixelPerfectTest(object1, object2);
	}
}
