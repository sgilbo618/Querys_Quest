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

#define MAX_STEPS 1000
#define QUERIES_NEEDED 1
enum Direction {UP, DOWN, LEFT, RIGHT};

class Player
{
private:
	Space* playerPtr;
	Direction direction;
	bool isAlive;
	int steps;
	Space* items[6];
	int numberOfItems;
	int queries;

public:
	// Constructor and Destructor
	Player();
	~Player();

	Direction getDirection();
	bool checkIsAlive();

	// Move methods
	void movePlayer();
	void makeMove(Space* moveSpace);
	bool checkLegalMove(Space* moveSpace);
	void resetSpaceSymbol();

	// Item methods
	bool hasThisItem(ItemType item);

	friend class Board;
};

#endif // !PLAYER_HPP