/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program Test1
*/

/*
Programming part for test 1:

	Write a program that creates a two dimensional array initialized with test data.
	Use any data type you wish .  The program should have following functions:

	.getAverage: This function should accept a two dimensional array as its argument
	and return the average of each row (each student have their average) and each
	column (class test average) all the values in the array.

	.getRowTotal: This function should accept a two dimensional array as its first
	argument and an integer as its second argument.  The second argument should be
	the subscript of a row in the array. The function should return the total of
	the values in the specified row.

	.getColumnTotal:  This function should accept a two dimensional array as its
	first argument and an integer as its second argument.  The second argument
	should be the subscript of a column in the array. The function should return
	the total of the values in the specified column.

	.getHighestInRow: This function should accept a two dimensional array as its
	first argument and an integer as its second argument.  The second argument
	should be the subscript of a row in the array. The function should return
	the highest value in the specified row of the array.

	.getLowestInRow: This function should accept a two dimensional array as its
	first argument and an integer as its second argument.  The second argument
	should be the subscript of a row in the array. The function should return
	the lowest value in the specified row of the array.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

//*********************** Constant Variables ***************************************//
const	int		MAX_ROWS = 20;
const	int		MAX_COLUMNS = 5;
const	string	FILE_NAME = "data.txt";

//*********************** Global Variables *****************************************//
ifstream	inFile;
double		matrix[MAX_ROWS][MAX_COLUMNS] = {0};	//Two dimensional array
double		avgPerRow[MAX_ROWS] = {0};
double		avgPerColumn[MAX_COLUMNS] = {0};
double		highestInRow[MAX_ROWS] = { 0 };
double		lowestInRow[MAX_ROWS] = { 0 };


//*********************** Function Prototypes **************************************//
void initMsg(void);
void getDataFromFile(ifstream& inFile, string fileName, double matrix[][MAX_COLUMNS]);
void displayData(double _matrix[][MAX_COLUMNS], double[], double[], double[], double[]);
void getAverage(double[][MAX_COLUMNS], double[], double[]);
double getRowtotal(double[][MAX_COLUMNS], int);
double getColumnTotal(double[][MAX_COLUMNS], int);
double getHighestInRow(double[][MAX_COLUMNS], int);
double getLowestInRow(double[][MAX_COLUMNS], int);
void getHiLoInRows(double[][MAX_COLUMNS], double[], double[]);


int main()
{
	//Display initial message on the console
	initMsg();

	//Get data from the file
	getDataFromFile(inFile, FILE_NAME, matrix);

	/*
		Get average values for rows and columns and store them in the arrays
		passed as second and third arguments to the function
	*/
	getAverage(matrix, avgPerRow, avgPerColumn);

	/*
		Get the highest and lowest values in each row and store them in the
		global arrays passed as second and third arguments.
	*/
	getHiLoInRows(matrix, highestInRow, lowestInRow);

	//Displays the data read from the file
	displayData(matrix, avgPerRow, avgPerColumn, highestInRow, lowestInRow);


	system("pause");
	return 0;
}
/// <summary>
/// Display an initial message and instructions if neccesary
/// </summary>
/// <param name=""></param>
void initMsg(void)
{
	system("Color F5");

	cout << "************************************************************\n"
		<< "**           WELCOME TO THE PROGRAM FOR TEST 1            **\n"
		<< "**          TWO DIMENSIONAL ARRAY MANIPULATION            **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "This program reads data stored in a text file which contains\n"
		<< "a two dimensional array of floating ponit numbers. Some\n"
		<< "functions are used to demonstrate how the data can be\n"
		<< "accessed and manipulated.\n\n\n";
}

/// <summary>
/// This function is used to read the data from the input file. The data is stored
/// in the two dimensional array passed as argument.
/// </summary>
/// <param name="inFile"></param>
/// <param name="fileName"></param>
/// <param name="_matrix"></param>
void getDataFromFile(ifstream& inFile, string fileName, double _matrix[][MAX_COLUMNS])
{
	inFile.open(fileName);

	/*
		Reads the data from the input file. The array is scanned by
		rows to store the data.
	*/
	for (int row = 0; row < MAX_ROWS; row++)
	{
		for (int column = 0; column < MAX_COLUMNS; column++)
		{
			inFile >> _matrix[row][column];
		}
	}

	//Make sure to close the file
	inFile.close();
}

/// <summary>
/// Function used for displaying the data on the console. As the variables that store
/// the data are declared as global, there would not be neccesary to pass them as
/// arguments. But as the function might be used in other programs is better to define
/// the parameters that it receives.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="_highest"></param>
/// <param name="_lowest"></param>
void displayData(double _matrix[][MAX_COLUMNS], double avgByRow[], double avgByCol[], double _highest[], double _lowest[])
{
	// Prints a header for data data read from the file
	cout << setw(10) << left << " ";
	for (int i = 0; i < MAX_COLUMNS; i++)
	{
		cout << setw(7) << right << "  Col" << setw(2) << right << (i + 1);
	}
	cout << setw(9) << right << "Avg";
	cout << setw(9) << right << "Highest";
	cout << setw(9) << right << "Lowest" << endl;


	/*
		Prints data read on the console. The matrix is scanned by rows.
		Set the row and move through columns. After finishing printing the
		row data from extarcted from the file, the calculaterd values are
		printed. 
	*/
	for (int row = 0; row < MAX_ROWS; row++)
	{
		//Format the data before printing
		cout << fixed << showpoint << setprecision(2);
		cout << "Row " << setw(6) << left << (row + 1);

		//Prints data from the input file
		for (int column = 0; column < MAX_COLUMNS; column++)
		{
			cout << setw(9) << right << _matrix[row][column];
		}
		
		//Print the calculated values based on the data read
		cout << setw(9) << right << avgByRow[row];
		cout << setw(9) << right << _highest[row];
		cout << setw(9) << right << _lowest[row] << endl;
	}
	cout << endl;

	//The average data of each column is printed in the last row
	cout << setw(10) << left << "Average";
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < MAX_COLUMNS; i++)
	{
		cout << setw(9) << right << avgByCol[i];
	}
	cout << endl << endl;

}

/// <summary>
/// Function used for getting the average values by row and column. The getRowTotal
/// and getColumnTotal functions are used inside this function.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="_avgPerRow"></param>
/// <param name="_avgPerColumn"></param>
void getAverage(double _matrix[][MAX_COLUMNS], double _avgPerRow[], double _avgPerColumn[])
{
	/*
		Gets the average per row by calling the getRowTotal function and dividing
		by the number of columns. Teh result is stored in a one dimensional array
		declared as global variable.
	*/
	for (int row = 0; row < MAX_ROWS; row++)
	{
		_avgPerRow[row] = getRowtotal(_matrix, row) / MAX_COLUMNS;
	}
	
	/*
		Gets the average per column by calling the getColumnTotal function and
		dividing by the number of rows. Teh result is stored in a one dimensional
		array declared as global variable.
	*/
	for (int column = 0; column < MAX_COLUMNS; column++)
	{
		_avgPerColumn[column] = getColumnTotal(_matrix, column) / MAX_ROWS;
	}


}

/// <summary>
/// Calculates the sum of all the values on a specific row. The two dimensional
/// array and the desired row to calculate the sum are passed as arguments.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="row_index"></param>
/// <returns></returns>
double getRowtotal(double _matrix[][MAX_COLUMNS], int row_index)
{
	double	rowTotal = 0.0;

	/*
		Scans the row and add every value which will be returned at the
		end of the for loop.
	*/
	for (int column = 0; column < MAX_COLUMNS; column++)
	{
		rowTotal += _matrix[row_index][column];
	}

	return rowTotal;
}

/// <summary>
/// Calculates the sum of all the elements in a specific column of the two
/// dimensional array. The column is passed as the second argument for the
/// function.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="column_index"></param>
/// <returns></returns>
double getColumnTotal(double _matrix[][MAX_COLUMNS], int column_index)
{
	double	columnTotal = 0.0;

	/*
		Scans the column and add every value which will be returned at the
		end of the for loop.
	*/
	for (int row = 0; row < MAX_ROWS; row++)
	{
		columnTotal += _matrix[row][column_index];
	}

	return columnTotal;
}

/// <summary>
/// Calculate the highest value on the specified row of the two dimensional
/// array. The second argument determines the selected row index.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="row_index"></param>
/// <returns></returns>
double getHighestInRow(double _matrix[][MAX_COLUMNS], int row_index)
{
	double	highest;

	highest = _matrix[row_index][0];
	for (int column = 1; column < MAX_COLUMNS; column++)
	{
		if (_matrix[row_index][column] > highest)
			highest = _matrix[row_index][column];
	}

	return highest;
}

/// <summary>
/// Calculates the lowest value on the specified row of the two dimensional
/// array. The second argument determines the selected row index.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="row_index"></param>
/// <returns></returns>
double getLowestInRow(double _matrix[][MAX_COLUMNS], int row_index)
{
	double	lowest;

	lowest = _matrix[row_index][0];

	for (int column = 1; column < MAX_COLUMNS; column++)
	{
		if (_matrix[row_index][column] < lowest)
			lowest = _matrix[row_index][column];
	}

	return lowest;
}

/// <summary>
/// This function is used to determine all the highest and lowest values
/// of each row of the two dimensional array. The values are stored in
/// two one dimensional arrays of lenght MAX_ROWS.
/// </summary>
/// <param name="_matrix"></param>
/// <param name="_highest"></param>
/// <param name="_lowest"></param>
void getHiLoInRows(double _matrix[][MAX_COLUMNS], double _highest[], double _lowest[])
{
	/*
		Gets the highest value for every single row of the two dimensional array.
	*/
	for (int row = 0; row < MAX_ROWS; row++)
	{
		_highest[row] = getHighestInRow(_matrix, row);
	}

	/*
		Gets the lowest value for every single row of the two dimensional array.
	*/
	for (int row = 0; row < MAX_ROWS; row++)
	{
		_lowest[row] = getLowestInRow(_matrix, row);
	}
}
