#include	"checking_account.h"

void CheckingAccount::WriteCheck(double check_amount)
{
	BankAccount::Withdraw(check_amount);
	checks_emitted++;
}



