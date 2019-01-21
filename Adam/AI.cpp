#include "pch.h"
#include "AI.hpp"


void AI::shouldFollow_followDirection(Enemy & p1, movable & p2) {
	//Check if p1 and p2 are close to each other
	// if so, fight
	// or make enemy move towarts the player
	//if ((p1.getPosition() - p2.getPosition()).x <= 40 && (p1.getPosition() - p2.getPosition()).x >= 0) {
		//p1.fight();
	//}
	/*else*/ if ((p1.getPosition() - p2.getPosition()).x <= 400 && (p1.getPosition() - p2.getPosition()).x >= 25) {
		p1.updateFollowPosition(-1);
	}
	//else if ((p1.getPosition() - p2.getPosition()).x >= -40 && (p1.getPosition() - p2.getPosition()).x <= 0) {
		//p1.fight();
	//}
	else if ((p1.getPosition() - p2.getPosition()).x >= -400 && (p1.getPosition() - p2.getPosition()).x <= -25) {
		p1.updateFollowPosition(1);
	}
	// if they are not close to eachother
	// make sure the enemy's velocity is zero
	p1.updateFollowPosition(0);
}