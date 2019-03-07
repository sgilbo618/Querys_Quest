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
#include <iostream>


/*********************************************************************
** Function: Player()
** Description: Default constructor for Player object.
*********************************************************************/
Player::Player()
{
	playerPtr = nullptr;
}


/*********************************************************************
** Function: ~Player()
** Description: Destructor for Player object.
*********************************************************************/
Player::~Player()
{
}

void Player::movePlayer()
{
	// Get move from user
	std::cout << "Enter move: ";
	std::string move = "";
	std::getline(std::cin, move);

	// UP
	if (move == "i" && playerPtr->getUp() != nullptr) // && is for boundry checking
	{
		// function to check if space is legal move

		// function to reset symbol - use enums in switch
		resetSpaceSymbol();

		// Move player up
		playerPtr = playerPtr->getUp();

		// set new space symbol to Q
		playerPtr->setSpaceSymbol("Q ");
	}
	// Down
	else if (move == "k" && playerPtr->getDown() != nullptr)
	{
		// function to check if space is legal move

		// function to reset symbol - use enums in switch
		resetSpaceSymbol();

		// Move player down
		playerPtr = playerPtr->getDown();

		// Set new space symbol to Q
		playerPtr->setSpaceSymbol("Q ");
	}
	// Left
	else if (move == "j" && playerPtr->getLeft() != nullptr)
	{
		// function to check if space is legal move

		// function to reset symbol - use enums in switch
		resetSpaceSymbol();

		// Move player left
		playerPtr = playerPtr->getLeft();

		// Set new space symbol to Q
		playerPtr->setSpaceSymbol("Q ");
	}
	// Right
	else if (move == "l" && playerPtr->getRight() != nullptr)
	{
		// function to check if space is legal move

		// function to reset symbol - use enums in switch
		resetSpaceSymbol();

		// Move player right
		playerPtr = playerPtr->getRight();

		// Set new space symbol to Q
		playerPtr->setSpaceSymbol("Q ");
	}
	else
	{
		std::cout << move << std::endl;
		std::cout << "That move is out of bounds" << std::endl;
	}
}

void Player::resetSpaceSymbol()
{
	SpaceType type = playerPtr->getType();

	switch (type)
	{
	case FREE:
		playerPtr->setSpaceSymbol("  ");
		break;
	}
}
