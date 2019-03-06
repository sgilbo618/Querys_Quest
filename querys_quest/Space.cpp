/*********************************************************************
** Program name: Query's Quest
** File:
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Space which
**				is an abstract base case that represents the basic
**				tile of the game board for Query's Quest. Each Space
**				has a character to signify it's type and four pointers
**				to other Spaces in the directions of up, down, left,
**				and right.
*********************************************************************/

#include "Space.hpp"


/*********************************************************************
** Function: Space()
** Description: Default constructor for Space object.
*********************************************************************/
Space::Space()
{
	type = Free;
	symbol = ' ';

	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
}


/*********************************************************************
** Function: ~Space()
** Description: Destructor for Space object.
*********************************************************************/
Space::~Space()
{
}
