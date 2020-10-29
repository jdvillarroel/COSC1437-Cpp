#pragma once
#ifndef DAYS_H
#define	DAYS_H

#include	<iostream>
#include	<iomanip>
#include	<string>

using namespace std;

//Defines the menu options (Options 1 through 6)
enum menu
{
	SET_DAY = 1,
	PRINT_DAY,
	GET_DAY,
	GET_NEXT_DAY,
	GET_PREVIOUS_DAY,
	GET_FUTURE_DAY
};

//Reference for the index of the weekDays array
enum weekDays
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};



// Defines the datType class.
class dayType
{
private:
	//Used to print out the data on the console
	const	string	weekDays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday",
								"Thursday", "Friday", "Saturday" };
	string		_currentDay;
	int			_currentDayIndex;

public:
	//Constructor
	dayType();

	// Function prototypes for the current class
	void setDay();
	void printDay(string _day);
	string getCurrentDay();
	string getFutureDay(int _daysInFuture);
	string getNextDay();
	string getPreviousDay();

	int getUserSelection();
	void executeOption(int);

};



#endif // !DAYS_H



