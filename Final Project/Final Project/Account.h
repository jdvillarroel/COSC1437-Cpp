#pragma once
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include	"main.h"


// Base class for the other accounts.

class BankAccount
{
protected:
	double		_balance;
	double		_annualInterestRate;
	double		_monthlyServiceCharge;
	int			_numberOfWithdrawals;
	int			_numberOfDeposits;

	double		_initBalance;

public:
	// Constructor
	BankAccount(double, double);

	// Modifier and getter functions.
	virtual void deposit(double);
	virtual void withdraw(double);
	virtual void calcInt(void);
	virtual void monthlyProc(void);

	void printStatistics(void);

	//double getBalance(void);
	//double getInitBalance(void);
	//double getMonthlyServiceCharge(void);
	//int getNumberOfDeposits(void);
	//int getNumberOfWithdrawals(void);
};


#endif // !ACCOUNT_H_
