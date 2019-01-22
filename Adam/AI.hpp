#pragma once
#include "Movable.h"
#include "Enemy.hpp"
#include "npc.hpp"

class AI {

public:
	AI() {

	}

	int shouldFollow_followDirection(Enemy & p1, movable & p2);
	int walk_randomly(npc & p1);


};
