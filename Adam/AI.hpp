#pragma once
#include "Movable.h"
#include "Enemy.hpp"
#include "npc.hpp"
#include "fighter.h"
#include "Enemy.hpp"


class AI {

public:
	AI() {

	}

	void walkRandomly(npc * p1);
	void shouldFollow_followDirection(Enemy * p1, fighter & p2);

};
