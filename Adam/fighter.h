#pragma once

#include "SFML/Graphics.hpp"
#include "statistic.h"

class fighter
{
protected:
public:
	int lvl;
	statistic health;

	fighter(statistic health_c = statistic(100, 100),  int lvl_c = 1);



};