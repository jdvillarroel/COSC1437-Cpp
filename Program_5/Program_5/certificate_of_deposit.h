#pragma once
#ifndef CERTIFICATE_OF_DEPOSIT_H_
#define	CERTIFICATE_OF_DEPOSIT_H_

#include	"main.h"
#include	"bank_account.h"

//============================================================
//			Base class for savings accounts
//============================================================

class CertificateOfDeposit : public BankAccount
{
protected:
	double	interest_rate;
	int		maturity_months;
	int		current_month;
	double	penalty_rate;

public:
	//	Constructors
	CertificateOfDeposit() : BankAccount()
	{
		interest_rate = 0.025;
		maturity_months = 6;
		current_month = 0;
		penalty_rate = 0.03;
	}

	CertificateOfDeposit(string name, long long int account_number, double balance, int months) : BankAccount(name, account_number, balance)
	{
		interest_rate = 0.025;
		maturity_months = months;
		current_month = 0;
		penalty_rate = 0.03;
	}

	void Withdraw(double);
	void MonthlyStatement(void);

};


#endif // !CERTIFICATE_OF_DEPOSIT_H_
