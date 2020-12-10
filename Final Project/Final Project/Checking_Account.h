#pragma once

#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_

#include	"main.h"
#include	"Account.h"


// Create a checking account class derived from the base class(Account).
class CheckingAccount : public BankAccount
{
protected:
	double		_monthlyFee;
	double		_feePerWithdrawal;
	double		_serviceCharge;


public:
	// Constructor
	CheckingAccount(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate)
	{
		_monthlyFee = 5;
		_feePerWithdrawal = 0.1;
		_serviceCharge = 15;
	}

	void withdraw(double);
	void monthlyProc(void);
};



#endif // !CHECKING_ACCOUNT_H_

