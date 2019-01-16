#ifndef HUD_HPP
#define HUD_HPP

#include "SFML/Graphics.hpp"
#include "Character.h"

class HUD
{
private:
	sf::Font font;
	sf::Texture bar;
	sf::Text text[4];
	std::string t[4];
	Character & character;
public:
	HUD(Character & character);
	~HUD();
	void draw(sf::RenderWindow & window);
};
#endif // !HUD_HPP

