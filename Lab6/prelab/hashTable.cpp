//Yiwei He yh9vhg 10/17/2021 hashTable.cpp

#include "hashTable.h"
#include <list>
#include <string>

using namespace std;

hashTable::hashTable(){
    table  = new list<string>[1000000];
    tableSize = 100000;
    max_size = 0;
    count = 0;
}

void hashTable::insert(string x){
    int key = hash(x);
    if(x.length() > max_size){
        max_size = x.length();
    }
    (table)[key].push_back(x);
    count = count+1;
}

bool hashTable::find(string x){
    int key = hash(x);
    for(auto value : (table)[key]){
        if (value.compare(x) == 0){
            return true;
        }
    }
    return false;
}

int hashTable::hash(string key){
    int hash = 0;
    int index;
    for (int i = 0;i<key.length();i++){
        hash = hash+(int)key[i];
    }
    index = hash % tableSize;
    return index;
}

int hashTable::getMaxsize(){
    return max_size;
}

int hashTable::getCount(){
    return count;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}