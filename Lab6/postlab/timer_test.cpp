//Yiwei He yh9vhg 10/17/2021 timer_test.cpp

#include <iostream>
#include "timer.h"
using namespace std;

int main (void) {
    timer t;
    t.start();
    // do something that takes some time...
    for (int i = 0; i < 1000000000; i++) {}
    t.stop();
    cout << t << endl;
    cout << t.getTime() << endl;
}
