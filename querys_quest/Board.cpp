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

	// Build game board
	createGameBoard();

	// Build player
	player.playerPtr = gameBoard[15][10];
	player.playerPtr->setSpaceSymbol("Q ");
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
** Function: runGame()
** Description:
*********************************************************************/
void Board::runGame()
{
	printGameBoard();

	//int counter = 200;

	while (player.checkIsAlive())
	{
		player.movePlayer();
		printGameBoard();

		//counter--;
	}
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
** Function:
** Description:
*********************************************************************/
void Board::createGameBoard()
{
	createMainRoom();
	createIceRoom();
	createMazeRoom();
	createWaterRoom();
	createMixRoom();
	createFinishRoom();
	fillInEmptySpaces();
	setSpacePointers();
}

void Board::createMainRoom()
{
	// Walls
	gameBoard[11][5] = new Wall; gameBoard[11][6] = new Wall; gameBoard[11][7] = new Wall;
	gameBoard[11][10] = new Wall; gameBoard[11][11] = new Wall; gameBoard[11][12] = new Wall;
	gameBoard[11][13] = new Wall; gameBoard[11][14] = new Wall; gameBoard[11][15] = new Wall;
	gameBoard[11][17] = new Wall; gameBoard[11][18] = new Wall; gameBoard[12][5] = new Wall;
	gameBoard[12][18] = new Wall; gameBoard[13][5] = new Wall; gameBoard[13][18] = new Wall;
	gameBoard[14][5] = new Wall; gameBoard[14][18] = new Wall; gameBoard[16][5] = new Wall;
	gameBoard[16][18] = new Wall; gameBoard[17][5] = new Wall; gameBoard[17][6] = new Wall;
	gameBoard[17][7] = new Wall; gameBoard[17][8] = new Wall; gameBoard[17][9] = new Wall;
	gameBoard[17][10] = new Wall; gameBoard[17][11] = new Wall; gameBoard[17][12] = new Wall;
	gameBoard[17][14] = new Wall; gameBoard[17][15] = new Wall; gameBoard[17][16] = new Wall;
	gameBoard[17][17] = new Wall; gameBoard[17][18] = new Wall; 
}

void Board::createIceRoom()
{
	// Walls
	gameBoard[0][12] = new Wall; gameBoard[1][12] = new Wall; gameBoard[2][12] = new Wall;
	gameBoard[3][12] = new Wall; gameBoard[4][12] = new Wall; gameBoard[5][12] = new Wall;
	gameBoard[6][12] = new Wall; gameBoard[7][12] = new Wall; gameBoard[8][12] = new Wall;
	gameBoard[9][12] = new Wall; gameBoard[10][12] = new Wall; gameBoard[11][0] = new Wall;
	gameBoard[11][1] = new Wall; gameBoard[11][2] = new Wall; gameBoard[11][3] = new Wall;
	gameBoard[11][4] = new Wall; gameBoard[11][5] = new Wall; gameBoard[11][6] = new Wall;
	gameBoard[11][7] = new Wall; gameBoard[11][10] = new Wall; gameBoard[11][11] = new Wall;
	gameBoard[11][12] = new Wall; 
}

void Board::createMazeRoom()
{
	gameBoard[13][1] = new Wall; gameBoard[13][2] = new Wall; gameBoard[14][1] = new Wall;
	gameBoard[14][2] = new Wall; gameBoard[14][3] = new Wall; gameBoard[14][4] = new Wall;
	gameBoard[16][1] = new Wall; gameBoard[16][2] = new Wall; gameBoard[16][3] = new Wall;
	gameBoard[16][4] = new Wall; gameBoard[17][1] = new Wall; gameBoard[17][3] = new Wall;
	gameBoard[17][4] = new Wall; gameBoard[18][1] = new Wall; gameBoard[18][3] = new Wall;
	gameBoard[18][9] = new Wall; gameBoard[19][1] = new Wall; gameBoard[19][3] = new Wall;
	gameBoard[19][5] = new Wall; gameBoard[19][6] = new Wall; gameBoard[19][7] = new Wall;
	gameBoard[19][9] = new Wall; gameBoard[20][1] = new Wall; gameBoard[20][3] = new Wall;
	gameBoard[20][5] = new Wall; gameBoard[20][9] = new Wall; gameBoard[21][3] = new Wall;
	gameBoard[21][5] = new Wall; gameBoard[21][7] = new Wall; gameBoard[21][9] = new Wall;
	gameBoard[22][1] = new Wall; gameBoard[22][3] = new Wall; gameBoard[22][5] = new Wall;
	gameBoard[22][7] = new Wall; gameBoard[22][9] = new Wall; gameBoard[23][1] = new Wall;
	gameBoard[23][2] = new Wall; gameBoard[23][3] = new Wall; gameBoard[23][4] = new Wall;
	gameBoard[23][5] = new Wall; gameBoard[23][7] = new Wall; gameBoard[23][8] = new Wall;
	gameBoard[23][9] = new Wall; gameBoard[24][9] = new Wall;
}

void Board::createWaterRoom()
{
	// Walls
	gameBoard[17][10] = new Wall; gameBoard[17][11] = new Wall; gameBoard[17][12] = new Wall;
	gameBoard[17][14] = new Wall; gameBoard[17][15] = new Wall; gameBoard[17][16] = new Wall;
	gameBoard[17][17] = new Wall; gameBoard[17][18] = new Wall; gameBoard[18][18] = new Wall;
	gameBoard[19][18] = new Wall; gameBoard[20][18] = new Wall; gameBoard[21][18] = new Wall;
	gameBoard[22][18] = new Wall; gameBoard[23][18] = new Wall; gameBoard[24][18] = new Wall;
}

void Board::createMixRoom()
{
	// Walls
	gameBoard[11][19] = new Wall; gameBoard[11][20] = new Wall; gameBoard[11][21] = new Wall;
	gameBoard[11][22] = new Wall; gameBoard[11][23] = new Wall; gameBoard[11][24] = new Wall;
}

void Board::createFinishRoom()
{
	// Walls
	gameBoard[0][17] = new Wall; gameBoard[0][23] = new Wall; gameBoard[1][17] = new Wall;
	gameBoard[1][19] = new Wall; gameBoard[1][20] = new Wall; gameBoard[1][21] = new Wall;
	gameBoard[1][23] = new Wall; gameBoard[2][13] = new Wall; gameBoard[2][14] = new Wall;
	gameBoard[2][15] = new Wall; gameBoard[2][17] = new Wall; gameBoard[2][19] = new Wall;
	gameBoard[2][21] = new Wall; gameBoard[2][23] = new Wall; gameBoard[3][14] = new Wall;
	gameBoard[3][15] = new Wall; gameBoard[3][19] = new Wall; gameBoard[3][23] = new Wall;
	gameBoard[4][14] = new Wall; gameBoard[4][15] = new Wall; gameBoard[4][17] = new Wall;
	gameBoard[4][18] = new Wall; gameBoard[4][19] = new Wall; gameBoard[4][21] = new Wall;
	gameBoard[4][22] = new Wall; gameBoard[4][23] = new Wall; gameBoard[5][14] = new Wall;
	gameBoard[5][15] = new Wall; gameBoard[5][17] = new Wall; gameBoard[5][21] = new Wall;
	gameBoard[6][17] = new Wall; gameBoard[6][21] = new Wall; gameBoard[6][23] = new Wall;
	gameBoard[7][13] = new Wall; gameBoard[7][14] = new Wall; gameBoard[7][15] = new Wall;
	gameBoard[7][17] = new Wall; gameBoard[7][18] = new Wall; gameBoard[7][19] = new Wall;
	gameBoard[7][21] = new Wall; gameBoard[7][23] = new Wall; gameBoard[8][19] = new Wall;
	gameBoard[8][21] = new Wall; gameBoard[8][23] = new Wall; gameBoard[9][19] = new Wall;
	gameBoard[9][23] = new Wall; gameBoard[10][19] = new Wall; gameBoard[10][23] = new Wall;
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