/*********************************************************************
** Program name: Query's Quest
** File: Boots.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Boots which is
**				a subclass of Space and represents Boots tiles in the
**				game board.
*********************************************************************/

#ifndef BOOTS_HPP
#define BOOTS_HPP

#include "Space.hpp"


class Boots : public Space
{
public:
	Boots();
	Boots(std::string symbol, ItemType itemType);
	~Boots();

	virtual void displayMessage();
};

#endif // !BOOTS_HPP