// Yiwei He yh9vhg 9/2/2021 bankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;

// class
class bankAccount {
    public: 
        bankAccount(); // default constructor 
        bankAccount(double amount); // constructor with initial balance
        ~bankAccount(); // destructor 

        // prototypes
        double withdraw(double amount); // withdraw function
        double deposit(double amount); // deposit function
        double getBalance(); // getter 
    
    private: 
        double balance; // amount of money in account 
};

#endif