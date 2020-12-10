/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Final Course Project
*/


#include	"main.h"
#include	"Account.h"
#include	"Savings_Account.h"
#include	"Checking_Account.h"

//============================================================
//					Global variables
//============================================================
double		savingsInitBalance = 5000;
double		savingsAnnualIntRate = 0.01;
double		checkingInitBalance = 4500;
double		checkingAnnualIntRate = 0.005;

//============================================================
//					Class Instances Definition
//============================================================
SavingsAccount		savingsAccount(savingsInitBalance, savingsAnnualIntRate);
CheckingAccount		checkingAccount(checkingInitBalance, checkingAnnualIntRate);

//============================================================
//					Function prototypes
//============================================================
void initMsg(void);
void MenuSelection(int);
double getInput(void);

int main()
{
	int selection;

	//	Displays a initial message on the console
	initMsg();

	//	Menu options
	cout << "\n********** BANK MANAGMENT SYSTEM MENU **********\n"
		<< "1  -> Savings Account Deposit.\n"
		<< "2  -> Checking Account Deposit.\n"
		<< "3  -> Savings Account Withdrawal.\n"
		<< "4  -> Checking Account Withdrawal.\n"
		<< "5  -> Update and Display Accounts Statistics.\n"
		<< "0  -> Exit" << "\n\n";

	do
	{
		cout << "Please, enter your selection: ";
		cin >> selection;
		cin.clear();
		//	Ignore other characters the user might enter
		cin.ignore(100, '\n');

		MenuSelection(selection);

		cout << endl;
	} while (selection != 0);

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
		<< "**              WELCOME TO THE FINAL PROJECT              **\n"
		<< "**                  HCC - COSC1437 BANK                   **\n"
		<< "**              Made by: Jesus Villarroel                 **\n"
		<< "************************************************************\n\n";

	//Display a brief description of what the program does
	cout << "Bank account managment system.\n\n";

}


/// <summary>
/// Call the corresponding functions according to the menu selection.
/// </summary>
/// <param name="menu_selection"></param>
void MenuSelection(int menu_selection)
{
	double amount = 0.0;

	switch (menu_selection)
	{
	case 0:
		break;

	case 1:
		amount = getInput();
		savingsAccount.deposit(amount);
		break;

	case 2:
		amount = getInput();
		checkingAccount.deposit(amount);
		break;

	case 3:
		amount = getInput();
		savingsAccount.withdraw(amount);
		break;

	case 4:
		amount = getInput();
		checkingAccount.withdraw(amount);
		break;

	case 5:
		cout << "*****  SAVINGS ACCOUNT STATISTICS  *****" << endl;
		savingsAccount.monthlyProc();
		cout << endl << endl;

		cout << "*****  CHECKING ACCOUNT STATISTICS  *****" << endl;
		checkingAccount.monthlyProc();
		cout << endl;
		break;

	default:
		cout << "*****  You entered an invalid option.  ******" << endl;
		break;
	}
}

/// <summary>
/// Get user input and validate it.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double getInput(void)
{
	double	amount;

	cout << "Please, enter amount: $";
	cin >> amount;
	cin.clear();
	cin.ignore(100, '\n');

	while (amount < 0)
	{
		cout << "Please, enter amount: $";
		cin >> amount;
		cin.clear();
		cin.ignore(100, '\n');
	}
	return amount;
}

