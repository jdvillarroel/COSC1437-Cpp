#pragma once
#ifndef BANK_ACCOUNT_H_
#define	BANK_ACCOUNT_H_

#include	"main.h"

//	Base class for all the accounts

class BankAccount
{
protected:
	string	name_;
	int		account_number_;
	double	balance_;

public:
	//	Default constructor
	BankAccount();

	BankAccount(string, int, double);

	//	Retrieve information from account
	string GetAccountOwnerName(void);
	int GetAccountNumber(void);
	double GetAccountBalance(void);

	//	Modify information of account
	void Deposit(double);
	void Withdraw(double);

	//	Create or set information in account
	void MonthlyStatement(void);
};












#endif // !BANK_ACCOUNT_H_
