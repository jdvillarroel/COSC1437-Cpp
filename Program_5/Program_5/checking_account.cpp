#include	"checking_account.h"
//============================================================
//	Function definition for checking accounts base class
//============================================================

void CheckingAccount::WriteCheck(double check_amount)
{
	BankAccount::Withdraw(check_amount);
	checks_written++;
}

void CheckingAccount::MonthlyStatement(void)
{
	BankAccount::MonthlyStatement();
	cout << "Checks Written: " << checks_written << "\n";
}


//============================================================
//	Function definition for service charge checking accounts
//============================================================

void ServiceChargeChecking::WriteCheck(double check_amount)
{
	//	Only if account is active can proceed.
	if (!is_active)
	{
		cout << "Account is not active. No operation possible.\n";
		return;
	}

	//	Only when number of checks emiited are less than maximum allowed and customer has
	//	enough balance the check can be emitted.
	if ((checks_written < MAX_NUM_CHECKS) && (balance_ - check_amount) >= 0)
	{
		CheckingAccount::WriteCheck(check_amount);
	}
	else
	{
		cout << "Check cannot be written. Not enough funds or checks limit reached.\n";
		cout << "Checks written: " << checks_written << " of " << MAX_NUM_CHECKS << "\n";
		cout << fixed << showpoint << setprecision(2);
		cout << "Account Balance: $" << balance_ << "\n";
	}
}

void ServiceChargeChecking::Withdraw(double withdraw_amount)
{
	//	Only if account is active can proceed.
	if (!is_active)
	{
		cout << "Account is not active. No operation possible\n";
		return;
	}

	if (withdraw_amount <= 0)
	{
		cout << "Amount must be greater than zero.\n";
		return;
	}

	//	Withdrawals are allowed when enough funds are available. Only the service charge
	//	can be withdrawed from the account leaving it in negative balance, but the account
	//	is marked as inactive.
	if ((balance_ - withdraw_amount) >= 0)
	{
		CheckingAccount::Withdraw(withdraw_amount);
	}
	else if (withdraw_amount <= SERVICE_CHARGE)
	{
		CheckingAccount::Withdraw(withdraw_amount);
		is_active = false;
	}
	else
	{
		cout << "Withdrawal not possible.\n";
		cout << "You attemped to withdraw an amount higher than your current balance.\n";
		cout << "Account Balance: $" << balance_ << "\n.";
	}
}

void ServiceChargeChecking::MonthlyStatement(void)
{
	//	Specific data only for this type of account is added to the monthly statement.
	CheckingAccount::MonthlyStatement();
	cout << fixed << showpoint << setprecision(2);
	cout << "Service Charge: $" << SERVICE_CHARGE << "\n";
	CheckingAccount::Withdraw(SERVICE_CHARGE);
	cout << "Final Balance: $" << (balance_) << "\n";
	
}

//============================================================
//	Function definition for no service charge checking accounts
//============================================================

void NoServiceChargeChecking::WriteCheck(double check_amount)
{
	//	Only if account is active can proceed.
	if (!is_active)
	{
		cout << "Account is not active.\n";
		return;
	}

	//	Only when customer has enough balance the check can be emitted.
	if ((balance_ - check_amount) >= min_balance)
	{
		CheckingAccount::WriteCheck(check_amount);
	}
	else
	{
		cout << "Check cannot be written. Not enough funds.\n";
		cout << "A minimum balance of $" << min_balance << " is required.\n";
		cout << "Checks written: " << checks_written << "\n";
		cout << fixed << showpoint << setprecision(2);		
		cout << "Account Balance: $" << balance_ << "\n";
	}
}

void NoServiceChargeChecking::Withdraw(double withdraw_amount)
{
	//	Only if account is active can proceed.
	if (!is_active)
	{
		cout << "Account is not active.\n";
		return;
	}

	if (withdraw_amount <= 0)
	{
		cout << "Amount must be greater than zero.\n";
		return;
	}

	//	Withdrawals are allowed when enough funds are available. The minimum balance allowed
	//	in the account is min_balance
	if ((balance_ - withdraw_amount) >= min_balance)
	{
		CheckingAccount::Withdraw(withdraw_amount);
	}
	else
	{
		cout << "Withdrawal not possible.\n";
		cout << "A minimum balance of $" << min_balance << " is required.\n";
		cout << "Account Balance: $" << balance_ << "\n.";
	}
}

void NoServiceChargeChecking::MonthlyStatement(void)
{
	//	Specific data only for this type of account is added to the monthly statement.
	CheckingAccount::MonthlyStatement();
	cout << fixed << showpoint << setprecision(2);
	cout << "Annual interest rate: " << (interest_rate * 100) << "%\n";
	this->Deposit(balance_ * (interest_rate)/12);
	cout << "Final Balance: $" << (balance_) << "\n";
}