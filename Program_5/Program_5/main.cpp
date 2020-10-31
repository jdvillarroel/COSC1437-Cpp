/*
Author: Jesus Villarroel
Class: COSC1437
Period: Fall 2020
Program 5
*/

/*
Assignment number 5:

Banks offer various types of accounts, such as savings, checking, certificate of deposits, and money market,
to attract customers as well as meet their specific needs. Two of the most commonly used accounts are savings
and checking. Each of these accounts has various options. For example, you may have a savings account that
requires no minimum balance but has a lower interest rate. Similarly, you may have a checking account that
limits the number of checks you may write. Another type of account that is used to save money for the long
term is certificate of deposit (CD).

In this programming exercise, you use classes and functions to design classes to manipulate various types of
accounts. For simplicity, assume that the bank offers three types of accounts: savings, checking, and
certificate of deposit, as described next.

Savings accounts: Suppose that the bank offers two types of savings accounts: one that has no minimum balance
and a lower interest rate and another that requires a minimum balance and has a higher interest rate.

Checking accounts: Suppose that the bank offers three types of checking accounts: one with a monthly service
charge, limited check writing, no minimum balance, and no interest; another with no monthly service charge, a
minimum balance requirement, unlimited check writing and lower interest; and a third with no monthly service
charge, a higher minimum requirement, a higher interest rate, and unlimited check writing.

Certificate of deposit (CD): In an account of this type, money is left for some time, and these accounts draw
higher interest rates than savings or checking accounts. Suppose that you purchase a CD for six months. Then
we say that the CD will mature in six months. The penalty for early withdrawal is stiff.

Figure below  shows the inheritance hierarchy of these bank accounts.

										bankAccount

						/                   |                         \

		checkingAccount                 certificateofDeposit            savingAccount

		 |                \													   |

serviceChargeChecking       noServiceChargeChecking                  highInterestSaving

									|

						 hightInterestChecking

Inheritance hierarchy of banking accounts

Note that the classes bankAccount and checkingAccount are abstract. That is, we cannot instantiate objects
of these classes. The other classes in Figure above.

bankAccount: Every bank account has an account number, the name of the owner, and a balance. Therefore,
instance variables such as name, accountNumber, and balance should be declared in the abstract class bankAccount.
Some operations common to all types of accounts are retrieve account owner's name, account number, and account
balance; make deposits; withdraw money; and create monthly statement. So include functions to implement these
operations. Some of these functions will be pure virtual.

checkingAccount: A checking account is a bank account. Therefore, it inherits all the properties of a bank
account. Because one of the objectives of a checking account is to be able to write checks, include the pure
virtual function writeCheck to write a check.

serviceChargeChecking: A service charge checking account is a checking account. Therefore, it inherits all the
properties of a checking account. For simplicity, assume that this type of account does not pay any interest,
allows the account holder to write a limited number of checks each month, and does not require any minimum balance.
Include appropriate named constants, instance variables, and functions in this class.

noServiceChargeChecking: A checking account with no monthly service charge is a checking account. Therefore, it
inherits all the properties of a checking account. Furthermore, this type of account pays interest, allows the
account holder to write checks, and requires a minimum balance.

highInterestChecking: A checking account with high interest is a checking account with no monthly service charge.
Therefore, it inherits all the properties of a no service charge checking account. Furthermore, this type of
account pays higher interest and requires a higher minimum balance than the no service charge checking account.

savingsAccount: A savings account is a bank account. Therefore, it inherits all the properties of a bank account.
Furthermore, a savings account also pays interest.

highInterestSavings: A high-interest savings account is a savings account. Therefore, it inherits all the
properties of a savings account. It also requires a minimum balance.

certificateOfDeposit: A certificate of deposit account is a bank account. Therefore, it inherits all the properties
of a bank account. In addition, it has instance variables to store the number of CD maturity months, interest rate,
and the current CD month.

*/

/*
	Note: The rules for the name convention used in this program tries to follow the Google C++ Style Guide.
	More information can be found at: https://google.github.io/styleguide/cppguide.html#C++_Version
*/

#include	"main.h"
#include	"bank_account.h"
#include	"checking_account.h"
#include	"savings_account.h"
#include	"certificate_of_deposit.h"

//============================================================
//					Class Instances Definition
//============================================================

//	Arguments: Account holder name, Account number, initial balance
ServiceChargeChecking sc_checking("Jesus Villarroel", 9876543210, 5000);
NoServiceChargeChecking no_sc_checking("Jesus Villarroel", 9876123450, 5000);
HighInterestChecking hi_checking("Jesus Villarroel", 9876012345, 7000);

//	Arguments: Account holder name, Account number, initial balance
SavingsAccount savings("Jesus Villarroel", 1234567890, 3000);
HighInterestSavings hi_savings("Jesus Villarroel", 1234098765, 8000);

//	Arguments: Account holder name, Account number, initial balance, maturity months
CertificateOfDeposit CD("Jesus Villarroel", 1234987605, 10000, 6);

//============================================================
//					Function prototypes
//============================================================
void initMsg(void);
void MenuSelection(int);

int main()
{
	int selection;

	//	Displays a initial message on the console
	initMsg();

	//	Menu options
	cout << "\n********** BANK MANAGMENT SYSTEM MENU **********\n"
		<< "1  -> Service Charge Checking Account Deposit.\n"
		<< "2  -> Service Charge Checking Account Withdrawal.\n"
		<< "3  -> Service Charge Checking Account Write Check.\n"
		<< "4  -> Service Charge Checking Account Monthly Statement.\n"
		<< "5  -> No Service Charge Checking Account Deposit.\n"
		<< "6  -> No Service Charge Checking Account Withdrawal.\n"
		<< "7  -> No Service Charge Checking Account Write Check.\n"
		<< "8  -> No Service Charge Checking Account Monthly Statement.\n"
		<< "9  -> High Interest Checking Account Deposit.\n"
		<< "10 -> High Interest Checking Account Withdrawal.\n"
		<< "11 -> High Interest Checking Account Write Check.\n"
		<< "12 -> High Interest Checking Account Monthly Statement.\n"
		<< "13 -> Savings Account Deposit.\n"
		<< "14 -> Savings Account Withdrawal.\n"
		<< "15 -> Savings Account Monthly Statement.\n"
		<< "16 -> High Interest Savings Account Deposit.\n"
		<< "17 -> High Interest Savings Account Withdrawal.\n"
		<< "18 -> High Interest Savings Account Monthly Statement.\n"
		<< "19 -> Certificate of Deposit(CD) Withdrawal.\n"
		<< "20 -> Certificate of Deposit(CD) Monthly Statement.\n"
		<< "0  -> Exit" << "\n\n";

	do
	{		
		cout << "Please, enter your selection: ";
		cin >> selection;

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
		<< "**          WELCOME TO THE ASSIGNMENT NUMBER 5            **\n"
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
	double amount;

	switch (menu_selection)
	{
	case 1:
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		sc_checking.Deposit(amount);
		break;

	case 2:
		cout << "Enter the amount to withdraw: ";
		cin >> amount;
		sc_checking.Withdraw(amount);
		break;

	case 3:
		cout << "Enter the check amount: ";
		cin >> amount;
		sc_checking.WriteCheck(amount);
		break;

	case 4:
		sc_checking.MonthlyStatement();
		break;

	case 5:
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		no_sc_checking.Deposit(amount);
		break;

	case 6:
		cout << "Enter the amount to withdraw: ";
		cin >> amount;
		no_sc_checking.Withdraw(amount);
		break;
		
	case 7:
		cout << "Enter the check amount: ";
		cin >> amount;
		no_sc_checking.WriteCheck(amount);
		break;

	case 8:
		no_sc_checking.MonthlyStatement();
		break;

	case 9:
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		hi_checking.Deposit(amount);
		break;

	case 10:
		cout << "Enter the amount to withdraw: ";
		cin >> amount;
		hi_checking.Withdraw(amount);
		break;

	case 11:
		cout << "Enter the check amount: ";
		cin >> amount;
		hi_checking.WriteCheck(amount);
		break;

	case 12:
		hi_checking.MonthlyStatement();
		break;

	case 13:
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		savings.Deposit(amount);
		break;

	case 14:
		cout << "Enter the amount to withdraw: ";
		cin >> amount;
		savings.Withdraw(amount);
		break;

	case 15:
		savings.MonthlyStatement();
		break;

	case 16:
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		hi_savings.Deposit(amount);
		break;

	case 17:
		cout << "Enter the amount to withdraw: ";
		cin >> amount;
		hi_savings.Withdraw(amount);
		break;

	case 18:
		hi_savings.MonthlyStatement();
		break;

	case 19:
		cout << "You are withdrawing from a CD account. Any amount(> 0) withdrawn\n"
			<< "will cause to deactivate account and withdraw the entire funds.\n"
			<< "A penalty of 3% will be deducted from the total amount if the.\n"
			<< "maturity month has not been reached.\n";
		cout << "Enter any amount to withdraw: ";
		cin >> amount;
		CD.Withdraw(amount);
		break;

	case 20:
		CD.MonthlyStatement();
		break;

	default:
		cout << "No valid option was selected.\n";
		break;
	}
}
