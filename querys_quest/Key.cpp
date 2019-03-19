/*********************************************************************
** Program name: Query's Quest
** File: Key.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Key which
**				is a subclass of Space and represents Key tiles in
**				the game board.
*********************************************************************/

#include "Key.hpp"
#include <iostream>


/*********************************************************************
** Function: Key()
** Description: Default constructor for Key object.
*********************************************************************/
Key::Key()
{
	type = KEY;
	symbol = "k ";
	name = "k";
}


/*********************************************************************
** Function: Key(string, ItemType, string)
** Description: Constructor that takes in a string for the symbol of 
**				the key, a string for the name of the key, and an 
**				ItemType for the specific version of the key. Uses
**				the input to create a specific version of a Key.
*********************************************************************/
Key::Key(std::string symbol, ItemType itemType, std::string name)
{
	type = KEY;
	this->symbol = symbol;
	this->itemType = itemType;
	this->name = name;
}


/*********************************************************************
** Function: ~Key()
** Description: Destructor for Key object.
*********************************************************************/
Key::~Key()
{
}


/*********************************************************************
** Description: Getter for name.
*********************************************************************/
std::string Key::getName()
{
	return name;
}



/*********************************************************************
** Function: displayMessage()
** Description: Displays message to user if player attempts to go
**				onto a Key space.
*********************************************************************/
void Key::displayMessage()
{
	std::cout << std::endl;
	std::cout << "** ";

	// Display message based on the spefic key that was found
	if (itemType == REDKEY)
	{
		std::cout << "Query found the red key!" << std::endl;
	}
	else if (itemType == GREENKEY)
	{
		std::cout << "Query found the green key!" << std::endl;
	}
	else if (itemType == BLUEKEY)
	{
		std::cout << "Query found the blue key!" << std::endl;
	}
}