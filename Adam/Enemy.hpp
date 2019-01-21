#ifndef  _ENEMY_HPP
#define _ENEMY_HPP

#include "Collision.h"
#include "statistic.h"
#include "Movable.h"
#include "fighter.h"

class Enemy : public movable, public fighter
{
private:
	sf::Font font;
	sf::Text text[2];
	std::string t[2];
	int teller = 0;

	enum class STATE { IDLE, FOLLOWING };
	STATE state = STATE::IDLE;

public:
	//int lvl = 1;
	//statistic health;

	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	void update_info(int new_lvl);
	void update_info_pos(sf::RenderWindow & window);
	Enemy() {}
	Enemy(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic health_c = statistic(100, 100));

	void take_damage(int amount);

	void updateFollowPosition(int x);

	~Enemy();
	//	operator sf::Sprite() { return sprite; }
};

#endif

