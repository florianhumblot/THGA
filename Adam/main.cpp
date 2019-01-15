#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "mainMenu.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
	mainMenu mainmenu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}