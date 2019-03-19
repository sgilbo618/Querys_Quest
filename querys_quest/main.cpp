/*********************************************************************
** Program name: Query's Quest
** File: main.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the main function for the program which is 
**				responsible for creating the game and calling the game
**				driver function. Has a main menu and play again menu
**				to get the user's option to play or exit.
*********************************************************************/

#include "Board.hpp"
#include "Menus.hpp"
#include <iostream>

int main()
{
	Menus menu;
	int selection = menu.mainMenu();

	// User wants to play
	if (selection == 1)
	{
		// Continue to create and run a game as long as user selects
		// to play again
		do
		{
			Board gameBoard;
			gameBoard.runGame();

		} while (menu.playAgainMenu() == 1);
	}

	// Done playing
	std::cout << std::endl << "GoodBye" << std::endl;
	
	return 0;
}