/*********************************************************************
** Program name: Query's Quest
** File: getCharInput.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the functions for getting single char user
**		user input on Linux OS. Uses termios to reset I/O settings to
**		take in a single char input without the user having to use
**		enter. Has options for echoing the char or not.
*********************************************************************/

// Only compile this file if on linux
#ifdef __linux__

#include "getCharInput.h"

/*********************************************************************
** Function: initTermios(int echo)
** Description: Initializes new terminal I/O settings. Takes in int
**    echo in order to set whether or not to echo input.
*********************************************************************/
void initTermios(int echo)
{
	tcgetattr(0, &old); /* grab old terminal i/o settings */
	current = old; /* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
	if (echo)
	{
		current.c_lflag |= ECHO; /* set echo mode */
	}
	else
	{
		current.c_lflag &= ~ECHO; /* set no echo mode */
	}
	tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}


/*********************************************************************
** Function: resetTermios()
** Description: Restore old terminal I/O settings.
*********************************************************************/
void resetTermios()
{
	tcsetattr(0, TCSANOW, &old);
}


/*********************************************************************
** Function: char getch_(int echo)
** Description: Reads one input character. Takes in int echo to define
**    what ehco mode to set.
*********************************************************************/
char getch_(int echo)
{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}


/*********************************************************************
** Function: getch(void)
** Description: Gets one character without echo.
*********************************************************************/
char getch()
{
	return getch_(0);
}


/*********************************************************************
** Function: getche(void)
** Description: Gets one character with echo.
*********************************************************************/
char getche()
{
	return getch_(1);
}

#endif