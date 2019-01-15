#include "physics.h"
#include <iostream>

namespace Adam
{
	physics::physics(Character & player, collision_handler & clh_in)
	{
		moveables.push_back(&player);
		clh = &clh_in;
	}

	physics::~physics()
	{
	}

	void physics::step_x_moveables()
	{
		for (auto & moveable : moveables)
		{
			moveable->move(sf::Vector2f(moveable->getVelocity().x, 0));
		}

		for (auto & moveable : moveables)
		{

			clh->handle_collision(clh->handle_world_collision(*moveable), 
			[&]() 
			{
				moveable->move(sf::Vector2f(-moveable->getVelocity().x, 0));
				moveable->setVelocity(sf::Vector2f(0, moveable->getVelocity().y));
			});
		}
	}

	void physics::step_y_moveables()
	{
		for (auto & moveable : moveables)
		{
			moveable->move(sf::Vector2f(0, moveable->getVelocity().y));
		}

		for (auto & moveable : moveables)
		{
			if (clh->handle_collision(clh->handle_world_collision(*moveable) && moveable->getVelocity().y > 0,
				[&]() {
				while (clh->handle_world_collision(*moveable))
				{
					moveable->move(sf::Vector2f(0, -0.5));
				}
				moveable->setVelocity(sf::Vector2f(moveable->getVelocity().x, 0));
			})) return;

			if (clh->handle_collision(clh->handle_world_collision(*moveable) && moveable->getVelocity().y < 0,
				[&]() {
				while (clh->handle_world_collision(*moveable))
				{
					moveable->move(sf::Vector2f(0, 0.5));
				}
				moveable->setVelocity(sf::Vector2f(moveable->getVelocity().x, 0));
			})) return;

			moveable->setVelocity(moveable->getVelocity() + gravity);



		}
	}
}