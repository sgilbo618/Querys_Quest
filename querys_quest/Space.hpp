/*********************************************************************
** Program name: Query's Quest
** File: Space.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the declaration of the class Space which is
**				an abstract base case that represents the basic tile
**				of the game board for Query's Quest. Each Space has
**				a character to signify it's type and four pointers to
**				other Spaces in the directions of up, down, left, and
**				right.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

enum SpaceType {FREE, WALL, DOOR, KEY, ELEMENT, BOOT, QUERY};

class Space
{
protected:
	SpaceType type;
	std::string symbol;

	Space* up;
	Space* down;
	Space* left;
	Space* right;

public:
	// Constructor and Destructor
	Space();
	~Space();

	// Getters and Setters
	std::string getSpaceSymbol();

	// Methods

};

#endif // !SPACE_HPP