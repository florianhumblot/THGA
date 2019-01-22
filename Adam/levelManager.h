#pragma once

class levelManager
{
private:
	
	sf::Sprite fg;
	

	sf::Texture tex;
	sf::Texture tex2;
	sf::Texture tex3;



public:
	sf::Sprite bg;
	sf::Sprite fg_dmg;
	sf::Sprite background;
	sf::Sprite damage_background;
	sf::Sprite ground;

	std::map<std::string, std::map<std::string, std::string> > lvls;
	levelManager();
	void print();
	void make_lvl(std::string lvl_name);
	~levelManager();
};

