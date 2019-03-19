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
** Description: Displays the main menu to the user. Explains how to
**				play the game and gets user's selection to playe or
**				not.
*********************************************************************/
int Menus::mainMenu()
{
	std::cout << std::endl << std::endl
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
		<< "** About Query's Quest **\n"
		<< "Query has always been curious about the meaning of the \n"
		<< "information around him, so naturally, he became a data \n"
		<< "mining explorer! Query's quest is to traverse his world in \n"
		<< "search of queries to help answer his questions about life -\n"
		<< "no matter what obstacles he may encounter.\n"
		<< std::endl
		<< "** How to Play **\n"
		<< "In the game Query's Quest, the player is Query (denoted by\n"
		<< "the symbol 'Q') and Query must explore his world in search\n"
		<< "of queries (denoted by the symbol '?'). Query must find\n"
		<< "all of queries in order to end his quest and move on to\n"
		<< "the next level of understanding. Along the way, Query will\n"
		<< "encounter different elements of his world, including water,\n"
		<< "fire, and ice. Be careful when traversing these elements \n"
		<< "because some of them may harm Query if you have not found \n"
		<< "the proper boots. Also, not all places in Query's world \n"
		<< "will be accesible without finding the proper keys to unlock\n"
		<< "doors. Good luck to you in your journey!\n"
		<< std::endl
		<< "** Other Information **\n"
		<< "I recommend lengthing your console window to make sure you\n"
		<< "will see the output to explain certain situations. Also, \n"
		<< "Arrow keys are the controls for Query's movements, and if\n"
		<< "at any time you are confused about the spaces, press 'i' \n"
		<< "to get a print out of the map key.\n"
		<< "This game is based off an early 90's computer game called \n"
		<< "Chip's Challenge. It was one of the first computer games I\n"
		<< "ever played, and I hope you enjoy my version of it!\n"
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