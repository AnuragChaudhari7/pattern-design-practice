#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>
#include <string>

#include "Account.h"
using namespace std;

class SavingsAccount : public Account{
    public:
        /*Constructor*/
        SavingsAccount(int _accountNumber, int _routingNumber, string _firstName, string _lastName);

        /*Deposit funds*/
        int deposit(double amount) override;

        /*Withdraw funds*/
        int withdraw(double amount) override;
};

#endif