#include "HUD.hpp"

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
		text[i].setCharacterSize(30);
		text[i].setString(t[i]);
		text[i].setPosition(50, 800 + 24 * i);
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

	for (unsigned int k = 0; k < 4; k++)
	{
		text[k].setString(t[k]);
	}
	
}

void HUD::draw(sf::RenderWindow & window) 
{
	for (unsigned int j = 0; j < 4; j++)
	{
		window.draw(text[j]);
	}
	
}
