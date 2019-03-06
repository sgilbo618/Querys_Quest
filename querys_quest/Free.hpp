/*********************************************************************
** Program name: Query's Quest
** File: Free.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Free which
**				is a subclass of Space and represents open tiles on
**				the game board.
*********************************************************************/

#ifndef FREE_HPP
#define FRRE_HPP

#include "Space.hpp"


class Free : public Space
{
public:
	Free();
	~Free();
	virtual void displayMessage();
};

#endif // !FREE_HPP