// Yiwei He yh9vhg 9/15/2021 stack.h

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "StackNode.h"
using namespace std;

class stack {
    public: 
        stack();
        void push(int e); 
        void pop();
        int top();
        bool empty();
    private: 
        StackNode* topNode; 
};

#endif