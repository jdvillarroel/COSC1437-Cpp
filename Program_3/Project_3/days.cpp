/*
	This file contains the function definition for the dayType class on days.h

*/
#include	"days.h"

/// <summary>
/// Display a menu on the console and prompt the user to select what
/// action he/she wants to perform on the current day.
/// </summary>
/// <param name=""></param>
void dayType::setDay(void)
{
	int		_day;				//Hold the value selected by the user

	cout << "1 -> Sunday\n"
		<< "2 -> Monday\n"
		<< "3 -> Tuesday\n"
		<< "4 -> Wednesday\n"
		<< "5 -> Thursday\n"
		<< "6 -> Friday\n"
		<< "7 -> Saturday\n\n";

	//Prompt the user to enter a selection
	cout << "Select the day you would like to set as current day: ";
	cin >> _day;

	//Ingnores other characters the user might enter to avoid errors due to invalid data
	cin.ignore(100, '\n');

	//Validates the selection is in the range specified and keep prompting if not
	while (_day < 1 || _day > 7)
	{
		cout << "Please, select the day you would like to set as current day(1 to 7): ";
		cin >> _day;
		cin.ignore(100, '\n');
	}
	cout << '\n';

	//Set the current day index and the actual day (string) in the private variable
	_currentDayIndex = _day - 1;
	_currentDay = weekDays[_currentDayIndex];

}

/// <summary>
/// Prints the day passed as argument
/// </summary>
/// <param name="_day"></param>
void dayType::printDay(string _day)
{
	cout << _day;
}

/// <summary>
/// Gets the day stored in the private variable which holds the current day selected.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
string dayType::getCurrentDay(void)
{
	return _currentDay;
}

/// <summary>
/// This is the most important function in the class. It calculates the future day
/// based on the number of days passed. If the number is positive it counts forward.
/// If the number is negative counts backwards.
/// </summary>
/// <param name="_daysInFuture"></param>
/// <returns></returns>
string dayType::getFutureDay(int _daysInFuture)
{
	int		daysToAdd;
	int		futureDay;

	/*
		Modulus function is used since the days added are multiples of 7(days of the week).
		Example: Adding 9 days is the same as adding 2, which we can get by 9 % 7
	*/
	daysToAdd = _daysInFuture % 7;

	/*
		Since I decided that the function will accept negative values to go to past days,
		if the number is negative we add 7 and make it positive. Example: Going 17 days
		to the past(-17days), first -17 % 7 = -3 -> going 3 days to the pass is the same
		as going 4 days forward which we get it by adding 7.
	*/
	if (daysToAdd < 0)
		daysToAdd += 7;

	/*
		This logic is used to determine how I add the days to the current day. If the days
		to add is greater than the days left before the saturday(last day of the week) it
		means the week will overflow, so I subtract 7. Example: If current day is
		Thursday(index 4) and I add 5 days (4+5=9), it is the same as adding 2 days to
		the beggining of the week(Sunday).
	*/
	if (daysToAdd > (static_cast<int>(SATURDAY) - _currentDayIndex))
	{
		futureDay = static_cast<int>(SUNDAY) + (_currentDayIndex + daysToAdd - 7);
	}
	else
	{
		futureDay = static_cast<int>(SUNDAY) + (_currentDayIndex + daysToAdd);
	}

	return weekDays[futureDay];
}

/// <summary>
/// Gets the day after the current day. It calls the getfutureday function and
/// pass 1 as argument.
/// </summary>
/// <returns></returns>
string dayType::getNextDay()
{
	return getFutureDay(1);
}

/// <summary>
/// Gets the day before of the current day. It calls the getFutureDay function
/// and pass -1 as argument to get the previuos day.
/// </summary>
/// <returns></returns>
string dayType::getPreviousDay()
{
	return getFutureDay(-1);
}
/// <summary>
/// Constructor function. It initialize the dayType class object. Default day is
/// Sunday and its index is zero.
/// </summary>
dayType::dayType() {
	_currentDay = weekDays[0];		//Sunday as default value
	_currentDayIndex = 0;
}


/********************************* Auxiliary functions *********************************/

/// <summary>
/// This function is used to get the menu option selected by the user. It returns the
/// user selection.
/// </summary>
/// <returns></returns>
int dayType::getUserSelection()
{
	int		_menuOption = 0;
	string	userDay;

	//Prompt the user to enter an option from the menu
	cout << "Please, select an option from the menu(1 throgh 6): ";
	cin >> _menuOption;

	//Ingnores other characters the user might enter to avoid errors due to invalid data
	cin.ignore(100, '\n');

	//Validates the selection is in the range specified.
	while (_menuOption <= 0 || _menuOption > 6)
	{
		cout << "Please, select a valid option (1 to 6): ";
		cin >> _menuOption;
		cin.ignore(100, '\n');
	}
	cout << '\n';
	return _menuOption;
}

/// <summary>
/// Executes the selected function by the user. it calls the appropiate functions
/// defined in the class. The enum type declared in the days.h header file is used
/// to validate the selection.
/// </summary>
/// <param name="_menuOption"></param>
void dayType::executeOption(int _menuOption)
{
	switch (_menuOption)
	{
	case (SET_DAY):
		dayType::setDay();
		cout << "Day selected: ";
		printDay(getCurrentDay());
		cout << endl << endl;
		break;

	case(PRINT_DAY):
		cout << "Current day is: ";
		printDay(getCurrentDay());
		cout << endl << endl;
		break;

	case(GET_DAY):
		cout << "Today is: ";
		printDay(getCurrentDay());
		cout << endl << endl;
		break;

	case(GET_NEXT_DAY):
		cout << "The next day is: ";
		printDay( getNextDay() );
		cout << endl << endl;
		break;

	case(GET_PREVIOUS_DAY):
		cout << "The previous day is: ";
		printDay( getPreviousDay() );
		cout << endl << endl;
		break;

	case(GET_FUTURE_DAY):
		int numDays;
		cout << "Please, enter number of days to add to current day: ";
		cin >> numDays;
		cin.ignore(100, '\n');
		cout << "Adding " << numDays << " days to current day gets: ";
		printDay( getFutureDay(numDays) );
		cout << endl << endl;
		break;

	default:
		break;
	}
}