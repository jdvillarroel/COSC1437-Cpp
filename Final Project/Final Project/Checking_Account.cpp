#include	"Checking_Account.h"


/// <summary>
/// Perform withdrawal for checking account. If not enough funds are available
/// a service charge is deducted.
/// </summary>
/// <param name="amount"></param>
void CheckingAccount::withdraw(double amount)
{
	// Verify if account has enough funds to withdraw. If not, a service
	// charge of $15 will be deducted from the balance and the operation
	// won't be performed.
	if ((_balance - amount) < 0)
	{
		BankAccount::withdraw(_serviceCharge);

		cout << "Not enough funds. Service charge applied." << endl;
	}
	else
	{
		BankAccount::withdraw(amount);

		cout << "Withdrawal successful." << endl;
	}
		
}


void CheckingAccount::monthlyProc(void)
{
	// Updates the amount in fees to be deducted from the balance.
	_monthlyServiceCharge = _monthlyFee + (_feePerWithdrawal * _numberOfWithdrawals);

	BankAccount::monthlyProc();
}
