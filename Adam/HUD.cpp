#include "HUD.hpp"

HUD::HUD(Character & character) : character(character)
{
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		//std::cout << "error loading font" << std::endl;
	}
	
	t[0] = std::to_string(character.health.current) + "/" + std::to_string(character.health.max) + '\n';
	t[1] = std::to_string(character.mana.current) + "/" + std::to_string(character.mana.max) + '\n';
	t[2] = std::to_string(character.exp.current) + "/" + std::to_string(character.exp.max) + '\n';
	t[3] = "  lvl: " + std::to_string(character.lvl);

	for (unsigned int i = 0; i < 4; i++)
	{
		text[i].setFont(font);	
		text[i].setCharacterSize(100);
		text[i].setString(t[i]);
	}
	
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Blue);
	text[2].setFillColor(sf::Color::Yellow);
	text[3].setFillColor(sf::Color::Black);
}

HUD::~HUD()
{

}

void HUD::draw(sf::RenderWindow & window) 
{
	for (unsigned int j = 0; j < 4; j++)
	{
		window.draw(text[j]);
	}
	
}

/*
if (!font.loadFromFile("fonts/stranger.ttf"))
{
	//std::cout << "error loading font" << std::endl;
}
t[0] = std::to_string(health.current) + "/" + std::to_string(health.max) + '\n';
t[1] = std::to_string(mana.current) + "/" + std::to_string(mana.max) + '\n';
t[2] = std::to_string(exp.current) + "/" + std::to_string(exp.max) + '\n';
t[3] = "  lvl: " + std::to_string(lvl);

text[0].setFillColor(sf::Color::Red);
text[1].setFillColor(sf::Color::Blue);
text[2].setFillColor(sf::Color::Yellow);
text[3].setFillColor(sf::Color::Black);
for (unsigned int i = 0; i < 4; i++)
{
	text[i].setFont(font);
	text[i].setCharacterSize(25);
	text[i].setString(t[i]);
	text[i].setPosition(sf::Vector2f(characters_pos.x, characters_pos.y + i * 24));
	window.draw(text[i]);
}*/