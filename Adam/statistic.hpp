#pragma once

#include "SFML/Graphics.hpp"
//#include "Character.h"

class statistic {
private:

	sf::Font font;
	sf::Text text;

public:
	int max = 100;
	int current = 100;
	statistic(int max, int current);
	statistic();
	void set_max(int max_points);
	void add(int points);
	void sub(int points);
	void zero();
	int is_zero();
	int is_max();
	void update_max(int points);
	void print();

};


