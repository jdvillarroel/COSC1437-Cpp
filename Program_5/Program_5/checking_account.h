#pragma once
#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_

#include	"main.h"
#include	"bank_account.h"

//============================================================
//			Base class for checking accounts
//============================================================

class CheckingAccount : public BankAccount
{
protected:
	int		checks_written;

public:
	//	Default constructor
	CheckingAccount() : BankAccount()
	{
		checks_written = 0;
	}

	//	Second constructor with arguments
	CheckingAccount(string name, long long int account_number, double balance) : BankAccount(name, account_number, balance)
	{
		checks_written = 0;
	}

	virtual void WriteCheck(double);
	void MonthlyStatement(void);
};

//============================================================
//			Service charge checking account
//============================================================

class ServiceChargeChecking : public CheckingAccount
{
private:
	const int		MAX_NUM_CHECKS = 5;
	const double	SERVICE_CHARGE = 10.00;

protected:

public:
	//	Constructors
	ServiceChargeChecking() : CheckingAccount()
	{}

	ServiceChargeChecking(string name, long long int account_number, double balance) : CheckingAccount(name, account_number, balance)
	{}

	void WriteCheck(double);
	void Withdraw(double);
	void MonthlyStatement(void);

};

//============================================================
//			No Service charge checking account
//============================================================

class NoServiceChargeChecking : public CheckingAccount
{
protected:
	double min_balance;
	double interest_rate;

public:
	//	Constructors
	NoServiceChargeChecking() : CheckingAccount()
	{
		min_balance = 1000.0;
		interest_rate = 0.01;
	}

	NoServiceChargeChecking(string name, long long int account_number, double balance) : CheckingAccount(name, account_number, balance)
	{
		min_balance = 1000.0;
		interest_rate = 0.01;
	}

	void WriteCheck(double);
	void Withdraw(double);
	void MonthlyStatement(void);
};

//============================================================
//			High Interest checking account
//============================================================
class HighInterestChecking : public NoServiceChargeChecking
{

public:
	//	Constructors
	HighInterestChecking() : NoServiceChargeChecking()
	{
		min_balance = 3000;
		interest_rate = 0.05;
	}

	HighInterestChecking(string name, long long int account_number, double balance) : NoServiceChargeChecking(name, account_number, balance)
	{
		min_balance = 3000;
		interest_rate = 0.05;
	}
};

#endif // !CHECKING_ACCOUNT_H_
