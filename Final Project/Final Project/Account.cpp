#include	"Account.h"






/// <summary>
/// Initialize the variables when the class type object is created;
/// </summary>
/// <param name="balance"></param>
/// <param name="annualInterestRate"></param>
BankAccount::BankAccount(double balance, double annualInterestRate)
{
	_balance = balance;
	_annualInterestRate = annualInterestRate;

	_monthlyServiceCharge = 0.0;
	_numberOfDeposits = 0;
	_numberOfWithdrawals = 0;

	_initBalance = _balance;
}

/// <summary>
/// Make a deposit into the account, and keep track of the number
/// of deposits made.
/// </summary>
/// <param name="amount"></param>
void BankAccount::deposit(double amount)
{
	_balance += amount;
	_numberOfDeposits++;
}

/// <summary>
/// Withdraw a specific amount from the account, and keep track of the 
/// number of widrawals made.
/// </summary>
/// <param name="amount"></param>
void BankAccount::withdraw(double amount)
{
	_balance -= amount;
	_numberOfWithdrawals++;
}

/// <summary>
/// Claculate the interest generated monthly and update the account balance.
/// </summary>
/// <param name=""></param>
void BankAccount::calcInt(void)
{
	double monthlyInterest;

	// Interest earned monthly.
	monthlyInterest = _balance * (_annualInterestRate / 12);

	// Update balance with the interest generated.
	_balance += monthlyInterest;
}

void BankAccount::monthlyProc(void)
{
	// Updates the account by charging it with the monthly fees.
	_balance -= _monthlyServiceCharge;

	// Call function to calculate interest earned.
	calcInt();

	// Print Statistics.
	printStatistics();

	// Resets account statistics.
	_numberOfDeposits = 0;
	_numberOfWithdrawals = 0;
	_monthlyServiceCharge = 0.0;

	// Update initial balance for next cycle
	_initBalance = _balance;
}

void BankAccount::printStatistics(void)
{

	// Format the floating point numbers.
	cout << fixed << showpoint << setprecision(2);

	cout << "// ========================================================" << endl;
	cout << "// Initial balance: $" << _initBalance << endl;
	cout << "// Deposits: " << _numberOfDeposits << endl;
	cout << "// Withdrawals: " << _numberOfWithdrawals << endl;	
	cout << "// Service Charges: $" << _monthlyServiceCharge << endl;
	cout << "// Ending Balance: $" << _balance << endl;
	cout << "// ========================================================" << endl;

}