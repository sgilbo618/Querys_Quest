/*********************************************************************
** Program name: Query's Quest
** File: Boots.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Boots which
**				is a subclass of Space and represents Boots tiles in
**				the game board. 
*********************************************************************/

#include "Boots.hpp"
#include <iostream>


/*********************************************************************
** Function: Boots()
** Description: Default constructor for Boots object.
*********************************************************************/
Boots::Boots()
{
	type = BOOTS;
	symbol = "D ";
	name = "";
}


/*********************************************************************
** Function: Boots(string, ItemType, string)
** Description: Constructor that takes in a string for the boot
**				symbol, a string for the boot name, and an ItemType
**				to define what kind of boot this will be. Uses the 
**				input to create a specific version of a Boot.
*********************************************************************/
Boots::Boots(std::string symbol, ItemType itemType, std::string name)
{
	type = BOOTS;
	this->symbol = symbol;
	this->itemType = itemType;
	this->name = name;
}


/*********************************************************************
** Function: ~Boots()
** Description: Destructor for Boots object.
*********************************************************************/
Boots::~Boots()
{
}


/*********************************************************************
** Description: Getter for name.
*********************************************************************/
std::string Boots::getName()
{
	return name;
}


/*********************************************************************
** Function: displayMessage()
** Description: Displays message to user if player attempts to go
**				onto a Boots space.
*********************************************************************/
void Boots::displayMessage()
{
	std::cout << std::endl;
	std::cout << "** ";

	// Displays a different message for each type of different Boot
	if (itemType == WATERBOOTS)
	{
		std::cout << "Query found the water boots!" << std::endl;
		std::cout << "Now he can walk on water!" << std::endl;
	}
	else if (itemType == FIREBOOTS)
	{
		std::cout << "Query found the fire boots!" << std::endl;
		std::cout << "Now he can walk on fire!" << std::endl;
	}
	else if (itemType == ICEBOOTS)
	{
		std::cout << "Query found the ice boots!" << std::endl;
		std::cout << "Now he can walk on ice!" << std::endl;
	}
}