//Yiwei He yh9vhg 09／20/2021 prelab4.cpp

#include <iostream>
#include "limits.h"
using namespace std;

void sizeOfTest() {
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
    unsigned int max = UINT_MAX;
    cout << max << " + 1 = " << max+1 << endl;
}

void outputBinary(unsigned int x) {
    int count = 0;
    int temp[32] = {0};
    while(x != 0){
        count++;
        temp[32-count] = x % 2;
        x /= 2;
    }
    for (int i = 0; i < 32; i++){
        if (i % 4 == 3){
            cout << temp[i] << " ";
        }
        else{
            cout << temp[i];
        }
    }
    cout << endl;
}

int main(){
    unsigned int x;
    cin >> x;
    sizeOfTest();
    overflow();
    outputBinary(x);
    return 0;
}