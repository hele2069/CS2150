// Yiwei He yh9vhg 9/5/2021 List.cpp

#include <iostream>
#include "ListItr.h"
#include "ListNode.h"
#include "List.h"
using namespace std;

// default constructor 
List::List() {
    head = new ListNode();
    tail = new ListNode();
    head -> next = tail;
    tail -> previous = head;
    count = 0;
}

// copy constructor
List::List(const List& source) {
    head = new ListNode();
    tail = new ListNode();
    head -> next = tail;
    tail -> previous = head;
    count = 0;

    // Make a deep copy of the list
    ListItr iter(source.head -> next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// destructor
List::~List() {
    makeEmpty();
    delete head;
    delete tail;
}

// copy assignment operator
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// methods
bool List::isEmpty() const {
    return count == 0;
}

void List::makeEmpty() {
	while(!isEmpty()) { 
		remove(last().retrieve());
	}
}

ListItr List::first() {
    ListItr itr_object(head -> next);
    return itr_object; 
}

ListItr List::last() {
    ListItr itr_object(tail -> previous);
    return itr_object;
}

void List::insertAfter(int x, ListItr position) {
    ListNode * temp = new ListNode();
    temp -> value = x;
    temp -> next = position.current -> next;
    temp -> previous = position.current;
    position.current -> next -> previous = temp; 
    position.current -> next = temp; 
    count++;
}

void List::insertBefore(int x, ListItr position) {
    ListNode * temp = new ListNode();
    temp -> value = x;
    temp -> next = position.current;
    temp -> previous = position.current -> previous;
    position.current -> previous -> next = temp;
    position.current -> previous = temp; 
    count++;
}

void List::insertAtTail(int x) { 
    ListNode * temp = new ListNode();
    temp -> value = x;
    temp -> next = tail;
    temp -> previous = tail -> previous;
    tail -> previous -> next = temp;
    tail -> previous = temp;
    count++;
}

ListItr List::find(int x) {
    ListItr itr_object = first();
    while(!itr_object.isPastEnd()) {
        if(itr_object.retrieve() == x){
            return itr_object;
        }
        itr_object.moveForward();
    }
}

void List::remove(int x) {
    ListItr temp = find(x);
	if(!temp.isPastEnd()){
		temp.current -> previous -> next = temp.current-> next;
		temp.current -> next -> previous = temp.current-> previous;
		delete temp.current;
		count --;
	} 
}

int List::size() const {
    return count; 
}

void printList(List& source, bool forward) {
    if (forward) {
        ListItr temp = source.first();
        while (!temp.isPastEnd()) {
            cout << temp.retrieve() << " ";
            temp.moveForward();
        }
        cout << "\n\n" << endl;
    }
    if (!forward) {
        ListItr temp = source.last();
        while (!temp.isPastBeginning()) {
            cout << temp.retrieve() << " ";
            temp.moveBackward();
        }
        cout << "\n\n" << endl;
    }
}