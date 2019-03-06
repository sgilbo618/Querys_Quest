/*********************************************************************
** Program name: Query's Quest
** File: Board.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Board which
**				represtents the 2D game board for Query's Quest. It
**				is responsible for building the world made up of
**				different Spaces.
*********************************************************************/

#include "Board.hpp"
#include <iostream>


/*********************************************************************
** Function: Board()
** Description: Default constructor for Board object.
*********************************************************************/
Board::Board()
{
	// Build 2D array of Spaces
	gameBoard = new Space**[COLS];

	for (int j = 0; j < ROWS; j++)
	{
		gameBoard[j] = new Space*[ROWS];
	}

	// Set all pointers to nullptr
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gameBoard[i][j] = new Space;
		}
	}
}


/*********************************************************************
** Function: ~Board()
** Description: Destructor for Board object.
*********************************************************************/
Board::~Board()
{
	// Delete Spaces
	for (int j = 0; j < COLS; j++)
	{
		delete[] gameBoard[j];
	}
	delete[] gameBoard;
}


/*********************************************************************
** Function: printGameBoard()
** Description: Loops through gameBoard and prints each Spaces's char.
*********************************************************************/
void Board::printGameBoard()
{
	// Print top boarder
	std::cout << std::endl;
	std::cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # #" << std::endl;

	// Print gameBoard
	for (int i = 0; i < COLS; i++)
	{
		std::cout << "# ";
		for (int j = 0; j < ROWS; j++)
		{
			std::cout << gameBoard[i][j]->getSpaceSymbol();
		}
		std::cout << "#" << std::endl;
	}

	// Print bottom boarder
	std::cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # #" << std::endl;
}
