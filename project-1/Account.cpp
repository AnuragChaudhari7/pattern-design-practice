#include <iostream>
#include <string.h>

#include "Account.h"
using namespace std;

/** TODO:
 * 2) use header files and cpp for each class
 * 3) test the classes (in main? assert statements?)
 * 3) user classes & identification
 * 4) references?
 * 5) method description formatting? Like in python?
 */

/*Abstract Constructor for private fields*/
Account::Account(int _accountNumber, int _routingNumber, string _firstName, string _lastName) : 
    accountNumber(_accountNumber), routingNumber(_routingNumber), firstName(_firstName), lastName(_lastName), balance(0.0) {}

/*Get account details*/
void Account::getAccountDetails() const{
    cout << "Account Details:" << endl;
    cout << "\tFirst Name: " << firstName << endl;
    cout << "\tLast Name: " << lastName << endl;
    cout << "\tAccount Number: " << accountNumber << endl;
    cout << "\tRouting Number: " << routingNumber << endl;
}