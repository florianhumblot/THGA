#include "pch.h"
#include "AI.hpp"


void AI::shouldFollow_followDirection(Enemy * p1, fighter * p2) {

	//Check if p1 and p2 are close to each other
	// if so, make enemy move towarts the player
	if ((p1->getPosition() - p2->getPosition()).x <= 200 && (p1->getPosition() - p2->getPosition()).x > 10) {
		std::cout << "left \n";
		if (!p1->fight(p2)) {
			if (p1->getCurrentAnimation() != "WALKright") {
				p1->setAnimation("WALKright");
				p1->setTexture(p1->currentAnimation.nextFrame());
			}

			p1->updateFollowPosition(-1);
		}
		
		p1->setScale(sf::Vector2f(-0.2, 0.2));
		
		return;
	}
	else if ((p1->getPosition() - p2->getPosition()).x >= -200 && (p1->getPosition() - p2->getPosition()).x < 10) {
		if (p1->fight(p2)) {
			std::cout << "right \n";
			if (p1->getCurrentAnimation() != "SLASHINGright") {
				p1->setAnimation("SLASHINGright");
				p1->setTexture(p1->currentAnimation.nextFrame());
			}
		}
		else {
			std::cout << "right \n";
			if (p1->getCurrentAnimation() != "WALKright") {
				p1->setAnimation("WALKright");
				p1->setTexture(p1->currentAnimation.nextFrame());
			}
			p1->updateFollowPosition(1);
		}
		p1->setScale(sf::Vector2f(0.2, 0.2));
		

		return;
	}
	else {
		// if they are not close to eachother
		// make sure the enemy's velocity is zero
		p1->updateFollowPosition(0);
	}

}

void AI::walkRandomly(npc * p1) {
	p1->updateState();
	int dir = p1->getDirection();

	if (p1->isWalking()) {
		if (p1->originPosition.x - p1->getPosition().x > 100) {
			p1->setScale(sf::Vector2f(0.2, 0.2));
			p1->current_direction = movable::direction::RIGHT;
			if (p1->getCurrentAnimation() != "WALKright") {
				p1->setAnimation("WALKright");
				p1->setTexture(p1->currentAnimation.nextFrame());
			}
		} else if (p1->originPosition.x - p1->getPosition().x < -100) {
			p1->setScale(sf::Vector2f(-0.2, 0.2));
			p1->current_direction = movable::direction::LEFT;
			if (p1->getCurrentAnimation() != "WALKright") {
				p1->setAnimation("WALKright");
				p1->setTexture(p1->currentAnimation.nextFrame());
			}
		}
		std::cout << p1->lastDirection;

		if (p1->getVelocity().x == 0 && p1->lastDirection != 0) {
		//	std::cout << p1->lastDirection;
			p1->walkTheOtherWay();
			p1->setVelocity(sf::Vector2f(0, -9));
		}
		p1->setVelocity(sf::Vector2f(dir, p1->getVelocity().y));
		p1->lastDirection = 1;

	}
	else {
		if (p1->getCurrentAnimation() != "IDLEright") {
			p1->setAnimation("IDLEright");
			p1->setTexture(p1->currentAnimation.nextFrame());
		}
		p1->setVelocity(sf::Vector2f(0,p1->getVelocity().y));
		p1->lastDirection = 0;
	}

	
}