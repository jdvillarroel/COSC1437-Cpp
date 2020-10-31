#include	"savings_account.h"


//============================================================
//			Functions for savings account
//============================================================

void SavingsAccount::Withdraw(double withdraw_amount)
{
	if (!is_active)
	{
		cout << "Account is not active. No opeartion is possible.\n";
		return;
	}

	if (withdraw_amount <= 0)
	{
		cout << "Amount must be greater than zero.\n";
		return;
	}

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

void SavingsAccount::MonthlyStatement(void)
{
	BankAccount::MonthlyStatement();
	cout << fixed << showpoint << setprecision(2);
	cout << "Annual interest rate: " << (interest_rate * 100) << "%\n";
	this->Deposit(balance_ * (interest_rate / 12));
	cout << "Final balance: $" << balance_ << "\n";
}

//============================================================
//		Functions for high interest savings account
//============================================================

void HighInterestSavings::Withdraw(double withdraw_amount)
{
	if (!is_active)
	{
		cout << "Account is not active. No opeartion is possible.\n";
		return;
	}

	if (withdraw_amount <= 0)
	{
		cout << "Amount must be greater than zero.\n";
		return;
	}

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