#include	"bank_account.h"

/// <summary>
/// Default variables values.
/// </summary>
BankAccount::BankAccount()
{
	name_ = "Sample Name";
	account_number_ = 1234567890;
	balance_ = 0.0;
}

/// <summary>
/// Initialize the variables with the arguments passed
/// </summary>
/// <param name="name"></param>
/// <param name="account_number"></param>
/// <param name="balance"></param>
BankAccount::BankAccount(string name, long long int account_number, double balance)
{
	name_ = name;
	account_number_ = account_number;
	balance_ = balance;
}

/// <summary>
/// Set the customer name in case not passed when declaring the instance.
/// </summary>
/// <param name="name"></param>
void BankAccount::SetAccountOwnerName(string name)
{
	name_ = name;
}

/// <summary>
/// Set the account number in case not passed when declaring the instance.
/// </summary>
/// <param name="account_number"></param>
void BankAccount::SetAccountNumber(long long int account_number)
{
	account_number_ = account_number;
}

/// <summary>
/// Set the balance in case not passed when declaring the instance.
/// </summary>
/// <param name="balance"></param>
void BankAccount::SetAccountBalance(double balance)
{
	balance_ = balance;
}

/// <summary>
/// Retrieve the account owner's name.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
string BankAccount::GetAccountOwnerName(void)
{
	return name_;
}

/// <summary>
/// Retrieve the current account balance
/// </summary>
/// <param name=""></param>
/// <returns></returns>
double BankAccount::GetAccountBalance(void)
{
	return balance_;
}

/// <summary>
/// Retrieve the customer account number.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
long long int BankAccount::GetAccountNumber(void)
{
	return account_number_;
}

/// <summary>
/// Set a deposit to the bank account.
/// </summary>
/// <param name="deposit"></param>
void BankAccount::Deposit(double deposit_amount)
{
	balance_ += deposit_amount;
}

/// <summary>
/// Set a withdraw to the bank account.
/// </summary>
/// <param name="withdraw"></param>
void BankAccount::Withdraw(double withdraw_amount)
{
	balance_ -= withdraw_amount;
}

void BankAccount::MonthlyStatement(void)
{
	cout << "********** MONTHLY STATEMENT **********\n\n";

	cout << "Customer name: " << name_ << "\n";
	cout << "Account Number: #" << account_number_ << "\n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Account Balance: $" << balance_ << "\n\n";
}