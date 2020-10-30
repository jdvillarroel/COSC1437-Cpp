#pragma once
#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_

#include	"main.h"
#include	"bank_account.h"

class CheckingAccount : public BankAccount
{
protected:
	int		checks_emitted;

public:
	//	Default constructor
	CheckingAccount() : BankAccount()
	{
		checks_emitted = 0;
	}

	//	Second constructor with arguments
	CheckingAccount(string name, long long int account_number, double balance):BankAccount(name, account_number, balance)
	{
		checks_emitted = 0;
	}

	virtual void	WriteCheck(double);

};

#endif // !CHECKING_ACCOUNT_H_
