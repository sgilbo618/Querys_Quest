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
	if (isLocked)
	{
		std::cout << "This door is locked - can't go in here" << std::endl;
	}
	else
	{
		std::cout << "Query used a key to unlock the door!" << std::endl;
	}
}