#pragma once
#include "Movable.h"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class AI {

public:
	AI() {

	}

	int shouldFollow_followDirection(Enemy & p1, movable & p2) {
		if ((p1.getPosition() - p2.getPosition()).x <= 400 && (p1.getPosition() - p2.getPosition()).x >= 80) {
			p1.updateFollowPosition(-1);
			return -1;
		} else if ((p1.getPosition() - p2.getPosition()).x >= -400 && (p1.getPosition() - p2.getPosition()).x <= -80) {
			p1.updateFollowPosition(1);
			return 1;
		} 
		p1.updateFollowPosition(0);
		return 0;
	}
	


};
