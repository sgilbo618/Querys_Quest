/*********************************************************************
** Program name: Query's Quest
** File: Player.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Player which
**				represents the main character, Query, in the game
**				Query's Quest. Player has containers to keep track of
**				keys, boots, and queries.
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"


class Player
{
private:
	Space* playerPtr;

public:
	// Constructor and Destructor
	Player();
	~Player();

	void movePlayer();
	void resetSpaceSymbol();

	friend class Board;
};

#endif // !PLAYER_HPP