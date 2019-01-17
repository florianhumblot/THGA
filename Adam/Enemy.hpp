#ifndef  _ENEMY_HPP
#define _ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"

class Enemy : public movable
{

	sf::Font font;
	sf::Text text[4];
	std::string t[4];
	int teller = 0;

	enum class STATE { IDLE, FOLLOWING };
	STATE state = STATE::IDLE;

public:
	int lvl = 1;
	statistic health;

	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	void update_info();
	void update_info_pos(sf::RenderWindow & windwo, sf::Vector2f character_pos);
	Enemy() {}
	Enemy(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic health_c = statistic(100, 100));

	
	void updatePosition(int x) { 
		if (state == STATE::IDLE) {
			if (teller % 6 == 0) {
				setVelocity(sf::Vector2f(x, getVelocity().y));
				teller++;
			}
			else {
				setVelocity(sf::Vector2f(0, getVelocity().y));
			}

			if (teller++ > 80) {
				if (current_direction == Enemy::direction::RIGHT) {
					current_direction = Enemy::direction::LEFT;
				}
				else {
					current_direction = Enemy::direction::RIGHT;
				}
				teller = 0;
			}
		}
		
		
	}

	void updateFollowPosition(int x) {
		setVelocity(sf::Vector2f(8 *x, getVelocity().y));


	}

	~Enemy();
	//	operator sf::Sprite() { return sprite; }
};

#endif

