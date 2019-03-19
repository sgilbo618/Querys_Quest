/*********************************************************************
** Program name: Query's Quest
** File: Door.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Door which
**				is a subclass of Space and represents Door tiles in
**				the game board.
*********************************************************************/

#include "Door.hpp"
#include <iostream>


/*********************************************************************
** Function: Door()
** Description: Default constructor for Door object.
*********************************************************************/
Door::Door()
{
	type = DOOR;
	symbol = "D ";
	isLocked = true;
}


/*********************************************************************
** Function: Door(string)
** Description: Constructor that takes in a string for the symbol of
**				a door and uses it to create a specific version of a
**				Door.
*********************************************************************/
Door::Door(std::string symbol)
{
	type = DOOR;
	this->symbol = symbol;
	isLocked = true;
}


/*********************************************************************
** Function: ~Door()
** Description: Destructor for Door object.
*********************************************************************/
Door::~Door()
{
}


/*********************************************************************
** Description: Getter and Setter for isLocked.
*********************************************************************/
bool Door::getIsLocked()
{
	return isLocked;
}

void Door::setIsLocked(bool isLocked)
{
	this->isLocked = isLocked;
}


/*********************************************************************
** Function: displayMessage()
** Description: Displays message to user if player attempts to go
**				onto a Door space.
*********************************************************************/
void Door::displayMessage()
{
	std::cout << std::endl;
	std::cout << "** ";

	// When a door is locked, it cannot be passed
	if (isLocked)
	{
		if (symbol == "R ")
		{
			std::cout << "This door is locked - Query needs the red key to go in here." << std::endl;
		}
		else if (symbol == "G ")
		{
			std::cout << "This door is locked - Query needs the green key to go in here." << std::endl;
		}
		else if (symbol == "B ")
		{
			std::cout << "This door is locked - Query needs the blue key to go in here." << std::endl;
		}
		else if (symbol == "! ")
		{
			std::cout << "The final door is locked - Query needs to collect all of the queries to win." << std::endl;
		}
	}
	// The door is unlocked messages
	else
	{
		if (symbol == "R ")
		{
			std::cout << "Query used the red key to unlock the red door!" << std::endl;
		}
		else if (symbol == "G ")
		{
			std::cout << "Query used the green key to unlock the green door!" << std::endl;
		}
		else if (symbol == "B ")
		{
			std::cout << "Query used the blue key to unlock the blue door!" << std::endl;
		}
		else if (symbol == "! ")
		{
			std::cout << "Query completed level 1 of Query's Quest! Congrats!!" << std::endl;
		}
	}
}