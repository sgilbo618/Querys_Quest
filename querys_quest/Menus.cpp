/*********************************************************************
** Program name: Query's Quest
** File: Menus.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Menus which
**				contains the menus for Fantasy Combat Game.
*********************************************************************/

#include "Menus.hpp"
#include "inputValidation.hpp"
#include <iostream>


/*********************************************************************
** Function: Menus()
** Description: Default constructor for Menus.
*********************************************************************/
Menus::Menus()
{
	choice = 0;
}


/*********************************************************************
** Function: ~Menus()
** Description: Default destructor for Menus.
*********************************************************************/
Menus::~Menus()
{
}


/*********************************************************************
** Function: getAndSetChoice(int, int)
** Description: Calls integerValidation to get user choice.
*********************************************************************/
void Menus::getAndSetChoice(int low, int high)
{
	do
	{
		// Validates integer
		choice = integerValidation();

		// Validates range
		if (choice < low  || choice > high)
		{
			std::cout << "\n**Invalid Entry**\n";
			std::cout << "Enter again: ";
		}
	} while (choice < low || choice > high);
}


/*********************************************************************
** Function: mainMenu()
** Description: 
*********************************************************************/
int Menus::mainMenu()
{
	std::cout << std::endl
		<< "*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*\n"
		<< "*?*                    Query's Quest                    *?*\n"
		<< "*?*                       ______                        *?*\n"
		<< "*?*                      /  __  \\                       *?*\n"
		<< "*?*                     /__/  \\  \\                      *?*\n"
		<< "*?*                           /  /                      *?*\n"
		<< "*?*                          /  /                       *?*\n"
		<< "*?*                         |  |                        *?*\n"
		<< "*?*                         |__|                        *?*\n"
		<< "*?*                          __                         *?*\n"
		<< "*?*                         |__|                        *?*\n"
		<< "*?*                                                     *?*\n"
		<< "*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*\n"
		<< std::endl
		<< "** How to play **\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< std::endl << std::endl
		<< "1. Play Game\n"
		<< "2. Exit Game\n"
		<< "Enter Selection: ";

	getAndSetChoice(1, 2);

	return choice;
}


/*********************************************************************
** Function: playAgainMenu()
** Description: Displays play again, gets and returns user's choice.
*********************************************************************/
int Menus::playAgainMenu()
{
	// Play again menu output
	std::cout << std::endl << std::endl
		<< "Game Over. Would you like to play again?\n"
		<< "1. Play Again\n"
		<< "2. Exit\n"
		<< "Enter Selection: ";

	getAndSetChoice(1, 2);
	
	return choice;
}