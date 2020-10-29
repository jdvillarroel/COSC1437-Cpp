/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program 2
*/

/**
Assignment number 2:

	Write a program that reads students' names followed by their test scores. The program should output each student's
	name followed by the test scores and the relevant grade. It should also find and print the highest test score and
	the name of the students having the highest test score.

	Student data should be stored in a struct variable of type studentType, which has four components: studentFName and
	studentLName of type string, testScore of type int (testScore is between 0 and 100), and grade of type char. Suppose
	that the class has 20 students. Use an array of 20 components of type studentType.

	Your program must contain at least the following functions:

		A function to read the students' data into the array.
		A function to assign the relevant grade to each student.
		A function to find the highest test score.
		A function to print the names of the students having the highest test score.

	Your program must output each student's name in this form: last name followed by a comma, followed by a space,
	followed by the first name; the name must be left justified. Moreover, other than declaring the variables and
	opening the input and output files, the function main should only be a collection of function calls.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/************************ CONSTANTS DECLARATION **********************************************/
const	int		NUMBER_OF_STUDENTS = 20;
const	int		NUMBER_OF_TESTS = 5;
const	string	FILE_NAME = "Program2_COSC1437.txt";
const	string	outFileName = "Results.txt";

/************************ STRUCTURE DECLARATION **********************************************/
struct studentType {
	string	studentFName;
	string	studentLName;
	int		testScore[NUMBER_OF_TESTS] = { 0 };
	char	grade = 'I';
};


/************************ GLOBAL VARIABLES DECLARATION ***************************************/
ifstream	inFile;
ofstream	outFile;
studentType	student[NUMBER_OF_STUDENTS];				//Main data storage array for each student
float		avgScore[NUMBER_OF_STUDENTS] = {0};			//Avg score by student
int			highestScoreByTest[NUMBER_OF_TESTS];		//Stores the highest score by test


/************************ FUNCTION PROTOTYPES ************************************************/
void initMsg(void);
void getStudentData(studentType [], ifstream &, string);
void displayResult(void);
void calcAvgScoreGrade(studentType [], float []);
char calcGrade(float);
void getHighestTestScore(studentType [], int []);
void printBestStudents(studentType[], int[]);


int main()
{
	//Shows an initial message at the beginning of the program
	initMsg();

	//Read information from the input file
	getStudentData(student, inFile, FILE_NAME);

	//Calculate the average score and grade for each student
	calcAvgScoreGrade(student, avgScore);

	//Gets the highest score by test, and store it in an array
	getHighestTestScore(student, highestScoreByTest);

	//Open the output file to store the data
	outFile.open(outFileName);

	//Show results on the console
	displayResult();

	//Prints the names of the student(s) who got the highest score
	printBestStudents(student, highestScoreByTest);

	outFile.close();

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
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 2            **\n"
		<< "**             STUDENTS\' GRADES AND SCORES                **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "This program reads data stored in a text filea which containt\n"
		<< "the names and scores of the students in a class. Some statistics\n"
		<< "are displayed after processing the data.\n\n\n";
}
/// <summary>
/// This function reads the data from the from the input file and save the data
/// into the array structure.
/// </summary>
/// <param name="_student"></param>
/// <param name="_inFile"></param>
/// <param name="_fileName"></param>
void getStudentData(studentType _student[], ifstream &_inFile, string _fileName)
{
	//Opens the file containing the students data
	_inFile.open(_fileName);

	/*
		Scans the file containing the students data. It stracts the student last
		name, first name, and the 5 test scores. A second for loop is nested to
		stract the test scores for each student.
	*/
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		_inFile >> student[i].studentLName;
		_inFile >> student[i].studentFName;

		/*
			Iterates over the scores and save it in the array for the test scores
			into the studentType structure
		*/
		for (int j = 0; j < NUMBER_OF_TESTS; j++)
		{
			_inFile >> student[i].testScore[j];
		}
	}

	//Ensures to close the file
	_inFile.close();
}
/// <summary>
/// Prints the data read from the file on the console and store it in the uotput file.
/// All the data is formatted for better visualization in the console and the output file.
/// It also prints the average score and grade of each student. As the variables are declared
/// as global the function does not take any parameter.
/// </summary>
/// <param name=""></param>
void displayResult(void)
{
	//It will store the full name of the student for better formatting
	string studentName;

	/******************** Prints a header to format the displayed data ********************/
	cout << setw(24) << left << "Student Name";
	outFile << setw(24) << left << "Student Name";

	/* prints header to idenify the test it is refering to */
	for (int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		cout << setw(7) << right << "Test " << (i + 1) << "  ";
		outFile << setw(7) << right << "Test " << (i + 1) << "  ";
	}

	/* header for Avg score and grade for each student */
	cout << setw(8) << "AvgScore" << "  ";
	outFile << setw(8) << "AvgScore" << "  ";

	cout << setw(5) << "Grade" << endl;
	outFile << setw(5) << "Grade" << endl;

	
	/******************** Prints information read from the file ***************************/
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		//Join full name for better formatting
		studentName = student[i].studentLName + ", " + student[i].studentFName;
		cout << left << setw(24) << studentName;

		//Prints data to the output file
		outFile << left << setw(24) << studentName;

		/*
			Iterates over the scores and save it in the array for the test scores
			into the studentType structure
		*/
		for (int j = 0; j < NUMBER_OF_TESTS; j++)
		{
			cout << setw(8) << right << student[i].testScore[j] << "  ";
			outFile << setw(8) << right << student[i].testScore[j] << "  ";
		}

		/***************** Prints avg score and grade for each student ********************/
		cout << fixed << showpoint << setprecision(1);				//Format float value
		outFile << fixed << showpoint << setprecision(1);

		cout << setw(8) << right << avgScore[i] << "  ";
		outFile << setw(8) << right << avgScore[i] << "  ";


		cout << setw(5) << right << student[i].grade << endl;
		outFile << setw(5) << right << student[i].grade << endl;

	}
	cout << endl;
	outFile << endl;
}
/// <summary>
/// This function calculates the average score that each student got after taking all the
/// tests. It also assigns the grade for the respective avg score of each student by calling
/// another function.
/// </summary>
/// <param name="_student"></param>
/// <param name="_avgScore"></param>
void calcAvgScoreGrade(studentType _student[], float _avgScore[])
{
	// ***************** CALCULATE THE STUDENT GRADE *************************************//
	/*
		These two for loops scan the scores array to calculate the average score
		by student which gives the grade obtained by the student. The results are stored
		in the structure. The array is scanned by rows.
	*/
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)	// Stablish the row to scan
	{

		for (int j = 0; j < NUMBER_OF_TESTS; j++)	//Stablish the column to scan
		{
			// Stores the sum for each test
			_avgScore[i] += _student[i].testScore[j];
		}
		// The average for the respective test is calculated
		_avgScore[i] /= NUMBER_OF_TESTS;

		//Get the equivalent grade from the score and save it to the structure
		student[i].grade = calcGrade(_avgScore[i]);
	}
}
/// <summary>
/// Gets the equivales grade for the avg score.
/// </summary>
/// <param name="_grade"></param>
/// <returns></returns>
char calcGrade(float _grade)
{
	char letter;

	if (_grade >= 89.5)
		letter = 'A';
	else if (_grade >= 79.5)
		letter = 'B';
	else if (_grade >= 69.5)
		letter = 'C';
	else if (_grade >= 59.5)
		letter = 'D';
	else
		letter = 'F';

	return letter;
}
/// <summary>
/// This function gets the highest score by test. It scans the array in the structure where
/// all the scores are stored. It scans the array column by column. The values of the highest
///	scores is saved in an a one dimensional array. That array will be later used to get the
/// names of the student(s) who got that grade on each test.
/// </summary>
/// <param name="_student"></param>
/// <param name="_highestScoreByTest"></param>
void getHighestTestScore(studentType _student[], int _highestScoreByTest[NUMBER_OF_TESTS])
{
	int highest = 0;
	int index = 0;

	/*
		Gets the highest score for each test. Then, that value will be used to find all
		the students who got that grade.
	*/
	for (int test = 0; test < NUMBER_OF_TESTS; test++)
	{
		for (int studentNumber = 0; studentNumber < NUMBER_OF_STUDENTS; studentNumber++)
		{
			if (_student[studentNumber].testScore[test] > highest)
				highest = _student[studentNumber].testScore[test];
		}
		//Save to the array containing the highest score
		_highestScoreByTest[test] = highest;

		//Resets for next cycle
		highest = 0;
	}
}
/// <summary>
/// This function prints to the console and save in an output file the names of the students
/// who got the highest score on each test. It uses the array that contains the highest score
/// by test as reference to get the names of the students from the structure containing the
/// data.
/// </summary>
/// <param name="_student"></param>
/// <param name="_higestScoreByTest"></param>
void printBestStudents(studentType _student[], int _higestScoreByTest[NUMBER_OF_TESTS])
{
	/*
		Prints the highest test score by each test saved in the received array.
	*/
	cout << left << setw(24) << "Highest Score";
	outFile << left << setw(24) << "Highest Score";

	for (int j = 0; j < NUMBER_OF_TESTS; j++)
	{
		cout << setw(8) << right << _higestScoreByTest[j] << "  ";
		outFile << setw(8) << right << _higestScoreByTest[j] << "  ";
	}

	//Gives some space for better visualization
	cout << endl << endl;
	outFile << endl << endl;

	/*
		Scans the structure to get the names of the students that matches the highest
		scores in the array. It scans the array by column.
	*/
	for (int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		cout << "Student(s) who got the highest score for Test " << (i + 1) << ":" << endl;
		outFile << "Student(s) who got the highest score for Test " << (i + 1) << ":" << endl;

		for (int j = 0; j < NUMBER_OF_STUDENTS; j++)
		{
			if (_student[j].testScore[i] >= _higestScoreByTest[i])
			{
				string name = _student[j].studentLName + ", " + _student[j].studentFName;
				cout << setw(24) << left << name << endl;
				outFile << setw(24) << left << name << endl;
			}
		}
		cout << endl;
		outFile << endl;
	}


}
