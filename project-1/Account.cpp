#include <iostream>
#include <string.h>

#include "Account.h"
using namespace std;

/** TODO:
 * 2) use header files and cpp for each class
 * 3) test the classes (in main? assert statements?)
 * 3) user classes & identification
 */

/*Abstract Constructor for private fields*/
Account::Account(int _accountNumber, int _routingNumber, string _firstName, string _lastName) : 
    accountNumber(_accountNumber), routingNumber(_routingNumber), firstName(_firstName), lastName(_lastName), balance(0.0) {}

/*Get account details*/
void Account::getAccountDetails(){
    cout << "Account Details:" << endl;
    cout << "\tFirst Name: " << firstName << endl;
    cout << "\tLast Name: " << lastName << endl;
    cout << "\tAccount Number: " << accountNumber << endl;
    cout << "\tRouting Number: " << routingNumber << endl;
}
        

class CheckingAccount : public Account {

    /*Constructor (uses abstract class since fields are private)*/
    CheckingAccount(int _accountNumber, int _routingNumber, string _firstName, string _lastName) : 
        Account(_accountNumber, _routingNumber, _firstName, _lastName) {}
    
    /*Deposit funds*/
    int deposit(double amount) override {
        if(amount < 0){
            cerr << "Deposit amount negative. Must be non-negative." << endl;
            return -1;
        }

        double newBalance = getBalance() + amount;
        setBalance(newBalance);
        cout << "Deposited $" << amount << endl;
        cout << "New Balance: $" << getBalance() << endl;
        return 0;
    }

    /*Withdraw funds*/
    int withdraw(double amount) override {
                
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
        cout << "Withdrew $" << amount << endl;
        cout << "New Balance $" << getBalance() << endl;
        return 0;
    }

};

class SavingsAccount : public Account {

    SavingsAccount(int _accountNumber, int _routingNumber, string _firstName, string _lastName) : 
        Account(_accountNumber, _routingNumber, _firstName, _lastName) {}

    /**
     * Deposits in savings account should have 0.5% interest to deposits
     */
    int deposit(double amount) override {
        if(amount < 0){
            cerr << "Deposit amount negative. Must be non-negative." << endl;
            return -1;
        }

        double newBalance = getBalance() + (1.005 * amount);
        setBalance(newBalance);
        cout << "Deposited $" << (1.005 * amount) << endl;
        cout << "New Balance: $" << getBalance() << endl;
        return 0;
    }

    int withdraw(double amount) override {
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
        cout << "Withdrew $" << amount << endl;
        cout << "New Balance $" << getBalance() << endl;
        return 0;
    }
};