#include	"Savings_Account.h"


/// <summary>
/// Perform withdrawal on savings account. It can proceed only if account is active.
/// If balance falls below $25, the account is marked as not active.
/// </summary>
/// <param name="amount"></param>
void SavingsAccount::withdraw(double amount)
{
	// If account is active, it can proceed.
	if (_status == ACTIVE)
	{
		BankAccount::withdraw(amount);

		cout << "Withdrawal successful." << endl;

		// Verifies balance to update status.
		if (_balance < _minimumBalance)
		{
			_status = NOT_ACTIVE;

			cout << "Acount balance below minimum. Account is now inactive" << endl;
		}
	}
	else
	{
		cout << "Account is not active. Operation rejected." << endl;
	}
}

/// <summary>
/// Performs deposit into savings account, and update status in case the account
/// is not active and the amount of the deposit brings the account above the minimum balance.
/// </summary>
/// <param name="amount"></param>
void SavingsAccount::deposit(double amount)
{
	// Update status of the account if not active and deposit amount brings
	// balance above $25.
	if (_status == NOT_ACTIVE && (_balance + amount) > _minimumBalance)
	{
		_status = ACTIVE;

		cout << "Account is now active." << endl;
	}

	// Performs deposit.
	BankAccount::deposit(amount);

	cout << "Deposit successful." << endl;
}


void SavingsAccount::monthlyProc(void)
{
	if (_numberOfWithdrawals > 4)
	{
		// Charge $1 per transaction above 4.
		_monthlyServiceCharge = (static_cast<double>(_numberOfWithdrawals) - 4) * _serviceChargeFee;
	}

	BankAccount::monthlyProc();

	// Update status in case balance falls below $25;
	if (_balance < _minimumBalance)
	{
		_status = NOT_ACTIVE;
	}
}
