/*********************************************************************
** Program name: Query's Quest
** File: Menus.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Menus.
*********************************************************************/

#ifndef MENUS_HPP
#define MENUS_HPP


class Menus
{
private:
	int choice;

public:
	Menus();
	~Menus();

	void getAndSetChoice(int low, int high);
	int mainMenu();
	int playAgainMenu();
};

#endif // !MENUS_HPP