/*********************************************************************
** Program name: Query's Quest
** File: Ice.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Ice which is
**				a subclass of Element and represents Ice tiles in the
**				game board.
*********************************************************************/

#ifndef ICE_HPP
#define ICE_HPP

#include "Space.hpp"


class Ice : public Space
{
private:
	std::string element;

public:
	Ice();
	~Ice();

	std::string getElement();
	virtual void displayMessage();
};

#endif // !ICE_HPP