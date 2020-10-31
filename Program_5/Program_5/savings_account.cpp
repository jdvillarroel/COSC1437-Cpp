#include	"savings_account.h"


//============================================================
//			Functions for savings account
//============================================================

/// <summary>
/// If the account complies with the minimum requirements, the operation can be done.
/// The base class function is called.
/// </summary>
/// <param name="withdraw_amount"></param>
void SavingsAccount::Withdraw(double withdraw_amount)
{
	//	Only if account is active can proceed.
	if (!is_active)
	{
		cout << "Account is not active. No opeartion is possible.\n";
		return;
	}

	//	Only if amount is valid can proceed.
	if (withdraw_amount <= 0)
	{
		cout << "Amount must be greater than zero.\n";
		return;
	}

	//	Since no minimum balance is required, the only condition is that the
	//	the account has enough funds to do the operation.
	if ((balance_ - withdraw_amount) >= 0)
	{
		BankAccount::Withdraw(withdraw_amount);
	}
	else
	{
		cout << "Withdrawal not possible. Not enough funds available.\n";
		cout << "Account Balance: $" << balance_ << "\n.";
	}
}

/// <summary>
/// Prints the basic and the related information according the account type.
/// </summary>
/// <param name=""></param>
void SavingsAccount::MonthlyStatement(void)
{
	//	Print the basic account information
	BankAccount::MonthlyStatement();

	//	Print additional info related only to this kind of account.
	cout << fixed << showpoint << setprecision(2);
	cout << "Annual interest rate: " << (interest_rate * 100) << "%\n";

	//	Deposit the interests gained during the current month.
	this->Deposit(balance_ * (interest_rate / 12));
	cout << "Final balance: $" << balance_ << "\n";
}

//============================================================
//		Functions for high interest savings account
//============================================================

/// <summary>
/// If the account complies with the minimum requirements, the operation can be done.
/// The base class function is called.
/// </summary>
/// <param name="withdraw_amount"></param>
void HighInterestSavings::Withdraw(double withdraw_amount)
{
	//	Only if account is active can proceed.
	if (!is_active)
	{
		cout << "Account is not active. No opeartion is possible.\n";
		return;
	}

	//	Only if amount is valid can proceed.
	if (withdraw_amount <= 0)
	{
		cout << "Amount must be greater than zero.\n";
		return;
	}

	//	As the account requires a minimum balance, no withdrawal can be done if
	//	the balance can drop under the minimum.
	if ((balance_ - withdraw_amount) >= min_balance)
	{
		BankAccount::Withdraw(withdraw_amount);
	}
	else
	{
		cout << "Withdrawal not possible. Not enough funds available.\n";
		cout << "A minimum balance of $" << min_balance << " is required.\n";
		cout << "Account Balance: $" << balance_ << "\n.";
	}
}