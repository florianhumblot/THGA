#include "pch.h"
#include "Character.h"

Character::Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic mana_c, statistic health_c, statistic exp_c):
	//Animateable(animations),
	fighter(position, scale, animations["IDLEright"].textures[0], velocity, animations, health_c, 1)
{
	mana = mana_c;
	exp = exp_c;
}


Character::~Character()
{
}

void Character::update_exp(int amount)
{
	exp.add(amount);
	if (exp.is_max()) {
		lvl++;
		exp.set_max(exp.max + 20);
		exp.zero();
	}
}