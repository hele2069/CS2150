// Yiwei He yh9vhg threexinput.cpp 11/15/2021

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long threexplusone (int a);

int  main () {

    // delcare the local variables
    int  x,n, steps;

    cout << "Enter a number:  ";
    cin >> x;
    cout << "Enter iterations of subroutine: ";
    cin >> n;

    steps = threexplusone(x);
    cout << "Steps: " << steps << endl;
    return 0;
}