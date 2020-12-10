#pragma once

#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include	"main.h"
#include	"Account.h"


// Create a savings account class derived from the base class(Account).
class SavingsAccount : public BankAccount {
protected:
	bool		_status;
	double		_serviceChargeFee;
	double		_minimumBalance;

public:
	// Constructor
	SavingsAccount(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate)
	{
		// If account is created with a balance greater than zero (0), the account will be active.
		// Otherwise it will remain inactive.
		(balance > 0) ? _status = ACTIVE : _status = NOT_ACTIVE;

		// Initialize service charge fee per withdrawal above 4.
		_serviceChargeFee = 1.0;

		_minimumBalance = 25.0;
	}


	void withdraw(double);
	void deposit(double);
	void monthlyProc(void);

};



#endif // !SAVINGS_ACCOUNT_H_

