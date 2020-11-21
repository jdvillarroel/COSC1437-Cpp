/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program 7
*/

/*
Assignment number 7:

Write a program that prompts the user to enter a person's date of birth in numeric
form such as 8-27-1980. The program then outputs the date of birth in the form:
August 27, 1980. Your program must contain at least two exception classes: invalidDay
and invalidMonth. If the user enters an invalid value for day, then the program should
throw and catch an invalidDay object. Similar conventions for the invalid values of
month and year. (Note that your program must handle a leap year.)
*/

#include	<iostream>
#include	<iomanip>
#include	<string>

using	namespace std;

//============================================================
//					Class Instances Definition
//============================================================
class DateOfBirthType
{
private:
	string	month_;
	int		day_;
	int		year_;
	bool	isLeap_;
	bool	isDateValid_;

public:
	// Constructors
	DateOfBirthType();

	// Member functions
	void setMonth(int);
	void setDay(int, int);
	void setYear(int);

	string getMonth(void) const;
	int getDay(void) const;
	int getYear(void) const;
	bool isLeapYear(int);
	bool isDateValid(void);
	void printDate(void) const;

	// Exception handler objects
	class invalidMoth
	{};

	class invalidDay
	{};

	class invalidYear
	{};

};

//============================================================
//					Global variables
//============================================================
// Jan(31), Feb(28), Mar(31), Apr(30), May(31), Jun(30), Jul(31), Aug(31), Sep(30), Oct(31), Nov(30), Dec(31).
const	int		MAX_DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const	string	MONTHS[12] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};


//============================================================
//					Function prototypes
//============================================================
void initMsg(void);

int main()
{
	char selection;				// Hold user selection to repeat the program.
	int		month = 0;			// Temporary variables to hold user data entered.
	int		day = 0;
	int		year = 0;

	// Instance of class declaration
	DateOfBirthType		birthDate;

	initMsg();

	do
	{
		// Prompt user to enter a date.
		cout << "Please enter your date of birth (MM-DD-YYYY): ";
		cin >> month;
		cin.ignore(1, '-');
		cin >> day;
		cin.ignore(1, '-');
		cin >> year;
		cin.ignore(100, '\n');
		cout << endl;

		try
		{
			// Set date based on user data.
			birthDate.setYear(year);

			birthDate.setMonth(month);

			birthDate.setDay(day, month);
		}
		// Catch blocks to handle exceptions in case of errors.
		catch (DateOfBirthType::invalidYear)
		{
			cout << "==============================================================" << endl;
			cout << "  A year must be greater than zero (0)" << endl;
			cout << "==============================================================" << endl;
		}
		catch (DateOfBirthType::invalidMoth)
		{
			cout << "==============================================================" << endl;
			cout << "  You entered an invalid month. Valid options are from 1 to 12." << endl;
			cout << "==============================================================" << endl;
		}
		catch (DateOfBirthType::invalidDay)
		{
			cout << "==============================================================" << endl;
			cout << "  Day entered is invalid." << endl;
			cout << "==============================================================" << endl;
		}

		// Print the date using new format if it is valid
		if (birthDate.isDateValid())
		{
			birthDate.printDate();
		}
		else
		{
			cout << "//////////////////////////////////////////////////////////////" << endl;
			cout << "  Date was not entered correctly or" << endl;
			cout << "  date entered does not correspond to our calendar." << endl;
			cout << "//////////////////////////////////////////////////////////////" << endl;
		}

		// Prompt the user to continue or finish program. Any entry different
		// from 'y' or 'Y' will finish the program.
		cout << endl << "Would you like to enter new data? [y/n]: ";
		selection = cin.get();
		cin.ignore(100, '\n');
		cout << endl;
	} while (selection == 'y' || selection == 'Y');

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
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 7            **\n"
		<< "**              HCC - COSC1437 Exceptions                 **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "Exceptions handler assignment program.\n"
		<< "To determine if the date entered is invalid it first checks\n"
		<< "the year, next the month, and last, the day.\n\n";

}

//============================================================
//					Class Member Functions
//============================================================

// Default constructor. Initialize private variables.
DateOfBirthType::DateOfBirthType()
{
	// Initialize class variables
	month_ = "";
	day_ = 0;
	year_ = 0;
	isLeap_ = false;
	isDateValid_ = false;
}

/// <summary>
/// Determine if the year entered is leap. 3 rules must be checked to determine
/// if it is a leap year.
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
bool DateOfBirthType::isLeapYear(int year)
{
	// To determine a leap year, it has to pass 3 rules:
	// 1. It has to be evenly divisible by 4, then it might be leap.
	// 2. If it is evenly divisible by 4, but also by 100, it is not leap. Unless...
	// 3. It is also evenly divisible by 400, then it is leap.
	bool leap = false;

	if (year % 4 == 0)
		leap = true;

	if (year % 100 == 0)
		leap = false;

	if (year % 400 == 0)
		leap = true;

	return leap;
}

/// <summary>
/// Set the year according the user data entered. It calls another
/// function to verify if it is a leap year. If so, it marks a flag.
/// </summary>
/// <param name="year"></param>
void DateOfBirthType::setYear(int year)
{
	// If a negative number is entered for year, an exception is thrown.
	if (year <= 0)
	{
		isDateValid_ = false;
		throw invalidYear();
	}
	else
	{
		// Verify if leap year. It will help in case Feb 29 is entered.
		isLeap_ = isLeapYear(year);
		isDateValid_ = true;
		year_ = year;
	}
	
}

/// <summary>
/// Set the month according to the user data entered. Verifies if the month is
/// in the acceptable range (1-12).
/// </summary>
/// <param name="month"></param>
void DateOfBirthType::setMonth(int month)
{
	// Month out of bounds.
	bool	monthOutOfRange = month <= 0 || month > 12;

	// Throw exception when month is out of allowed range.
	if (monthOutOfRange)
	{
		isDateValid_ = false;
		throw invalidMoth();
	}		
	else
	{
		isDateValid_ = true;
		month_ = MONTHS[month - 1];
	}
		
}

/// <summary>
/// Set the day according to the user entered data. Verifies if the day match
/// the selected month, including Feb 29 on leap years.
/// </summary>
/// <param name="day"></param>
/// <param name="month"></param>
void DateOfBirthType::setDay(int day, int month)
{
	// Set flag if current month is February. Needed to add 1 day during leap years.
	bool	isFebruary = month == 2;
	bool	dayOutOfRange;

	// Set bounds to the day entered by user considering leap year and current month.
	if (isLeap_ && isFebruary)
		dayOutOfRange = day <= 0 || (day > MAX_DAYS_IN_MONTH[month - 1] + 1);
	else
		dayOutOfRange = day <= 0 || day > MAX_DAYS_IN_MONTH[month - 1];

	// Check if flag was set to throw error or set variable.
	if (dayOutOfRange)
	{
		isDateValid_ = false;
		throw invalidDay();
	}		
	else
	{
		isDateValid_ = true;
		day_ = day;
	}
}

/// <summary>
/// Get month
/// </summary>
/// <param name=""></param>
/// <returns></returns>
string DateOfBirthType::getMonth(void) const
{
	return DateOfBirthType::month_;
}

/// <summary>
/// Gets day.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int DateOfBirthType::getDay(void) const
{
	return DateOfBirthType::day_;
}

/// <summary>
/// Gets year.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int DateOfBirthType::getYear(void) const
{
	return DateOfBirthType::year_;
}

/// <summary>
/// Flag to indicate if date entered is valid or not.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
bool DateOfBirthType::isDateValid(void)
{
	return DateOfBirthType::isDateValid_;
}

/// <summary>
/// Prints to the screen if date is valid. Uses a different format than the entered by
/// the user.
/// </summary>
/// <param name=""></param>
void DateOfBirthType::printDate(void) const
{
	cout << "==============================================================" << endl;
	cout << "  Date entered: " << getMonth() << " " << getDay() << ", " << getYear() << endl;
	cout << "==============================================================" << endl;
}
