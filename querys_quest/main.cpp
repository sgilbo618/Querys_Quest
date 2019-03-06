/*********************************************************************
** Program name: Query's Quest
** File: main.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description:
*********************************************************************/

#include "Board.hpp"
#include <iostream>


int main()
{
	Board gameBoard;
	gameBoard.printGameBoard();

	int counter = 20;
	while (counter > 0)
	{
		gameBoard.movePlayer();
		gameBoard.printGameBoard();

		counter--;
	}

	return 0;
}
