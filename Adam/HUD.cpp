#include "pch.h"
#include "HUD.hpp"
HUD::HUD(Character & character) : character(character)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		
	}
	
	update();

	for (unsigned int i = 0; i < 4; i++)
	{
		text[i].setFont(font);
		text[i].setOutlineColor(sf::Color::Black);
		text[i].setOutlineThickness(2.0f);
		text[i].setCharacterSize(40);
		if (!texture_bar[i].loadFromFile(bar_location[i])) 
		{
			std::cout << "error loading font" << std::endl;
		}
		sprite_bar[i].setTexture(texture_bar[i]);
		sprite_bar[i].setPosition(sf::Vector2f(20, 37 + 30 * i));
		bar_status(i);
	}
	
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Blue);
	text[2].setFillColor(sf::Color::Yellow);
	text[3].setFillColor(sf::Color::White);
}

void HUD::update()
{
	bar_length[0] = int((100.0 / (float)character.health.max) * (float)character.health.current);
	bar_length[1]= int((100.0 / (float)character.mana.max) * (float)character.mana.current);
	bar_length[2] = int((100.0 / (float)character.exp.max) * (float)character.exp.current);
	
	text[0].setString(std::to_string(character.health.current) + "/" + std::to_string(character.health.max) + '\n');
	text[1].setString(std::to_string(character.mana.current) + "/" + std::to_string(character.mana.max) + '\n');
	text[2].setString(std::to_string(character.exp.current) + "/" + std::to_string(character.exp.max) + '\n');
	text[3].setString("  lvl: " + std::to_string(character.lvl));
	for (unsigned int k = 0; k < 4; k++)
	{
		bar_status(k);
	}
	
}

void HUD::bar_status(int index)
{
	if (index < 3)
	{
		sprite_bar[index].setScale(sf::Vector2f(1.45f, 1.45f));
		sprite_bar[index].setTextureRect(sf::IntRect(50, 70, bar_length[index], 60));
		text[index].setPosition(60, 15 + 30 * index);
	}
	else if (index == 3)
	{
		sprite_bar[3].setScale(sf::Vector2f(0.9f, 0.9f));
		sprite_bar[3].setTextureRect(sf::IntRect(50, 70, bar_length[3], 26));
		text[3].setPosition(20, 15 + 30 * 3);
	}
}

void HUD::draw(sf::RenderWindow & window) 
{
	for (unsigned int j = 0; j < 4; j++)
	{
		window.draw(sprite_bar[j]);
		window.draw(text[j]);
	}
	
}
