/*********************************************************************
** Program name: Query's Quest
** File: main.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description:
*********************************************************************/

#include "Board.hpp"
#include "Menus.hpp"
#include <iostream>

int main()
{
	Menus menu;
	int selection = menu.mainMenu();

	if (selection == 1)
	{
		do
		{
			Board gameBoard;
			gameBoard.runGame();

		} while (menu.playAgainMenu() == 1);
	}

	std::cout << std::endl << "GoodBye" << std::endl;
	
	return 0;
}
