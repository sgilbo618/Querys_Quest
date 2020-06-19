/*********************************************************************
** Program name: Query's Quest
** File: getCharInput.h
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the prototypes for getting single char user
**		user input on Linux OS. Uses termios to reset I/O settings so
**		only one character is taken in, and the user does not have to
**		hit enter.
*********************************************************************/
#ifdef __linux__

#include <termios.h>
#include <stdio.h>

static struct termios old, current;

void initTermios(int echo);
void resetTermios();
char getch_(int echo);
char getch();
char getche();

#endif