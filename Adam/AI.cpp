#include "pch.h"
#include "AI.hpp"


void AI::shouldFollow_followDirection(Enemy * p1, fighter * p2) {

	//Check if p1 and p2 are close to each other
	// if so, make enemy move towarts the player
	if ((p1->getPosition() - p2->getPosition()).x <= 400 && (p1->getPosition() - p2->getPosition()).x >= 0) {
		std::cout << "left \n";
		if (!p1->fight(p2)) {
			if (p1->getCurrentAnimation() != "WALKright") {
				p1->setAnimation("WALKright");
			}

			p1->setScale(sf::Vector2f(-0.2, 0.2));
			p1->updateFollowPosition(-1);
		}
		
		return;
	}
	else if ((p1->getPosition() - p2->getPosition()).x >= -400 && (p1->getPosition() - p2->getPosition()).x <= 0) {
		if (!p1->fight(p2)) {
			std::cout << "right \n";
			if (p1->getCurrentAnimation() != "WALKright") {
				p1->setAnimation("WALKright");
			}
			p1->setScale(sf::Vector2f(0.2, 0.2));
			p1->updateFollowPosition(1);
		}

		return;
	}
	else {
		// if they are not close to eachother
		// make sure the enemy's velocity is zero
		p1->updateFollowPosition(0);
	}
}