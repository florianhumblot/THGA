#pragma once
#include "Enemy.hpp"
#include "npc.hpp"
#include "Character.h"

// ==========================================================================
//
// File      : AI.hpp
//
// ==========================================================================

// this file contains Doxygen lines
///file AI.hpp
/// \brief AI class. Determence what a non playing character should do.
/// \details
/// This class serves as an decicionmaker for npc's. 
/// It can determen if an npc should follow, fight or walkrandomly

class AI {

public:
	/// \brief Empty constructor for AI
	AI() {}
	/// \brief Updates an enemy to it's next move
	/// \detail
	/// This function will check what the enemy should do, follow, fight or nothing
	void shouldFollow_followDirection(Enemy * p1, Character * p2);

	/// \brief Updates the ncp to it's next move
	/// \detail
	/// This function will check where the npc should walk to or eventually where it should jump to
	void walkRandomly(npc * p1);

};
