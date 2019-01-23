#pragma once

class levelManager
{
private:
	
	
	

	sf::Texture tex;
	sf::Texture tex2;
	sf::Texture tex3;
	sf::Texture tex4;



public:
	sf::Sprite fg;
	sf::Vector2f spawnpoint_player;
	sf::Sprite bg;
	sf::Sprite fg_dmg;
	sf::Sprite fg_bounce;
	sf::Sprite background;
	sf::Sprite damage_background;
	sf::Sprite ground;
	sf::Sprite foreground_bounce;
	std::map<std::string, std::map<int, std::string> > spawnpoints_enemys;

	std::map<std::string, std::map<std::string, std::string> > lvls;
	levelManager();
	void print();
	void make_lvl(std::string lvl_name);
	~levelManager();
};

