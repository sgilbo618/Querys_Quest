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

#define MAX_STEPS 10

class Player
{
private:
	Space* playerPtr;
	bool isAlive;
	int steps;

public:
	// Constructor and Destructor
	Player();
	~Player();

	bool checkIsAlive();

	// Move methods
	void movePlayer();
	void makeMove(Space* moveSpace);
	bool checkLegalMove(Space* moveSpace);
	void resetSpaceSymbol();

	friend class Board;
};

#endif // !PLAYER_HPP