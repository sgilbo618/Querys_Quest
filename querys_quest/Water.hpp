/*********************************************************************
** Program name: Query's Quest
** File: Water.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Water which is
**				a subclass of Space and represents Water tiles in the
**				game board.
*********************************************************************/

#ifndef WATER_HPP
#define WATER_HPP

#include "Space.hpp"


class Water : public Space
{
public:
	Water();
	~Water();
	virtual void displayMessage();
};

#endif // !WATER_HPP