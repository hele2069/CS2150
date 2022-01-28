// Yiwei He yh9vhg 9/5/2021 StackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>
using namespace std;

class StackNode {
public:
    StackNode();         // Constructor
    int value;          // The value of the node!
    StackNode* next;     // The next ListNode in the List
};

#endif
