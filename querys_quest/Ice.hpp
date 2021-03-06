/*********************************************************************
** Program name: Query's Quest
** File: Ice.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Ice which is
**				a subclass of Space and represents Ice tiles in the
**				game board.
*********************************************************************/

#ifndef ICE_HPP
#define ICE_HPP

#include "Space.hpp"


class Ice : public Space
{
public:
	Ice();
	~Ice();
	virtual void displayMessage();
};

#endif // !ICE_HPP