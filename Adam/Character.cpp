#include "pch.h"
#include "Character.h"

void Character::respawn()
{
	setPosition(spawn);
	health.current = health.max;
	mana.current = mana.max;
}

void Character::set_spawn(sf::Vector2f new_spawn)
{
	spawn = new_spawn;
}
Character::Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, int prjSize, statistic mana_c, statistic health_c, statistic exp_c):

	Animateable(animations),
	fighter(health_c, 1),
	movable(position, scale, animations["IDLEright"].textures[0], velocity),
	shooter(prjSize, animations)
{
	setAnimation("IDLEright", Animation::intervals::idle);
	setTexture(currentAnimation.nextFrame());
	mana = mana_c;
	exp = exp_c;
}

bool Character::fight(fighter * opponent, Audio & sound) {

	if (fighter::fight(opponent, sound)) {

		if (fighter::checkDead()) {
			setPosition(sf::Vector2f(890, 690));
			health.current = health.max;
		}
		else if (opponent->checkDead()) {
			update_exp(40);
		}
		return true;
	}
	return false;
}

sf::Sprite Character::makeFightBox() {
	auto temp = sf::Sprite();
	temp.setPosition(position);
	temp.setTexture(AABB_H);
	temp.setScale(scale);
	return temp;
}
void Character::shootProjectile(sf::Vector2f pos, sf::Vector2f direction, float angle) {
	if (mana.current >= 20) {
	//	pos.x = pos.x + (sprite.getGlobalBounds().width / 2);
	//	if (current_direction == direction::LEFT) {
		//	std::cout << "je muil! ";
		//	pos.y = pos.y + 500;
	//	}
		shooter::shootProjectile(pos, direction, angle);
		mana.sub(20);
	}
}


void Character::die()
{
	if (getCurrentAnimation() != std::string("DYINGright")) {
		setAnimation("DYINGright", Animation::intervals::dying);
		setTexture(currentAnimation.nextFrame());
	}
	else {
		if (currentAnimationIsDone()) {
			respawn();
			state = Animateable::states::IDLE;
		}
	}
}

sf::Sprite Character::getBox() {
	return drawable::getBox();
}

sf::Sprite Character::getHitbox()
{
	return drawable::getHitbox();
}

Character::~Character()
{
}

bool Character::update_exp(int amount)
{
	exp.add(amount);
	if (exp.is_max()) {
		lvl++;
		health.max = health.max + 10;
		mana.max = mana.max + 10;
		health.current = health.max;
		mana.current = mana.max;
		exp.set_max(exp.max + 20);
		exp.zero();
		return true;
	}
	return false;
}