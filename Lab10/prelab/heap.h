// Yiwei He yh9vhg heap.h 11/20/2021

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffmanNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffmanNode*> vec);
    ~heap();

    void insert(huffmanNode* x);
    huffmanNode* findMin();
    void deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    huffmanNode* get(int x);

private:
    vector<huffmanNode*> huffHeap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
