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
#include "Wall.hpp"
#include "Free.hpp"

#include <iostream>


/*********************************************************************
** Function: Board()
** Description: Default constructor for Board object.
*********************************************************************/
Board::Board()
{	
	// Build 2D array of Spaces
	gameBoard = new Space**[ROWS];

	for (int i = 0; i < COLS; i++)
	{
		gameBoard[i] = new Space*[COLS];
	}

	// Set all pointers to nullptr
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gameBoard[i][j] = nullptr;
		}
	}

	// Build gameBoard
	createIceRoom();
	fillInEmptySpaces();
	setSpacePointers();

	// Build player
	player = gameBoard[15][10];
	player->setSpaceSymbol("Q ");
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
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << "# ";
		for (int j = 0; j < COLS; j++)
		{
			std::cout << gameBoard[i][j]->getSpaceSymbol();
		}
		std::cout << "#" << std::endl;
	}

	// Print bottom boarder
	std::cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # #" << std::endl;
}


/*********************************************************************
** Function: createIceRoom()
** Description: Adds the Spaces to the gameBoard that make up the ice
**				room.
*********************************************************************/
void Board::createIceRoom()
{
	for (int i = 0; i <= 11; i++)
	{
		gameBoard[i][12] = new Wall;
	}

	for (int i = 0; i <= 7; i++)
	{
		gameBoard[11][i] = new Wall;
	}

	gameBoard[11][10] = new Wall;
	gameBoard[11][11] = new Wall;
}


/*********************************************************************
** Function: fillInEmptySpaces()
** Description: Loops through gameBoard and creates a free space where
**				ever there is a nullptr.
*********************************************************************/
void Board::fillInEmptySpaces()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (gameBoard[i][j] == nullptr)
			{
				gameBoard[i][j] = new Free;
			}
		}
	}
}


/*********************************************************************
** Function: setSpacePointers()
** Description: Loop through gameBoard and set all of the Space's
**				directional pointers to its surrounding Spaces.
*********************************************************************/
void Board::setSpacePointers()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			// Set ups - not top row
			if (i != 0)
			{
				gameBoard[i][j]->setUp(gameBoard[i - 1][j]);
			}

			// Set downs - not bottom row
			if (i != ROWS - 1)
			{
				gameBoard[i][j]->setDown(gameBoard[i + 1][j]);
			}

			// Set lefts - not first col
			if (j != 0)
			{
				gameBoard[i][j]->setLeft(gameBoard[i][j - 1]);
			}

			// Set rights - not last col
			if (j != COLS - 1)
			{
				gameBoard[i][j]->setRight(gameBoard[i][j + 1]);
			}
		}
	}
}


/*********************************************************************
** Function: movePlayer()
** Description: Gets and validates user input for player movement and
**				moves the player if the move is valid.
*********************************************************************/
void Board::movePlayer()
{
	// Get move from user
	std::cout << "Enter move: ";
	std::string move = "";
	std::getline(std::cin, move);

	// UP
	if (move == "i" && player->getUp() != nullptr) // && is for boundry checking
	{
		// function to check if space is legal move
		// function to reset symbol - use enums in switch
		// Move player up
		player = player->getUp();
		// set new space symbol to Q
		player->setSpaceSymbol("Q ");
	}
	// Down
	else if (move == "k" && player->getDown() != nullptr)
	{
		// Move player down
		player = player->getDown();

		// Set new space symbol to Q
		player->setSpaceSymbol("Q ");
	}
	// Left
	else if (move == "j" && player->getLeft() != nullptr)
	{
		// Move player left
		player = player->getLeft();

		// Set new space symbol to Q
		player->setSpaceSymbol("Q ");
	}
	// Right
	else if (move == "l" && player->getRight() != nullptr)
	{
		// Move player right
		player = player->getRight();

		// Set new space symbol to Q
		player->setSpaceSymbol("Q ");
	}
	else
	{
		std::cout << move << std::endl;
		std::cout << "That move is out of bounds" << std::endl;
	}
}
