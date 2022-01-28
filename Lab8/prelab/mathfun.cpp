//Yiwei He yh9vhg 11/01/2021 mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

// Purpose: This main program produces a vector of random numbers
// between 0 and 99, then calls the externally defined function
// 'vecsum' to add up the elements of the vector.

// Originally written by Adam Ferrari, and updated by Aaron Bloomfield

int  main () {

    long  x,y, prod, powe;

    cout << "Enter integer 1:  ";
    cin >> x;
    cout << "Enter integer 2:  ";
    cin >> y;

    prod = product(x,y);
    powe = power(x,y);
    cout << "Product: " << prod << endl;
    cout << "Power: " << powe << endl;
    return 0;
}