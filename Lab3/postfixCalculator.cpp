// Yiwei He yh9vhg 9/12/2021 postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"
#include "stack.h"
using namespace std;

postfixCalculator::postfixCalculator() {
    stack equation;
}

void postfixCalculator::addition() {
    int top_val = equation.top();
    equation.pop();
    top_val = top_val + equation.top();
    equation.pop();
    equation.push(top_val);
}

void postfixCalculator::subtraction() {
    int top_val = equation.top();
    equation.pop();
    top_val = equation.top()- top_val;
    equation.pop();
    equation.push(top_val);
}

void postfixCalculator::multiplication() {
    int top_val = equation.top();
    equation.pop();
    top_val = top_val * equation.top();
    equation.pop();
    equation.push(top_val);
}

void postfixCalculator::division() {
    int top_val = equation.top();
    equation.pop();
    top_val = equation.top() / top_val;
    equation.pop();
    equation.push(top_val);
}

void postfixCalculator::negation() {
    int top_val = equation.top();
    equation.pop();
    top_val = 0 - top_val;
    equation.push(top_val);
}
