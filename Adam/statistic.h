#pragma once
#include "pch.h"

class statistic
{
private:

	sf::Font font;
	sf::Text text;

public:
	int max = 100;
	int current = 100;
	statistic(int max, int current);
	statistic();

	// set max value of statistic and sets current to max
	void set_max(int max_points);

	// add value to current statistic and checks if current is not higher then max
	void add(int points);

	// subtract value form current statistic and checks if current is not lower then zero
	void sub(int points);

	// set current value of statistic to 0
	void zero();

	// checks if current is 0
	int is_zero();

	// checks if current is max
	int is_max();

	// updates max value of statistic without updating the current value
	void update_max(int points);
	void print();

};


