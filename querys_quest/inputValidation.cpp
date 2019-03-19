/*********************************************************************
** Program name: Query's Quest
** File: inputValidation.hpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of input validation
**				functions, including for integers and doubles.
*********************************************************************/

#include "inputValidation.hpp"
#include <iostream>
#include <sstream>
#include <string>


/*********************************************************************
**Function: integerValidation()
** Description: Gets user input and returns it if it is an integer.
** Source:  https://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
*********************************************************************/
int integerValidation()
{
	std::string input;
	int selection;
	while (std::getline(std::cin, input))
	{
		std::stringstream inputSS(input);
		inputSS >> selection;
		if (inputSS.eof())
		{
			return selection;
		}
		else
		{
			std::cout << "\n**Invalid Entry**\n";
			std::cout << "Enter again: ";
		}
	}
}


/*********************************************************************
** Function: doubleValidation()
** Description: Gets user input and returns it if it is a double.
*********************************************************************/
double doubleValidation()
{
	double input;
	std::cin >> input;

	while (std::cin.fail() || (std::cin.peek() != '\r' && std::cin.peek() != '\n'))
	{
		// not a valid number
		std::cout << "\n**Invalid Entry**\n";
		std::cout << "Enter again: ";

		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cin >> input;
	}
	return input;
}