#include "pch.h"
#include "AI.hpp"


void AI::shouldFollow_followDirection(Enemy * p1, Character * p2) {

	//Check if p1 and p2 are close to each other
	// if so, make enemy move towarts the player
	auto abs = p1->getPosition() - p2->getPosition();

	if (abs.x <= 100 && abs.x > 0 && (abs.y < 2 && abs.y > -2) )
	{
		if (p1->currentAnimation.isDone() || p1->getCurrentAnimation() == std::string("WALKright")) {
			if (!p1->fight(p2)) {
				if (p1->getCurrentAnimation() != "WALKright") {
					p1->setAnimation("WALKright", Animation::intervals::walk);
					p1->setTexture(p1->currentAnimation.nextFrame());
				}

				p1->updateFollowPosition(-1);
			}

			p1->setScale(sf::Vector2f(-0.2, 0.2));
		}
		
		return;
	}
	else if (abs.x >= -100 && abs.x < 0 && (abs.y < 2 && abs.y > -2) ) {
		if (p1->currentAnimation.isDone() || p1->getCurrentAnimation() == std::string("WALKright")) {
			if (!p1->fight(p2)) {
				if (p1->getCurrentAnimation() != "WALKright") {
					p1->setAnimation("WALKright", Animation::intervals::walk);
					p1->setTexture(p1->currentAnimation.nextFrame());
				}

				p1->updateFollowPosition(1);
			}
			p1->setScale(sf::Vector2f(0.2, 0.2));
		}
		
		return;
	}
	else {
		// if they are not close to eachother
		// make sure the enemy's velocity is zero
		if (p1->getCurrentAnimation() != std::string("IDLEright")) {
			p1->setAnimation("IDLEright", Animation::intervals::idle);
			p1->setTexture(p1->currentAnimation.nextFrame());
			p1->updateFollowPosition(0);
		}
		
	}

}

void AI::walkRandomly(npc * p1) {
	p1->updateState();
	int dir = p1->getDirection();

	if (p1->isWalking()) {
		if (p1->getCurrentAnimation() != "WALKright") {
			p1->setAnimation("WALKright", Animation::intervals::walk);
			p1->setTexture(p1->currentAnimation.nextFrame());

		}
		if (p1->originPosition.x - p1->getPosition().x > 30) {
			p1->setScale(sf::Vector2f(0.2, 0.2));
			p1->current_direction = movable::direction::RIGHT;

		} else if (p1->originPosition.x - p1->getPosition().x < -30) {
			p1->setScale(sf::Vector2f(-0.2, 0.2));
			p1->current_direction = movable::direction::LEFT;

		}

		if (p1->getVelocity().x == 0 && p1->lastDirection != 0) {
			p1->walkTheOtherWay();
			p1->setVelocity(sf::Vector2f(0, -9));
		}		p1->setVelocity(sf::Vector2f(dir, p1->getVelocity().y));
		p1->lastDirection = 1;

	}
	else {
		if (p1->getCurrentAnimation() != "IDLEright") {
			p1->setAnimation("IDLEright", Animation::intervals::idle);
			p1->setTexture(p1->currentAnimation.nextFrame());
		}
		p1->setVelocity(sf::Vector2f(0,p1->getVelocity().y));
		p1->lastDirection = 0;
	}

	
}