#include "pch.h"
#include "physics.h"

namespace Adam
{
	physics::physics(movable* player, collision_handler & clh_in)
	{
		moveables.push_back(player);
		clh = &clh_in;
	}

	physics::~physics()
	{
	}

	physics::physics() {}

	void physics::step_x_moveables()
	{
		for (auto & moveable : moveables)
		{
			moveable->move(sf::Vector2f(moveable->getVelocity().x, 0));
		}

		for (auto & moveable : moveables)
		{

			clh->handle_collision(clh->collides_with_world(moveable), 
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
			if (clh->handle_collision(clh->collides_with_world(moveable) && moveable->getVelocity().y > 0,
				[&]() {
				while (clh->collides_with_world(moveable))
				{
					moveable->move(sf::Vector2f(0, -1));
				}
				moveable->setVelocity(sf::Vector2f(moveable->getVelocity().x, 0));
			})) continue;

			if (clh->handle_collision(clh->collides_with_world(moveable) && moveable->getVelocity().y < 0,
				[&]() {
				while (clh->collides_with_world(moveable))
				{
					moveable->move(sf::Vector2f(0, 1));
				}
				moveable->setVelocity(sf::Vector2f(moveable->getVelocity().x, 0));
			})) continue;

			moveable->setVelocity(moveable->getVelocity() + gravity);



		}
	}
}