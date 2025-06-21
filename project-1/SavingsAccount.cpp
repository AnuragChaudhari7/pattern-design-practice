#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(int _accountNumber, int _routingNumber, string _firstName, string _lastName) :
    Account(_accountNumber, _routingNumber, _firstName, _lastName) {}

int SavingsAccount::deposit(double amount) {
    if(amount < 0){
            cerr << "Deposit amount negative. Must be non-negative." << endl;
            return -1;
        }

        double newBalance = getBalance() + (1.005 * amount);
        setBalance(newBalance);
        getAccountDetails();
        cout << "Deposited $" << (1.005 * amount) << endl;
        cout << "New Balance: $" << getBalance() << endl;
        return 0;
}

int SavingsAccount::withdraw(double amount) {
    if(amount < 0){
            cerr << "Withdrawal amount negative. Must be non-negative." << endl;
            return -1;
        }
        
        double balance = getBalance();
        if(balance - amount < 0){
            cerr << "Insufficient Balance" << endl;
            return -1;
        }

        setBalance(balance - amount);
        getAccountDetails();
        cout << "Withdrew $" << amount << endl;
        cout << "New Balance $" << getBalance() << endl;
        return 0;
}