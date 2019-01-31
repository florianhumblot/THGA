#include "pch.h"
#include "AI.hpp"


bool AI::shouldFollow_followDirection(Enemy * p1, Character * p2, Audio & sound) {

	//Check if p1 and p2 are close to each other
	// if so, make enemy move towarts the player
	auto abs = p1->getPosition() - p2->getPosition();
	int dir = 0;
	bool hit = false;

	//std::cout << abs.x << ", " << abs.y << " \n";
	if ((abs.x >= 280 || abs.x < -280) && (abs.y > 157,5 || abs.y < -157,5)) {
		//std::cout << "hiero ";
		return false;
	}
	else if (abs.x <= 200 && abs.x > 0 && (abs.y < 30 && abs.y > -30) )

	{

		if (p1->currentAnimation.isDone() || p1->getCurrentAnimation() == std::string("WALKright")) {
			if (!p1->fight(p2, sound)) 
			{
				if (p1->getCurrentAnimation() != "WALKright") {
					p1->setAnimation("WALKright", Animation::intervals::walk);
					p1->setTexture(p1->currentAnimation.nextFrame());
				}

//				p1->updateFollowPosition(-1);
				dir = -1;
			}
			else
			{
				hit = true;
			}

			p1->setScale(sf::Vector2f(-0.2, 0.2));
		}
		if (p1->getVelocity().x == 0 && p1->lastDirection != 0 && p1->getVelocity().y == 0) {
			p1->setVelocity(sf::Vector2f(p1->getVelocity().x, -4));
			p1->lastDirection = 0;
		}
		else {
			p1->lastDirection = 1;
		}
		
	//	return;
	}
	else if (abs.x >= -100 && abs.x < 0 && (abs.y < 10 && abs.y > -10) ) {
		if (p1->currentAnimation.isDone() || p1->getCurrentAnimation() == std::string("WALKright")) {
			if (!p1->fight(p2, sound)) 
			{
				if (p1->getCurrentAnimation() != "WALKright") {
					p1->setAnimation("WALKright", Animation::intervals::walk);
					p1->setTexture(p1->currentAnimation.nextFrame());
				}

			//	p1->updateFollowPosition(1);
				dir = 1;
			}
			else
			{
				hit = true;
			}

			p1->setScale(sf::Vector2f(0.2, 0.2));
		}
		if (p1->getVelocity().x == 0 && p1->lastDirection != 0 && p1->getVelocity().y == 0) {
			p1->setVelocity(sf::Vector2f(p1->getVelocity().x, -4));
			p1->lastDirection = 0;
		}
		else {
			p1->lastDirection = 1;
		}
		
		//return;
	}

	else {
		

		// if they are not close to eachother
		// walk in a random way
	//	p1->updateState();
		// make sure the enemy's velocity is zero


	/*	if (enemy_clock.getElapsedTime().asSeconds() >= 2) {
			p1->updateState();
			enemy_clock.restart();
		}*/
		if (p1->isWalking()) {
			if (p1->getCurrentAnimation() != std::string("WALKright")) {
				p1->setAnimation("WALKright", Animation::intervals::walk);
				p1->setTexture(p1->currentAnimation.nextFrame());
			}
			auto diff = p1->getPosition().x - p1->originPos.x;
			//std::cout << diff << "hiero";
			if (p1->current_direction == movable::direction::LEFT) {
				if (p1->getPosition().x - p1->originPos.x < -50) {
					p1->current_direction = movable::direction::RIGHT;
					dir = 1;
					p1->setScale(sf::Vector2f(0.2,0.2));
				}
				else {
					dir = -1;
				}

			}
			else if(p1->current_direction == movable::direction::RIGHT){
				if (p1->getPosition().x - p1->originPos.x > 50) {
					p1->current_direction = movable::direction::LEFT;
					dir = -1;
					p1->setScale(sf::Vector2f(-0.2, 0.2));
				}
				else {
					dir = 1;
				}
			}

			if (p1->getVelocity().x == 0 && p1->lastDirection != 0) {
				p1->setVelocity(sf::Vector2f(p1->getVelocity().x, -4));
				p1->lastDirection = 0;
			}
			else {
				p1->setVelocity(sf::Vector2f(p1->getVelocity().x, 4));
				p1->lastDirection = 1;

			}

		//	p1->lastDirection = 1;
		
		}
		else {
			dir = 0;
			if (p1->getCurrentAnimation() != std::string("IDLEright")) {
				p1->setAnimation("IDLEright", Animation::intervals::idle);
				p1->setTexture(p1->currentAnimation.nextFrame());
			}
			p1->setVelocity(sf::Vector2f(0, p1->getVelocity().y));
			p1->lastDirection = 0;
		}
		
	}
	p1->setVelocity(sf::Vector2f(dir*2, p1->getVelocity().y));

	return hit;
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

		if (p1->getVelocity().x == 0 && p1->lastDirection != 0 && p1->getVelocity().y == 0) {
			p1->walkTheOtherWay();
			p1->setVelocity(sf::Vector2f(0, -4));
			p1->lastDirection = 0;
			p1->setVelocity(sf::Vector2f(dir, p1->getVelocity().y));

		}
		else {
			p1->setVelocity(sf::Vector2f(dir, p1->getVelocity().y));
			p1->lastDirection = 1;
		}

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