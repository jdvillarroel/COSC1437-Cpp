#pragma once
#ifndef BANK_ACCOUNT_H_
#define	BANK_ACCOUNT_H_

#include	"main.h"

//	Base class for all the accounts

class BankAccount
{
protected:
	string			name_;
	long long int	account_number_;
	double			balance_;
	bool			is_active;

public:
	//	Default constructor
	BankAccount();

	BankAccount(string, long long int, double);

	//	Retrieve information from account
	string GetAccountOwnerName(void);
	double GetAccountBalance(void);
	long long int GetAccountNumber(void);

	//	Modify information of account
	virtual void Deposit(double);
	virtual void Withdraw(double);

	//	Create or set information in account
	virtual void MonthlyStatement(void);

	//	Not implemented in main program but they can be used for further
	//	control over the bank accounts.
	void SetAccountOwnerName(string);
	void SetAccountNumber(long long int);
	void SetAccountBalance(double);
};

#endif // !BANK_ACCOUNT_H_
