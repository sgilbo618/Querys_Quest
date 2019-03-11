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
	std::cout << "Query found a key!" << std::endl;
}