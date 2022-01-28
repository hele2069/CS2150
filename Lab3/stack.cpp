// Yiwei He yh9vhg 9/15/2021 stack.cpp

#include <iostream>
#include <string>
#include "stack.h"
#include "StackNode.h"
using namespace std;

stack::stack() {
    topNode = NULL; 
}

void stack::push(int e) {
    if (topNode ==  NULL) {
        topNode = new StackNode();
        topNode->value = e;
    }
    else {
        StackNode* new_topNode = new StackNode();
        new_topNode->value = e;
        new_topNode->next = topNode;
        topNode = new_topNode;
    }
}

void stack::pop() {
    if (topNode != NULL) {
        StackNode* new_topNode = new StackNode();
        new_topNode = topNode->next;
        delete topNode;
        topNode = new_topNode;
    }
}

int stack::top() {
    return topNode->value;
}

bool stack::empty() {
    return topNode == NULL; 
}