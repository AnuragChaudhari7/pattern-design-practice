#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <iostream>
#include <string>

#include "Account.h"
using namespace std;

class CheckingAccount : public Account {
    public:
        /*Constructor (uses abstract class since fields are private)*/
        CheckingAccount(int _accountNumber, int _routingNumber, string _firstName, string _lastName);
    
        /*Deposit funds*/
        int deposit(double amount) override;

        /*Withdraw funds*/
        int withdraw(double amount) override;
};

#endif