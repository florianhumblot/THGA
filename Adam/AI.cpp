#include "pch.h"
#include "AI.hpp"


void AI::shouldFollow_followDirection(fighter * p1, fighter & p2) {

	//Check if p1 and p2 are close to each other
	// if so, make enemy move towarts the player
	if ((p1->getPosition() - p2.getPosition()).x <= 50 && (p1->getPosition() - p2.getPosition()).x >= 0) {
		p1->updateFollowPosition(0);
		p2.health.sub(1);
		p1->fight();
	}
	else if ((p1->getPosition() - p2.getPosition()).x <= 400 && (p1->getPosition() - p2.getPosition()).x >= 50) {
		std::cout << "left \n";
		p1->updateFollowPosition(-1);
		return;
	}
	else if ((p1->getPosition() - p2.getPosition()).x >= -50 && (p1->getPosition() - p2.getPosition()).x <= -0) {
		p1->updateFollowPosition(0);
		p2.health.sub(1);
		p1->fight();
	}
	else if ((p1->getPosition() - p2.getPosition()).x >= -400 && (p1->getPosition() - p2.getPosition()).x <= -50) {
		std::cout << "right \n";
		p1->updateFollowPosition(1);
		return;
	}
	else {
		// if they are not close to eachother
		// make sure the enemy's velocity is zero
		p1->updateFollowPosition(0);
	}

}

void walkRandomly(npc & p1) {
	p1.updateState();
	if (p1.isWalking()) {
		if ((p1.originPosition.x - p1.getPosition().x > 100) || p1.originPosition.x - p1.getPosition().x < -100) {
			p1.walkTheOtherWay();
		}
	}
	int dir = p1.getDirection();
	p1.move(sf::Vector2f(dir, 0));
}