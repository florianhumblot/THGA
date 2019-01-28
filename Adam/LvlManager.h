#pragma once
#include "Level.h"
class LvlManager
{
	std::map<std::string, Level> levels;
public:
	LvlManager();
	~LvlManager();
};

