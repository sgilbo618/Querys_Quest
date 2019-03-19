/*********************************************************************
** Program name: Query's Quest
** File: Water.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Water which
**				is a subclass of Space and represents Water tiles in
**				the game board.
*********************************************************************/

#include "Water.hpp"
#include <iostream>



/*********************************************************************
** Function: Water()
** Description: Default constructor for Water object.
*********************************************************************/
Water::Water()
{
	type = ELEMENT;
	elementType = WATER;
	symbol = "~ ";
}


/*********************************************************************
** Function: ~Water()
** Description: Destructor for Water object.
*********************************************************************/
Water::~Water()
{
}


/*********************************************************************
** Function: displayMessage()
** Description: Displays message to user if player attempts to go
**				onto a Water space.
*********************************************************************/
void Water::displayMessage()
{
	std::cout << std::endl;
	std::cout << "** Query is on Water without Water boots! - He dead" << std::endl;
}