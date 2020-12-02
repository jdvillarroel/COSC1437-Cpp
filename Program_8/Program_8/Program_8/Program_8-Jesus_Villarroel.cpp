/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program 8
*/

/*
Assignment number 8:

Write a recursive function that takes as a parameter a nonnegative integer and generates
the following pattern of stars. If the nonnegative integer is 4, then the pattern generated is:

* * * *
* * *
* *
*
* *
* * *
* * * *

*/

#include	<iostream>
#include	<iomanip>
#include	<string>

using	namespace std;



//============================================================
//					Function prototypes
//============================================================
void initMsg(void);
void printStars(int);
void printPattern(int);

int main()
{
	char	selection;				// Hold user selection to repeat the program.
	int		userSel;


	initMsg();

	// Prompt user to enter a positive integer to generate the patter. In case the
	// user enter a non number value or negative numbers, the buffer is cleared
	// from srros and additional characters entered.
	cout << "Please, enter the a positive integer number: ";
	cin >> userSel;
	cin.clear();
	cin.ignore(100, '\n');
	cout << endl;

	// Prompt user to enter valid data.
	while (userSel <= 0)
	{
		cout << "You must enter a positive integer number: ";
		cin >> userSel;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl;
	}

	// Call recursive function to print pattern.
	printPattern(userSel);

	// End of the program.
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
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 8            **\n"
		<< "**             HCC - COSC1437 Pattern Print               **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "Print a pattern using recursive functions. The function\n"
		<< "receives a positive integer number to generate the pattern.\n\n";

}

// Print a row of stars in the pattern.
void printStars(int num_of_stars)
{
	for (int i = 0; i < num_of_stars; i++)
		cout << "* ";
}

/// <summary>
/// There are two sequences defined. Seq = 0 to print in descending order, and
/// seq = 1 to print in ascending order.
/// </summary>
/// <param name="num"></param>
void printPattern(int num)
{

	static int limit = num;
	static int seq = 0;

	// Print stars in descending order.
	while (seq == 0)
	{
		// If all stars are printed. Change sequence.
		if (num == 0)
		{
			seq = 1;
			num = 1;		// Sets base for next sequence.
			break;
		}

		// Print stars and call next iteration.
		printStars(num);
		cout << endl;
		printPattern(num - 1);
	}
	
	// Print stars in ascending order.
	while (seq == 1)
	{
		// Selects a non existing sequence to break cycle.
		if (num == limit)
		{
			seq = 2;
			break;
		}

		// Print stars and call next iteration.
		printStars(num + 1);
		cout << endl;
		printPattern(num + 1);
	}

	return;

}

