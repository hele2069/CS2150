// Yiwei He yh9vhg 9/12/2021 postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

class postfixCalculator {
    public:
        postfixCalculator();     // default constructor
        void addition();         // addition 
        void subtraction();      // subtraction
        void multiplication();   // multiplication
        void division();         // division
        void negation();         // negation 
        stack equation;
};

#endif