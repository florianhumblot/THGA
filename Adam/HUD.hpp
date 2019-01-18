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
	sf::Texture texture_bar[4];
	sf::Sprite sprite_bar[4];
	std::string bar_location[4] = { "assets/Health.png","assets/Mana.png","assets/exp.png","assets/lvl.png" };
	Character & character;
	int bar_length[4] = {100,100,100,60};
public:
	HUD(Character & character);
	~HUD();
	void update();
	void bar_status(int index);
	void draw(sf::RenderWindow & window);
};
#endif // !HUD_HPP

