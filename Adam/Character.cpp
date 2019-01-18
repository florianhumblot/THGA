#include "pch.h"
#include "Character.h"
Character::Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic mana_c, statistic health_c, statistic exp_c): 
	movable(position, scale, textureFile, velocity),
	Animateable(std::map<std::string, Animation> { {"IDLEright", Animation()}})
{
	animations["IDLEright"].addFrame(textureFile);
	mana = mana_c;
	health = health_c;
	exp = exp_c;
	Collision::CreateTextureAndBitmask(texture, textureFile);
	std::cout << " texturefile constructor called! \n";
}

Character::Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic mana_c, statistic health_c, statistic exp_c):
	Animateable(animations),
	movable(position, scale, animations["IDLEright"].textures[0], velocity)
{
	animations["IDLEright"].print();
	mana = mana_c;
	health = health_c;
	exp = exp_c;
	//texture = texture;
	std::cout << " animations constructor called! \n";

}


Character::~Character()
{
}

void Character::update_info()
{
	t[0] = std::to_string(health.current) + "/" + std::to_string(health.max) + '\n';
	t[1] = "  lvl: " + std::to_string(lvl);
	for (unsigned int k = 0; k < 2; k++)
	{
		text[k].setString(t[k]);

	}
}

void Character::update_info_pos(sf::RenderWindow & window, sf::Vector2f characters_pos)
{
	for (unsigned int j = 0; j < 2; j++)
	{
		text[j].setPosition(sf::Vector2f(characters_pos.x, characters_pos.y + j * 24));
		window.draw(text[j]);
	}
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