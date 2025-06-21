#include <iostream>
#include <string>

//N.B. bad practice to include .cpp files, use .h files instead
#include "Account.h" //N.B. we don't need this line since following already include it later (or the next 2 dont include Account.h again)
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

int main(){
    CheckingAccount chk = CheckingAccount(123456, 112233, "Rob", "Banks");
    SavingsAccount sav = SavingsAccount(987654, 998877, "Catch", "Rob");
    chk.deposit(100);
    sav.deposit(1000);
    return 0;
}