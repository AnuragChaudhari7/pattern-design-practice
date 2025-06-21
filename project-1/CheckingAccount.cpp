#include "CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount(int _accountNumber, int _routingNumber, string _firstName, string _lastName) :
    Account::Account(_accountNumber, _routingNumber, _firstName, _lastName) {}

int CheckingAccount::deposit(double amount){
    if(amount < 0){
            cerr << "Deposit amount negative. Must be non-negative." << endl;
            return -1;
        }

        double newBalance = getBalance() + amount;
        setBalance(newBalance);
        getAccountDetails();
        cout << "Deposited $" << amount << endl;
        cout << "New Balance: $" << getBalance() << endl;
        return 0;
}

int CheckingAccount::withdraw(double amount){
        if(amount < 0){
            cerr << "Withdrawal amount negative. Must be non-negative." << endl;
            return -1;
        }

        double balance = getBalance();
        if(balance - amount < -100){
            cerr << "Overdraft Limit reached" << endl;
            return -2;
        }
        
        if(balance - amount < 0){
            cout << "Account overdrafted. Charging $15 fee" << endl;
            setBalance(balance - amount - 15);
            return 0;
        }

        setBalance(balance - amount);
        getAccountDetails();
        cout << "Withdrew $" << amount << endl;
        cout << "New Balance $" << getBalance() << endl;
        return 0;
}