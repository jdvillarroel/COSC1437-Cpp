/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program 3
*/

/**
Assignment number 3:

Design and implement a class dayType that implements the day of the week in a program. The class dayType
should store the day, such as Sun for Sunday. The program should be able to perform the following
operations on an object of type dayType:

    Set the day.
    Print the day.
    Return the day.
    Return the next day.
    Return the previous day.
    Calculate and return the day by adding certain days to the current day. For example, if the current
    day is Monday and we add 4 days, the day to be returned is Friday. Similarly, if today is Tuesday
    and we add 13 days, the day to be returned is Monday.
    Add the appropriate constructors.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <Windows.h>
#include "days.h"


using namespace std;

//Defines the instance of the dayType object created in days.h
dayType		day;


/********************************** Function Prototypes ******************************************/
void initMsg(void);


int main()
{
	char	again;			//Used to hold if user wants to continue
	int		menuOption;		//User selection from the menu

	// Displays a initial message on the console
	initMsg();


	do
	{
		//Get user selection from the menu
		menuOption = day.getUserSelection();

		//Execute user selection
		day.executeOption(menuOption);

		//Prompt the user to continue using the program or terminate
		//Continue with 'y' or 'Y' and terminates with any other character
		cout << "Would you like to continue? [y/n]: ";
		cin.get(again);

		//Ignore other characters the user might enter
		cin.ignore(100, '\n');
		cout << endl;
	} while (again == 'y' || again == 'Y' );

	cout << endl;
	system("pause");
	return 0;
}
/// <summary>
/// Display an initial message and instructions if necesary
/// </summary>
/// <param name=""></param>
void initMsg(void)
{
	system("Color F5");

	cout << "************************************************************\n"
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 3            **\n"
		<< "**                   DAYS OF THE WEEK                     **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "This program demonstrates the use of classes. It manipulates\n"
		<< "the days of the week and perform certain functions described\n"
		<< "as follow:\n";

	//Menu
	cout << "1.- Set the day - > .setDay(day);\n"
		<< "2.- Print the day - > .printDay();\n"
		<< "3.- Return the day - > .getDay();\n"
		<< "4.- Return the next day - > .getNextDay(day);\n"
		<< "5.- Return the previous day - > .getPreviousDay(day);\n"
		<< "6.- Return n days after day - > .getFutureDay(day+n);\n\n";

	cout << "Note: default day is Sunday.\n"
		<< ".getfutureDay() accepts negative values to go to previous days.\n\n";
	
}


