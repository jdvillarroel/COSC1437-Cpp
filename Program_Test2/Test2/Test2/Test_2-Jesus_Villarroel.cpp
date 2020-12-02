/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program Test #2
*/

/*
Program Test #2:

write a recursive function program that prompts the user to enter the number of lines in the
pattern and uses the recursive function to generate the pattern. For example, specifying 4
as the number of lines generates the below pattern.

			*
		* 	* 	*
	* 	* 	* 	* 	*
* 	* 	* 	* 	* 	* 	*
	* 	* 	* 	* 	*
		* 	* 	*
			*
*/

#include	<iostream>
#include	<iomanip>
#include	<string>

using	namespace std;


//============================================================
//					Function prototypes
//============================================================
void initMsg(void);
void printSpace(int);
void printStar(int);
void printRhombus(int, int);

int main()
{
	char	selection;				// Hold user selection to repeat the program.
	int		lines = 0;

	initMsg();

	do
	{
		// Prompt the user to enter the data to print the pattern.
		cout << "Please, enter a positive integer number: ";
		cin >> lines;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl;

		// While data is not vslid the user will be prompted as needed.
		while (lines <= 0)
		{
			cout << "Please, enter a positive integer number: ";
			cin >> lines;
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl;
		}

		cout << "************************************************\n"
			<< "              Rhombus Pattern\n"
			<< "************************************************\n\n";

		// Print the pattern.
		printRhombus(lines, lines);

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
		<< "**               WELCOME TO THE TEST # 2                  **\n"
		<< "**              HCC - COSC1437 - Recursion                **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "Print a rhombus shape using a recursive function. The user\n"
		<< "enters a positive integer number which determines the number\n"
		<< "of lines the pattern will contain.\n\n";
}

/// <summary>
/// Print the spaces needed for the pattern.
/// </summary>
/// <param name="space"></param>
void printSpace(int space)
{
	// Base case. Break the recursive calls.
	if (space == 0)
		return;

	// Print a space to the console.
	cout << "  ";

	// Recursive call to print spaces.
	printSpace(space - 1);
}

/// <summary>
/// Print the stars line by line.
/// </summary>
/// <param name="star"></param>
void printStar(int star)
{
	// Base case. Break the recursive calls.
	if (star == 0)
		return;

	// Print a star to the console.
	cout << "* ";

	// Recursive call to print the stars.
	printStar(star - 1);
}

/// <summary>
/// This function prints the pattern line by line. The recursive calls are used
/// to print the upper side of the rhombus. Once the functions start to return
/// the print functions are used to print the lower part of the rhombus.
/// </summary>
/// <param name="n"></param>
/// <param name="m"></param>
void printRhombus(int n, int m)
{
	// Base case. Break the recursive calls.
	if (n == 0)
		return;

	// Print the spaces and stars line by line.
	printSpace(n - 1);
	printStar(m - n + 1);
	cout << endl;

	// Recursive calls.
	printRhombus(n - 1, m + 1);

	// Skip one line for the lower part of the rhombus, so there is not two
	// lines of the same length on the middle of the rhombus.
	if (n > 1)
	{
		printSpace(n - 1);
		printStar(m - n + 1);
		cout << endl;
	}
}
