#pragma once
#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include	"main.h"
#include	"bank_account.h"

//============================================================
//			Base class for savings accounts
//============================================================
class SavingsAccount : public BankAccount
{
protected:
	double	interest_rate;

public:
	//	 Constructors
	SavingsAccount() : BankAccount()
	{
		interest_rate = 0.012;
	}

	SavingsAccount(string name, long long int account_number, double balance) : BankAccount(name, account_number, balance)
	{
		interest_rate = 0.012;
	}

	void Withdraw(double);
	void MonthlyStatement(void);

};

//============================================================
//			High interest savings accounts
//============================================================
class HighInterestSavings : public SavingsAccount
{
protected:
	double	min_balance;

public:
	HighInterestSavings() : SavingsAccount()
	{
		min_balance = 3000.0;
		interest_rate = 0.025;
	}

	HighInterestSavings(string name, long long int account_number, double balance) : SavingsAccount(name, account_number, balance)
	{
		min_balance = 3000.0;
		interest_rate = 0.025;
	}

	void Withdraw(double);
};

#endif // !SAVINGS_ACCOUNT_H_
