/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
*/

/*
Assignment number 1:

Write a program to calculate students' average test scores and their grades. You may assume the following input data:

Johnson		85	83	77	91	76
Aniston		80	90	95	93	48
Cooper		78	81	11	90	73
Gupta		92	83	96	38	59
Blair		23	45	96	38	59
Clark		60	85	45	39	67
Kennedy		77	31	52	74	83
Bronson		93	94	89	77	97
Sunny		79	85	28	93	82
Smith		85	72	49	75	63


Use three arrays: a one-dimensional array to store the students' names, a (parallel) two-dimensional array to store the
test scores, and a parallel one-dimensional array to store grades. Your program must contain at least the following
functions: a function to read and store data into two arrays, a function to calculate the average test score and grade,
and a function to output the results. Have your program also output the class average.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//************* INPUT FILES INSTANCE DECLARATION ********************************//
ifstream	inFile_names;
ifstream	inFile_scores;

//************* GLOBAL VARIABLES ************************************************//
const	int		NUMBER_OF_STUDENTS = 10;
const	int		NUMBER_OF_TESTS = 5;

double	avg_score_by_test[NUMBER_OF_TESTS];			//Stores class avg score for each test
double	students_grade[NUMBER_OF_STUDENTS];			//Stores the total grade of each student
char	students_gradeLetter[NUMBER_OF_STUDENTS];	//Stores the total grade letter of each student
double	class_avg;									//Stores avg grade of the entire class

//************* FUNCTION PROTOTYPES *********************************************//
void readFiles(string [], double [][NUMBER_OF_TESTS]);

void displayResults(string[], double[][NUMBER_OF_TESTS], double [], double [], char []);

void calcAvgScoreGrade(double[][NUMBER_OF_TESTS], double [], char []);

char getGradeLetter(double);


int main()
{
	//Shows an initial message at the beginning of the program

	cout << "************************************************************\n"
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 1            **\n"
		<< "**         AVERAGE STUDENTS\' GRADES AND SCORES            **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "This program reads data stored in two text files which conaint\n"
		<< "the names and scores of the students in a class. Some statistics\n"
		<< "are displayed after processing the data.\n\n\n";


	//Variables to store the data read from files
	string	students_names[NUMBER_OF_STUDENTS];
	double	students_scores[NUMBER_OF_STUDENTS][NUMBER_OF_TESTS];

	//Call function to read files
	readFiles(students_names, students_scores);

	// Calculate Average scores and grades
	calcAvgScoreGrade(students_scores, students_grade, students_gradeLetter);

	// Display the results on the console
	displayResults(students_names, students_scores, students_grade, avg_score_by_test, students_gradeLetter);
	

	system("pause");
	return 0;
}
/// <summary>
/// This function opens and read the names and scores stored in the two files.
/// Two for loops (nested) are used to read the data from the files. The files
/// are closed before exiting the function.
/// </summary>
/// <param name="_names"></param>
/// <param name="_scores"></param>
void readFiles(string _names[], double _scores[][NUMBER_OF_TESTS])
{
	// Open the files containing the data to be proccessed
	inFile_names.open("names.txt");
	inFile_scores.open("scores.txt");

	/*
		These are the loops controling the reading of the data. There is a nested for loop
		to read the data by rows.
	*/
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		// Read the students' names from the file
		inFile_names >> _names[i];

		for (int j = 0; j < NUMBER_OF_TESTS; j++)
		{
			inFile_scores >> _scores[i][j];
		}
	}
	// Close the files
	inFile_names.close();
	inFile_scores.close();
}
/// <summary>
/// This function displays the data read from the two files and the results after proccessing the data.
/// It takes the four arrays where the data is stored. Inside this function the average of the class
/// is calculated while printing the average score of each test.
/// </summary>
/// <param name="_names"></param>
/// <param name="_scores"></param>
void displayResults(string _names[], double _scores[][NUMBER_OF_TESTS], double _grades[], double _avg_test[], char _letters[])
{
	double	class_avg = 0;			//Holds the average for the entire class

	//**************** Prints a header to format the output data ***************************//
	cout << setw(15) << left << "Student Name";

	// Displays the test number for better reference
	for (int j = 0; j < NUMBER_OF_TESTS; j++)
	{
		cout << setw(9) << right << "Test#" << (j + 1);
	}

	// Display a header where the student grade will be printed
	cout << setw(10) << right << "Grade";
	cout << endl;

	//*************** Display the data read from the files and grades **************************//
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		// Read the students' names from the file
		cout << setw(15) << left << _names[i];

		for (int j = 0; j < NUMBER_OF_TESTS; j++)
		{
			cout << setw(10) << right << fixed << showpoint << setprecision(2) << _scores[i][j];
			
		}
		// Display the grade obtained by each student by scanning the array contaning the data
		cout << setw(10) << right << fixed << showpoint << setprecision(2) << _grades[i];
		//cout << " (" << getGradeLetter(_grades[i]) << ")";
		cout << " (" << _letters[i] << ")";
		cout << endl;
	}

	//*************** Display the average data from the files *********************************//
	cout << endl << setw(15) << left << "Average score: ";

	/*
		Scan the array containing the class average by test and calculate the class average
		by adding the avg test while printing the result. When leaves the for loop the total
		is divided by the number of tests and prints the result.
	*/
	for (int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		cout << setw(10) << right << fixed << showpoint << setprecision(2) << _avg_test[i];
		class_avg += _avg_test[i];
	}
	//Calculate the average of the entire class by 
	class_avg /= NUMBER_OF_TESTS;

	//Print the result of the class average and get the equivalet letter
	cout << setw(10) << right << fixed << showpoint << setprecision(2) << class_avg;
	cout << " (" << getGradeLetter(class_avg) << ")";
	cout << endl << endl;
}
/// <summary>
/// This function scans the two dimensional array where the scores are stored. It scans the
/// scores by column(vertically) to calculate the average by test and by row(horizontally)
/// to calculate the grade of the student. It also takes a second array as parameter to
/// store the grades gotten by the students.
/// </summary>
/// <param name="_scores"></param>
/// <param name="_grades"></param>
void calcAvgScoreGrade(double _scores[][NUMBER_OF_TESTS], double _grades[], char _letter[])
{
	// Temporary holds the sum of the scores
	double	total_tests = 0;

	/*
		These two for loops scan the scores array to calculate the average score
		by test. The results are stored in an array. The array is scanned by columns.
	*/
	for (int j = 0; j < NUMBER_OF_TESTS; j++)			// Stablish the column to scan
	{
		
		for (int i = 0; i < NUMBER_OF_STUDENTS; i++)	//Stablish the row to scan
		{
			// Stores the sum for each test
			total_tests += _scores[i][j];
		}
		// The average for the respective test is calculated
		avg_score_by_test[j] = total_tests / NUMBER_OF_STUDENTS;

		//Resets the total value to be used in next cycle
		total_tests = 0.0;
	}

	// ***************** CALCULATE THE STUDENT GRADE *************************************//
	/*
		These two for loops scan the scores array to calculate the average score
		by student which gives the grade obtained by the student. The results are stored
		in an array. The array is scanned by rows.
	*/
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)	// Stablish the row to scan
	{

		for (int j = 0; j < NUMBER_OF_TESTS; j++)	//Stablish the column to scan
		{
			// Stores the sum for each test
			total_tests += _scores[i][j];
		}
		// The average for the respective test is calculated
		_grades[i] = total_tests / NUMBER_OF_TESTS;
		_letter[i] = getGradeLetter(_grades[i]);

		//Resets the total value to be used in next cycle
		total_tests = 0.0;
	}

}
/// <summary>
/// This function gets the equivalent letter grade. It is used while printing
/// the final grades of the students and the total class average.
/// </summary>
/// <param name="_grade"></param>
/// <returns></returns>
char getGradeLetter(double _grade)
{
	char letter;

	if (_grade >= 90.0)
		letter = 'A';
	else if (_grade >= 80.0)
		letter = 'B';
	else if (_grade >= 70.0)
		letter = 'C';
	else if (_grade >= 60.0)
		letter = 'D';
	else
		letter = 'F';

	return letter;
}
