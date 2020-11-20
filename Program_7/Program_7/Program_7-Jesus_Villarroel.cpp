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
	bool	leap_;

public:
	// Constructors
	DateOfBirthType();

	// Member functions
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	string getMonth(void);
	int getDay(void);
	int getYear(void);
	string getFullDate(string, int, int);
	bool isLeapYear(int);

	// Exception handler objects
	class invalidMoth
	{};

	class invalidDay
	{};

	class invalidYear
	{};

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
	bool	leap = false;

	DateOfBirthType		birthDate;

	initMsg();

	do
	{
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
			birthDate.setYear(year);
		}
		catch (DateOfBirthType::invalidYear)
		{
			cout << "A year must be greater than zero (0)" << endl;
		}


		// Prompt the user to continue or finish program. Any entry different
		// from 'y' or 'Y' will finish the program.
		cout << "Would you like to enter new data? [y/n]: ";
		selection = cin.get();
		cin.ignore(100, '\n');
		
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
	cout << "Exceptions handler assignment program.\n\n";

}

//============================================================
//					Class Member Functions
//============================================================
DateOfBirthType::DateOfBirthType()
{
	// Initialize class variables
	month_ = "";
	day_ = 0;
	year_ = 0;
	leap_ = false;
}

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


void DateOfBirthType::setYear(int year)
{
	// If a negative number is entered for year, an exception is thrown.
	if (year <= 0)
	{
		throw invalidYear();
	}
	else
	{
		// Verify if leap year. It will help in case Feb 29 is entered.
		leap_ = isLeapYear(year);

		year_ = year;
	}
	
}