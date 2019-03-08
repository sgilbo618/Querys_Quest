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
#include "Ice.hpp"
#include "Fire.hpp"
#include "Water.hpp"
#include "Door.hpp"
#include "Key.hpp"

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

	while (player.checkIsAlive())
	{
		player.movePlayer();
		printGameBoard();
		checkForElements();
		checkForItems();
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
	// Blue Key
	gameBoard[13][6] = new Key("b ", BLUEKEY);

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
	// Green Key
	gameBoard[1][5] = new Key("g ", GREENKEY);
	
	// Walls
	gameBoard[0][12] = new Wall; gameBoard[1][12] = new Wall; gameBoard[2][12] = new Wall;
	gameBoard[3][12] = new Wall; gameBoard[4][12] = new Wall; gameBoard[5][12] = new Wall;
	gameBoard[6][12] = new Wall; gameBoard[7][12] = new Wall; gameBoard[8][12] = new Wall;
	gameBoard[9][12] = new Wall; gameBoard[10][12] = new Wall; gameBoard[11][0] = new Wall;
	gameBoard[11][1] = new Wall; gameBoard[11][2] = new Wall; gameBoard[11][3] = new Wall;
	gameBoard[11][4] = new Wall; gameBoard[11][5] = new Wall; gameBoard[11][6] = new Wall;
	gameBoard[11][7] = new Wall; gameBoard[11][10] = new Wall; gameBoard[11][11] = new Wall;
	gameBoard[11][12] = new Wall; 

	// Free
	gameBoard[1][3] = new Free; gameBoard[2][1] = new Free;
	gameBoard[2][6] = new Free; gameBoard[4][7] = new Free; gameBoard[4][10] = new Free;
	gameBoard[5][3] = new Free; gameBoard[5][6] = new Free; gameBoard[7][4] = new Free;
	gameBoard[7][9] = new Free; gameBoard[9][1] = new Free; gameBoard[9][7] = new Free;
	gameBoard[10][4] = new Free; gameBoard[10][10] = new Free;

	// Water
	for (int i = 0; i <= 11; i++)
	{
		gameBoard[0][i] = new Water;
		if (i < 11)
		{
			gameBoard[i][0] = new Water;
			gameBoard[i][11] = new Water;
		}
	}
	gameBoard[10][1] = new Water; gameBoard[10][2] = new Water; gameBoard[10][3] = new Water;

	// Ice
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (gameBoard[i][j] == nullptr)
			{
				gameBoard[i][j] = new Ice;
			}
		}
	}
	gameBoard[10][5] = new Ice; gameBoard[10][6] = new Ice; gameBoard[10][7] = new Ice;
	gameBoard[10][8] = new Ice; gameBoard[10][9] = new Ice;
}

void Board::createMazeRoom()
{
	// Red Key
	gameBoard[22][8] = new Key("r ", REDKEY);
	
	// Walls
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

	// Fire
	gameBoard[21][8] = new Fire;
}

void Board::createWaterRoom()
{
	// Green Door
	gameBoard[17][13] = new Door("G ");
	
	// Walls
	gameBoard[17][10] = new Wall; gameBoard[17][11] = new Wall; gameBoard[17][12] = new Wall;
	gameBoard[17][14] = new Wall; gameBoard[17][15] = new Wall; gameBoard[17][16] = new Wall;
	gameBoard[17][17] = new Wall; gameBoard[17][18] = new Wall; gameBoard[18][18] = new Wall;
	gameBoard[19][18] = new Wall; gameBoard[20][18] = new Wall; gameBoard[21][18] = new Wall;
	gameBoard[22][18] = new Wall; gameBoard[23][18] = new Wall; gameBoard[24][18] = new Wall;

	// Water
	gameBoard[19][11] = new Water; gameBoard[19][12] = new Water; gameBoard[19][13] = new Water;
	gameBoard[19][14] = new Water; gameBoard[19][15] = new Water; gameBoard[19][16] = new Water;
	gameBoard[19][17] = new Water; gameBoard[20][11] = new Water; gameBoard[21][11] = new Water;
	gameBoard[21][13] = new Water; gameBoard[21][14] = new Water; gameBoard[21][15] = new Water;
	gameBoard[21][16] = new Water; gameBoard[22][11] = new Water; gameBoard[22][16] = new Water;
	gameBoard[23][11] = new Water; gameBoard[23][12] = new Water; gameBoard[23][13] = new Water;
	gameBoard[23][14] = new Water; gameBoard[23][15] = new Water; gameBoard[23][16] = new Water;
}

void Board::createMixRoom()
{
	// Blue Door
	gameBoard[15][18] = new Door("B ");
	
	for (int i = 19; i <= 24; i++)
	{
		// Walls
		gameBoard[11][i] = new Wall;

		// Fire
		gameBoard[12][i] = new Fire; gameBoard[19][i] = new Fire; gameBoard[22][i] = new Fire;

		// Ice
		gameBoard[17][i] = new Ice; gameBoard[18][i] = new Ice;
		if (i >= 21 && i <= 23)
		{
			gameBoard[14][i] = new Ice; gameBoard[15][i] = new Ice; gameBoard[16][i] = new Ice;
		}
	}
	// More ice
	gameBoard[13][19] = new Ice; gameBoard[13][20] = new Ice; gameBoard[13][22] = new Ice; 
	gameBoard[13][23] = new Ice;

	// More fire
	gameBoard[13][24] = new Fire; gameBoard[14][24] = new Fire; gameBoard[15][24] = new Fire;
	gameBoard[16][24] = new Fire; gameBoard[17][24] = new Fire; gameBoard[18][24] = new Fire;
}

void Board::createFinishRoom()
{
	// Red Door
	gameBoard[11][16] = new Door("R ");

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

	// Ice
	gameBoard[6][16] = new Ice; gameBoard[7][16] = new Ice; gameBoard[8][16] = new Ice;
	gameBoard[9][15] = new Ice; gameBoard[9][16] = new Ice; gameBoard[9][17] = new Ice;
	gameBoard[9][20] = new Ice; gameBoard[9][21] = new Ice; gameBoard[9][22] = new Ice;
	gameBoard[10][15] = new Ice; gameBoard[10][16] = new Ice; gameBoard[10][17] = new Ice;
	gameBoard[10][20] = new Ice; gameBoard[10][21] = new Ice; gameBoard[10][22] = new Ice;

	// Fire
	gameBoard[5][18] = new Fire; gameBoard[5][19] = new Fire; gameBoard[5][20] = new Fire;
	gameBoard[6][18] = new Fire; gameBoard[6][19] = new Fire; gameBoard[6][20] = new Fire;

	// Water
	gameBoard[8][13] = new Water; gameBoard[8][14] = new Water; gameBoard[8][15] = new Water;
	gameBoard[8][17] = new Water; gameBoard[8][18] = new Water; gameBoard[9][13] = new Water;
	gameBoard[9][14] = new Water; gameBoard[9][18] = new Water; gameBoard[10][14] = new Water;
	gameBoard[10][18] = new Water;
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
** Function: checkForElements()
** Description: Gets the player's current position and checks to see
**				if player is on any element spaces. If it is, it
**				calls the appropriate element function.
*********************************************************************/
void Board::checkForElements()
{
	ElementType elementType = player.playerPtr->getElementType();

	switch (elementType)
	{
	case ICE:
		onIce();
		break;

	case FIRE:
		onFire();
		break;

	case WATER:
		onWater();
		break;
	}
}


/*********************************************************************
** Function: onIce()
** Description: Checks if player has ice boots. If they don't, player
**				slides until not on ice anymore. If they do, player
**				walks like normal.
*********************************************************************/
void Board::onIce()
{
	// Get direction
	Direction direction = player.getDirection();
	std::cout << direction << std::endl;
	
	while (player.playerPtr->getElementType() == ICE)
	{	
		switch (direction)
		{
		case UP:
			if (player.playerPtr->getUp() != nullptr && player.playerPtr->getUp()->getType() != WALL)
			{
				player.resetSpaceSymbol();
				player.playerPtr = player.playerPtr->getUp();
				player.playerPtr->setSpaceSymbol("Q ");
				//player.makeMove(player.playerPtr->getUp());
			}
			else
			{
				direction = DOWN;
			}
			break;
		case DOWN:
			if (player.playerPtr->getDown() != nullptr && player.playerPtr->getDown()->getType() != WALL)
			{
				player.resetSpaceSymbol();
				player.playerPtr = player.playerPtr->getDown();
				player.playerPtr->setSpaceSymbol("Q ");
				//player.makeMove(player.playerPtr->getDown());
			}
			else
			{
				direction = UP;
			}
			break;
		case LEFT:
			if (player.playerPtr->getLeft() != nullptr && player.playerPtr->getLeft()->getType() != WALL)
			{
				player.resetSpaceSymbol();
				player.playerPtr = player.playerPtr->getLeft();
				player.playerPtr->setSpaceSymbol("Q ");
				//player.makeMove(player.playerPtr->getUp());
			}
			else
			{
				direction = RIGHT;
			}
			break;
		case RIGHT:
			if (player.playerPtr->getRight() != nullptr && player.playerPtr->getRight()->getType() != WALL)
			{
				player.resetSpaceSymbol();
				player.playerPtr = player.playerPtr->getRight();
				player.playerPtr->setSpaceSymbol("Q ");
				//player.makeMove(player.playerPtr->getUp());
			}
			else
			{
				direction = LEFT;
			}
			break;
		}
		printGameBoard();
		player.playerPtr->displayMessage();
	}
	checkForElements();
}


/*********************************************************************
** Function: onFire()
** Description: Checks if player has fire boots. If it does not, sets
**				isAlive to false. Displays fire message.
*********************************************************************/
void Board::onFire()
{
	player.isAlive = false;
	player.playerPtr->displayMessage();
}


/*********************************************************************
** Function: onWater()
** Description: Checks if player has water boots. If it does not, sets
**				isAlive to false. Displays water message.
*********************************************************************/
void Board::onWater()
{
	player.isAlive = false;
	player.playerPtr->displayMessage();
}


/*********************************************************************
** Function: checkForItems()
** Description: Determines if the current space is an item. If it is
**				the item is added to the item array.
*********************************************************************/
void Board::checkForItems()
{
	SpaceType type = player.playerPtr->getType();
	ItemType itemType = player.playerPtr->getItemType();

	switch (type)
	{
	case KEY:
		unlockDoor();
		player.items[player.numberOfItems] = player.playerPtr;
		player.numberOfItems++;
		player.playerPtr->displayMessage();
		break;

	case BOOTS:
		
		break;
	}
}

void Board::unlockDoor()
{
	switch (player.playerPtr->getItemType())
	{
	case REDKEY:
		static_cast<Door*>(gameBoard[11][16])->setIsLocked(false);
		break;

	case BLUEKEY:
		static_cast<Door*>(gameBoard[15][18])->setIsLocked(false);
		break;

	case GREENKEY:
		static_cast<Door*>(gameBoard[17][13])->setIsLocked(false);
		break;
	}
}
