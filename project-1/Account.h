#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
    private:
        int accountNumber;
        int routingNumber;
        string firstName;
        string lastName;
        double balance;

    public:
        /*Abstract Constructor for private fields*/
        Account(int _accountNumber, int _routingNumber, string _firstName, string _lastName);

        /*Deposit Virtual Method*/
        virtual int deposit(double amount) = 0;

        /*Withdraw Virtual Method
         *  0: successful 
         * -1: failed
         */
        virtual int withdraw(double amount) = 0;

        /*Getters*/
        int getAccountNumber(){return accountNumber;}

        int getRoutingNumber(){return routingNumber;}

        string getFirstName(){return firstName;}

        string getLastName(){return lastName;}
        
        double getBalance(){return balance;}
        
        /*Setters*/
        void setBalance(double newBalance){balance = newBalance;}

        /*Get account details
        * N.B. too complex to be in header file (unlike one liners above)*/
        void getAccountDetails() const;
        
};

#endif