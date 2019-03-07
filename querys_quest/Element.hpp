/*********************************************************************
** Program name: Query's Quest
** File: Element.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Element which is
**				a subclass of Space. It is an abstract class that 
**				represents Element tiles in the game board.
*********************************************************************/

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "Space.hpp"

enum Elements {ICE, FIRE, WATER};

class Element : public Space
{
protected:
	Elements elementType;

public:
	Element();
	~Element();

	Elements getElementType();
	virtual void displayMessage() = 0;
};

#endif // !ELEMENT_HPP