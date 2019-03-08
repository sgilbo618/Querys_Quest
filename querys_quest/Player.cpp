/*********************************************************************
** Program name: Query's Quest
** File: Player.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Player which
**				represents the main character, Query, in the game
**				Query's Quest. Player has containers to keep track of
**				keys, boots, and queries.
*********************************************************************/

#include "Player.hpp"
#include "Door.hpp"
#include <iostream>


/*********************************************************************
** Function: Player()
** Description: Default constructor for Player object.
*********************************************************************/
Player::Player()
{
	playerPtr = nullptr;
	direction = UP;
	isAlive = true;
	steps = 0;
	numberOfItems = 0;
}


/*********************************************************************
** Function: ~Player()
** Description: Destructor for Player object.
*********************************************************************/
Player::~Player()
{
}


Direction Player::getDirection()
{
	return direction;
}

/*********************************************************************
** Function: checkIsAlive()
** Description: Checks number of steps and what space the player is on
**				and determines if the player is still alive or not.
**				Sets and returns isAlive. Will return true if still 
**				alive or false if not.
*********************************************************************/
bool Player::checkIsAlive()
{
	if (steps >= MAX_STEPS)
	{
		std::cout << "Query ran out of steps and died!" << std::endl;
		isAlive = false;
	}


	return isAlive;
}


/*********************************************************************
** Function: movePlayer()
** Description: Gets and validates user input for player movement and
**				moves the player if the move is valid.
*********************************************************************/
void Player::movePlayer()
{
	std::string move = "";

	// Get move from user
	do
	{
		std::cout << "Enter move: ";
		std::getline(std::cin, move);
		if (move != "i" && move != "k" && move != "j" && move != "l")
		{
			std::cout << "**Invalid Entry - ";
		}

	} while (move != "i" && move != "k" && move != "j" && move != "l");

	// UP
	if (move == "i" && playerPtr->getUp() != nullptr) // && is for boundry checking
	{
		makeMove(playerPtr->getUp());
		direction = UP;
	}
	// Down
	else if (move == "k" && playerPtr->getDown() != nullptr)
	{
		makeMove(playerPtr->getDown());
		direction = DOWN;
	}
	// Left
	else if (move == "j" && playerPtr->getLeft() != nullptr)
	{
		makeMove(playerPtr->getLeft());
		direction = LEFT;
	}
	// Right
	else if (move == "l" && playerPtr->getRight() != nullptr)
	{
		makeMove(playerPtr->getRight());
		direction = RIGHT;
	}
	else
	{
		std::cout << "This is a wall - can't go here!" << std::endl;
	}
}


/*********************************************************************
** Function: makeMove(Space*)
** Description: Takes in the space the player is attempting to move to
**				and moves there if it is a legal move.
*********************************************************************/
void Player::makeMove(Space * moveSpace)
{
	// Check if space is legal move
	if (checkLegalMove(moveSpace))
	{
		// reset symbol to original
		resetSpaceSymbol();

		// Move player to new space
		playerPtr = moveSpace;

		// set new space symbol to Q
		playerPtr->setSpaceSymbol("Q ");

		// increment steps
		steps++;
	}
}


/*********************************************************************
** Function: checkLegalMove(Space*)
** Description: Checks the space Player is attempting to access and 
**				determines if the space is a legal move. Returns true
**				if it is, false if it is not.
*********************************************************************/
bool Player::checkLegalMove(Space* moveSpace)
{
	bool isLegal = true;
	SpaceType moveType = moveSpace->getType();

	if (moveType == WALL)
	{
		moveSpace->displayMessage();
		isLegal = false;
	}

	if (moveType == DOOR)
	{
		if (static_cast<Door*>(moveSpace)->getIsLocked())
		{
			moveSpace->displayMessage();
			isLegal = false;
		}
		else
		{
			moveSpace->displayMessage();
		}
	}

	return isLegal;
}


/*********************************************************************
** Function: resetSpaceSymbol()
** Description: Looks up the space type that the player is on and
**				changes its symbol back to its orignal state.
*********************************************************************/
void Player::resetSpaceSymbol()
{
	SpaceType type = playerPtr->getType();
	ElementType elementType = playerPtr->getElementType();

	switch (type)
	{
	case FREE:
		playerPtr->setSpaceSymbol("  ");
		break;

	case DOOR:
		playerPtr->setSpaceSymbol("  ");
		break;

	case KEY:
		playerPtr->setSpaceSymbol("  ");
		break;

	case BOOTS:
		playerPtr->setSpaceSymbol("  ");
		break;
		
	case ELEMENT:
	{
		switch (elementType)
		{
		case ICE:
			playerPtr->setSpaceSymbol("/ ");
			break;

		case FIRE:
			playerPtr->setSpaceSymbol("* ");
			break;

		case WATER:
			playerPtr->setSpaceSymbol("~ ");
			break;
		}
		break;
	}
	}
}
