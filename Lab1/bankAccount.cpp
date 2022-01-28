// Yiwei He yh9vhg 9/2/2021 bankAccount.cpp
#include <iostream>
#include <string>
#include "bankAccount.h"
using namespace std;

// default construcor 
bankAccount::bankAccount() {
    balance = 0;
}

// constructor with initial balance
bankAccount::bankAccount(double amount) {
    balance = amount; 
}

// destructor
bankAccount::~bankAccount() {

}

// regular functions 
double bankAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
    return balance; 
}

double bankAccount::deposit(double amount) {
    balance += amount;
    return balance;
}

double bankAccount::getBalance() {
    return balance;
}

