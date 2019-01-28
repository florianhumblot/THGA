#pragma once
#include "Enemy.hpp"
#include "npc.hpp"
#include "Character.h"


class AI {

public:
	AI() {

	}

	void shouldFollow_followDirection(Enemy * p1, Character * p2);
	void walkRandomly(npc * p1);

};
