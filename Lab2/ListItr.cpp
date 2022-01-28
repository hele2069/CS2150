// Yiwei He yh9vhg 9/5/2021 ListItr.cpp

#include <iostream>
#include "ListItr.h"
#include "ListNode.h"
#include "List.h"
using namespace std;

// default constructor
ListItr::ListItr() {
    current = new ListNode();
}

// constructor with parameters 
ListItr::ListItr(ListNode* theNode) {
    current = theNode;
}

// methods
bool ListItr::isPastEnd() const {
    return current -> next == NULL;
}

bool ListItr::isPastBeginning() const {
    return current -> previous == NULL;
}

void ListItr::moveForward() {
    if (!isPastEnd()) {
        current = current -> next; 
    }
}

void ListItr::moveBackward() {
    if (!isPastBeginning()) {
        current = current -> previous;
    }
}

int ListItr::retrieve() const {
    return current -> value; 
}