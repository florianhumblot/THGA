#include "pch.h"
#include "mainMenu.hpp"
#include "Collision.h"
#include "Character.h"
#include "Game.hpp"
#include "HUD.hpp"
#include "statistic.h"
#include "AnimationManager.h"
#include "Audio.h"

using namespace std;
using namespace sf;

//"trick" struct to declare objects without calling constructors
template<typename T>
struct deffered
{
	deffered() {}
	~deffered() { object.~T(); }
	template<typename...TArgs>
	void construct(TArgs&&...args)
	{
		new (&object) T(std::forward<TArgs>(args)...);
	}
public:
	union
	{
		T object;
	};
};

//renders and displays a rotating loading icon
void render_loading_screen(sf::RenderWindow & w, bool & loaded)
{
	sf::Sprite loader;
	sf::Sprite background;
	sf::Texture loader_png;
	sf::Texture background_texture;
	loader_png.loadFromFile("assets/loader.png");
	background_texture.loadFromFile("assets/backgrounds/loadingScreen.png");
	loader_png.setSmooth(true);
	loader.setTexture(loader_png);
	background.setTexture(background_texture);
	loader.setOrigin(sf::Vector2f(loader_png.getSize().x / 2, loader_png.getSize().y / 2));
	loader.setPosition(sf::Vector2f(w.getSize().x - loader.getTextureRect().width * 0.2, w.getSize().y - loader.getTextureRect().height * 0.2));
	loader.setScale(sf::Vector2f(0.2, 0.2));

	while (!loaded)
	{
		sf::Event e;
		while (w.pollEvent(e)) {}
		w.clear();
		w.draw(background);
		w.draw(loader);
		loader.rotate(10);
		w.display();
	}
}

int main()
{
	RenderWindow window(VideoMode(1920, 1080, 32), "Project: ADAM", sf::Style::None);
	window.setKeyRepeatEnabled(false);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(61);

	//declare objects without constructing
	deffered<AnimationManager> ani;
	deffered<Audio> geluidje;
	deffered<Character> player;
	deffered<HUD> hud;
	deffered<Game> game;

	//create and launch a thread that calls constructors
	bool loaded = false;
	std::thread t([&]() 
	{
		ani.construct("assets/animations/animations.txt");
		geluidje.construct("audio/audio.txt");
		player.construct(sf::Vector2f(890, 690), sf::Vector2f(0.2, 0.2), ani.object.animations["mage"], sf::Vector2f(0, 0), 5, statistic(200, 200), statistic(300, 300), statistic(80, 0));
		hud.construct(player.object);
		game.construct(window, player.object, hud.object, ani.object, geluidje.object);

		loaded = true;
	});

	//while loading render a loading icon/screen
	render_loading_screen(window, loaded);

	t.join(); //wait for objects to finish constructing before moving on

	while (window.isOpen())
	{
		if (window.hasFocus()) game.object.handleInput();
		else 
		{
			sf::Event ev;
			while (window.pollEvent(ev)) {}
		}
		game.object.update();
		game.object.render();

	}

	return 0;
}