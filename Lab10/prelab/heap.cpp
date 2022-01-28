// Yiwei He yh9vhg heap.cpp 11/20/2021

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// default constructor
heap::heap(){
    heap_size = 0;
    huffHeap.push_back(0);
}

heap::heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    huffHeap = vec;
    huffHeap.push_back(huffHeap[0]);
    huffHeap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    huffHeap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* x = huffHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->num < huffHeap[hole/2]->num); hole /= 2) {
        huffHeap[hole] = huffHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = x;
}

void heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    huffHeap[1] = huffHeap[heap_size--];
    // make sure the vector knows that there is one less element
    huffHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* x = huffHeap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (huffHeap[child+1]->getNum() < huffHeap[child]->getNum())) {
            child++;
        }
        // if the child is greater than the node...
        if (x->getNum() > huffHeap[child]->getNum()) {
            huffHeap[hole] = huffHeap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = x;
}

huffmanNode* heap::findMin() {
    return huffHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    huffHeap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

huffmanNode* heap::get(int x){
    return huffHeap[x];
}

void heap::print() {
    cout << "(" << huffHeap[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << huffHeap[i] << " ";
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
