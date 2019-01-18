#include "HUD.hpp"
#include "iostream"
HUD::HUD(Character & character) : character(character)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		//std::cout << "error loading font" << std::endl;
	}
	
	update();

	for (unsigned int i = 0; i < 4; i++)
	{
		text[i].setFont(font);
		text[i].setOutlineColor(sf::Color::Black);
		text[i].setOutlineThickness(2.0f);
		text[i].setCharacterSize(28);
		text[i].setString(t[i]);
		if (!texture_bar[i].loadFromFile(bar_location[i])) 
		{
			std::cout << "error loading font" << std::endl;
		}
		sprite_bar[i].setTexture(texture_bar[i]);
		sprite_bar[i].setPosition(sf::Vector2f(10, 820 + 30 * i));
		bar_status(i);
	}
	
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Blue);
	text[2].setFillColor(sf::Color::Yellow);
	text[3].setFillColor(sf::Color::White);
}

HUD::~HUD()
{

}

void HUD::update()
{
	t[0] = std::to_string(character.health.current) + "/" + std::to_string(character.health.max) + '\n';
	t[1] = std::to_string(character.mana.current) + "/" + std::to_string(character.mana.max) + '\n';
	t[2] = std::to_string(character.exp.current) + "/" + std::to_string(character.exp.max) + '\n';
	t[3] = "  lvl: " + std::to_string(character.lvl);

	bar_length[0] = (100.0 / (float)character.health.max) * (float)character.health.current;
	bar_length[1]= (100.0 / (float)character.mana.max) * (float)character.mana.current;
	bar_length[2] = (100.0 / (float)character.exp.max) * (float)character.exp.current;
	
	for (unsigned int k = 0; k < 4; k++)
	{
		text[k].setString(t[k]);
		bar_status(k);
	}
	
}

void HUD::bar_status(int index)
{
	if (index < 3)
	{
		sprite_bar[index].setScale(sf::Vector2f(1.45, 1.45));
		sprite_bar[index].setTextureRect(sf::IntRect(50, 70, bar_length[index], 60));
		text[index].setPosition(50, 813 + 30 * index);
	}
	sprite_bar[3].setScale(sf::Vector2f(0.9, 0.9));
	sprite_bar[3].setTextureRect(sf::IntRect(50, 70, bar_length[3], 26));
	text[3].setPosition(20, 813 + 30 * 3);
}

void HUD::draw(sf::RenderWindow & window) 
{
	for (unsigned int j = 0; j < 4; j++)
	{
		window.draw(sprite_bar[j]);
		window.draw(text[j]);
	}
	
}
