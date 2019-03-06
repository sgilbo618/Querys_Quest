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

enum SpaceType {Free, Wall, Door, Key, Element, Boot, Query};

class Space
{
private:
	SpaceType type;
	char symbol;

	Space* up;
	Space* down;
	Space* left;
	Space* right;

public:
	// Constructor and Destructor
	Space();
	~Space();

	// Getters and Setters
	

	// Methods

};

#endif // !SPACE_HPP