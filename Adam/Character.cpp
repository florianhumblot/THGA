#include "Character.h"



sf::Vector2f Character::getPosition()
{
	return position;
}

void Character::setVelocity(sf::Vector2f newVelocity)
{
	velocity = newVelocity;
}

sf::Vector2f Character::getVelocity()
{
	return velocity;
}

void Character::setPosition(sf::Vector2f newPos)
{
	position = newPos;
	sprite.setPosition(position);
}

void Character::move(sf::Vector2f direction)
{
	position += direction;
	sprite.setPosition(position);
}

void Character::move()
{
	position += velocity;
	sprite.setPosition(position);
}

void Character::setTexture(const std::string & textureFile)
{
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setTexture(texture);
}

void Character::setTexture(sf::Texture & texture)
{
	sprite.setTexture(texture);
	texture = texture;
}

void Character::update_info()
{
	t[0] = std::to_string(health.current) + "/" + std::to_string(health.max) + '\n';
	t[1] = std::to_string(mana.current) + "/" + std::to_string(mana.max) + '\n';
	t[2] = std::to_string(exp.current) + "/" + std::to_string(exp.max) + '\n';
	t[3] = "  lvl: " + std::to_string(lvl);
	for (unsigned int k = 0; k < 4; k++)
	{
		text[k].setString(t[k]);
	}
}

void Character::update_info_pos(sf::RenderWindow & window, sf::Vector2f characters_pos)
{
	for (unsigned int j = 0; j < 4; j++) 
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

Character::Character(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic mana_c, statistic health_c, statistic exp_c)
{
	position = position;
	scale = scale;
	velocity = velocity;
	mana = mana_c;
	health = health_c;
	exp = exp_c;
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setScale(scale);
	exp.is_zero();

	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		//std::cout << "error loading font" << std::endl;
	}
	update_info();

	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Blue);
	text[2].setFillColor(sf::Color::Yellow);
	text[3].setFillColor(sf::Color::Black);
	for (unsigned int i = 0; i < 4; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(25);
		text[i].setOutlineThickness(0.5f);
		text[i].setOutlineColor(sf::Color::Black);
		
	}

}

Character::~Character()
{
}
