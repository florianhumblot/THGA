#pragma once
#include "Character.h"
#include "Movable.h"
#include "collision_handler.h"

namespace Adam
{
	
	class physics
	{
	public:
		collision_handler * clh;
		std::vector<movable*> moveables;
		sf::Vector2f gravity = sf::Vector2f(0, 1);

		physics();
		physics(movable* player, collision_handler & clh_in);
		~physics();

		void step_x_moveables();
		void step_y_moveables();
	};
}

