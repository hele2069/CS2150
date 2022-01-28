// Yiwei He yh9vhg 9/12/2021 testPostfixCalc.cpp

#include <iostream>
#include "stack.h"
#include <string>
#include "postfixCalculator.h"
using namespace std;

int main() {
    postfixCalculator calc;
    string response; 
    while (cin >> response) {
        if (response.compare("+") == 0) {
            calc.addition();
        }
        else if (response.compare("-") == 0) {
            calc.subtraction();
        }
        else if (response.compare("*") == 0) {
            calc.multiplication();
        }
        else if (response.compare("/") == 0) {
            calc.division();
        }
        else if (response.compare("~") == 0) {
            calc.negation();
        }
        else {
            calc.equation.push(stoi(response));
        }
    }
    cout << calc.equation.top() << endl; 
    return 0;
}   