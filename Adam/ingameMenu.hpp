#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

#define pauseOptions 4

class inGameMenu
{
private:
	float width;
	float heigth;
	sf::Font font;
	sf::Text pauseScreen[pauseOptions];
	sf::Sprite sprite;
	sf::Texture texture;
public:
	inGameMenu(float width, float heigth)
	{
		if (!font.loadFromFile("fonts/strangers.ttf"))
		{
			std::cout << "error loading font" << std::endl;
		}

		pauseScreen[0].setFont(font);
		pauseScreen[0].setString("Continue Game");
		pauseScreen[0].setFillColor(sf::Color::Red);
		pauseScreen[0]
	}

};


#endif INGAMEMENU_HPP