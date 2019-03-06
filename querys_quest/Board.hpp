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

#define ROWS 25 // i
#define COLS 25 // j

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
	void createIceRoom();
	void fillInEmptySpaces();
	void setSpacePointers();
	//bool isInBounds(const int );
};

#endif // !BOARD_HPP