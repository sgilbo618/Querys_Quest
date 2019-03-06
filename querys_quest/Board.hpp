/*********************************************************************
** Program name: Query's Quest
** File: Board.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Board which
**				represtents the 2D game board for Query's Quest. It
**				is responsible for building the world made up of 
**				different Spaces.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"

#define ROWS 25
#define COLS 25

class Board
{
private:
	Space*** gameBoard;

public:
	// Constructor and Destructor
	Board();
	~Board();

	// Methods
	void printGameBoard();
};

#endif // !BOARD_HPP