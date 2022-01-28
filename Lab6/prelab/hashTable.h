//Yiwei He yh9vhg 10/17/2021 hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <string>
using namespace std;

class hashTable{
    public:
        hashTable();
        void insert(string x);
        bool find(string x);
        int hash(string x);
        bool checkprime(unsigned int p);
        int getNextPrime(unsigned int  n);
        int getMaxsize();
        int getCount();
    private:
        int tableSize;
        int max_size;
        list<string> *table;
        int count;
        unsigned int prime;
};

#endif