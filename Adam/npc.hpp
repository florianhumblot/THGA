#pragma once
#include "Movable.h"
#include "Animated.hpp"
#include "Character.h"
#include <cstdlib>

class npc : public movable, public Animateable{
	enum class STATE {IDLE, FOLLOWING, WALKING};
	STATE state = STATE::IDLE;
	
	sf::Text text = sf::Text();
	struct linearDialogue {
		std::vector<std::string> dialogue;
		int index = 0;
		std::string line();
		void updateLine();
		void reset();
	} speach;
public:
	sf::Font font;
	int lastDirection;
	sf::Vector2f originPosition;

	/// \brief
	/// constructs a npc 
	/// \details 
	/// constructs a npc and calls the movable and Animateable classes and initializes the npc speech dialogue
	npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, std::vector<std::string> npc_text);
	
	/// \brief
	/// default constructor 
	/// \details
	/// does nothing 
	npc() {}
	~npc();

	/// \brief 
	/// updates the state of npc
	/// \details
	/// updates the state from "IDLE" or "WALKING" randomly
	void updateState();

	/// \brief
	/// sets the text
	/// \details
	/// sets the text displayed above the npc
	void setText(std::string str);

	/// \brief
	/// sets dialogue options
	/// \details
	/// sets the dialoge displayed above npc
	void setDialogue(std::vector<std::string> & dia);

	/// \brief
	/// does not actualy show text
	/// \details
	/// this function does not actualy show the text but hear me out
	/// it decides based on the player position wether to show text above the npc
	void showText(Character &p);

	/// \brief
	/// updates text above npc
	/// \details
	/// calls the linearDialogue class to update the next line
	void updateText();

	/// \brief
	/// returns wether the npc is walking
	/// \details
	/// if not idle is walking
	bool isWalking(); 

	/// \brief
	/// changes direction in oposite direction
	/// \details
	/// inverts direction and texture 
	void walkTheOtherWay();

	/// \brief
	/// returns directions
	/// \details
	/// returns an int to be set in setVelocity on the x-axis
	int getDirection();

	/// \brief
	/// draws the npc
	/// \details
	/// draws the npc and calls drawDialogue()
	void draw(sf::RenderTarget & w);

	/// \brief
	/// draws the dialogue
	/// \details
	/// draws the dialogue of the npc
	void drawDialogue(sf::RenderTarget & w);

};

