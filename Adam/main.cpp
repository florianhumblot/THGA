#include <SFML/Graphics.hpp>
#include "Game.hpp"


#define MS_PER_UPDATE 100






int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	Game game = Game(window);
	
	clock_t previous = clock();
	double lag = 0.0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		clock_t current = clock();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		game.handleInput();

		while (lag >= MS_PER_UPDATE)
		{
			game.update();
			lag -= MS_PER_UPDATE;
		}
		game.render();

	}

	return 0;
}