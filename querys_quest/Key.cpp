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
	symbol = "D ";
}

Key::Key(std::string symbol, ItemType itemType)
{
	type = KEY;
	this->symbol = symbol;
	this->itemType = itemType;
}


/*********************************************************************
** Function: ~Key()
** Description: Destructor for Key object.
*********************************************************************/
Key::~Key()
{
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