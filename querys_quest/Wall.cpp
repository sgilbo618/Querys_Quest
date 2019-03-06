/*********************************************************************
** Program name: Query's Quest
** File: Wall.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Wall which
**				is a subclass of Space and represents wall tiles in
**				the game board.
*********************************************************************/

#include "Wall.hpp"


/*********************************************************************
** Function: Wall()
** Description: Default constructor for Wall object.
*********************************************************************/
Wall::Wall()
{
	type = WALL;
	symbol = "# ";
}


/*********************************************************************
** Function: ~Wall()
** Description: Destructor for Wall object.
*********************************************************************/
Wall::~Wall()
{
}
