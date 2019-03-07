/*********************************************************************
** Program name: Query's Quest
** File: Element.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Element which
**				is a subclass of Space. It is an abstract class that 
**				represents Element tiles in the game board.
*********************************************************************/

#include "Element.hpp"
#include <iostream>


/*********************************************************************
** Function: Element()
** Description: Default constructor for Element object.
*********************************************************************/
Element::Element()
{
	type = ELEMENT;
}


/*********************************************************************
** Function: ~Element()
** Description: Destructor for Element object.
*********************************************************************/
Element::~Element()
{
}


/*********************************************************************
** Description: Getter for elementType.
*********************************************************************/
Elements Element::getElementType()
{
	return elementType;
}
