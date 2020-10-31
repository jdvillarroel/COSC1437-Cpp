#include	"certificate_of_deposit.h"

//============================================================
//			Functions for certificate of deposit
//============================================================

/// <summary>
/// As this is a certificate of deposit account, withdrawals are not allowed
/// unless the maturity month has been reached. If a withdrawal is made, a penalty
/// amount will be deducted from the total balance and the entire amount will be
/// withdrawn. In addition, the account is deactivated.
/// </summary>
/// <param name="withdraw_amount"></param>
void CertificateOfDeposit::Withdraw(double withdraw_amount)
{
	double penalty_amount;

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

	//	If maturity month is reached the withdrawal is done without a panalty.
	if (maturity_months - current_month == 0)
	{
		cout << "Amount withdrawn: $" << balance_ << "\n";
		BankAccount::Withdraw(balance_);
		is_active = false;
	}
	else
	{
		//	Calculate penalty rate
		penalty_amount = balance_ * penalty_rate;
			
		//	Display the amount of the penalty and what is left to withdraw.
		cout << fixed << showpoint << setprecision(2);
		cout << "Penalty amount: $" << penalty_amount << "\n";
		cout << "Amount withdrawn: $" << (balance_ - penalty_amount) << "\n";

		// Withdraw whatever is left in the account and mark it inactive.
		BankAccount::Withdraw(balance_ - penalty_amount);
		is_active = false;
	}
}

/// <summary>
/// Statistic about the account by month. Everytime is called, it is simulated that a month
/// has elapse, so the interest is added to the balance and the current month is incremented.
/// When maturity month is reached no more interest is added. Amounth can be withdrawn with
/// no penalty.
/// </summary>
/// <param name=""></param>
void CertificateOfDeposit::MonthlyStatement(void)
{
	//	Everytime a monthly statement is printed, it simulates a month has passed.
	//	Just to demonstrate the functionality of the program.
	if (current_month < maturity_months)
	{
		current_month++;

		//	Considering the CD is compounded monthly we add the interest gained during the month.
		double monthly_amount = balance_ * (interest_rate / 12);
		this->Deposit(monthly_amount);
	}

	BankAccount::MonthlyStatement();
	cout << fixed << showpoint << setprecision(2);
	cout << "Annual interest rate: " << (interest_rate * 100) << "%\n";
	cout << "Current month: " << current_month << "\n";
	cout << "Maturity months: " << maturity_months << "\n";
}

