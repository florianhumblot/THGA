#pragma once
#include "Movable.h"
#include "Enemy.hpp"
#include "npc.hpp"
#include "fighter.h"


class AI {

public:
	AI() {

	}


	int walk_randomly(npc & p1);
	void shouldFollow_followDirection(fighter * p1, fighter & p2);

};
