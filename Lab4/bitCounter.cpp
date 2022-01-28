//Yiwei He yh9vhg 09／23/2021 bitCounter.cpp

#include <iostream>
#include <limits.h>
#include <math.h>
#include <string>
using namespace std;

int count(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n%2 == 0) {
        return count(n/2);
    }
    else {
        return 1+count(n/2);
    }
}

string convert(int x) {
    string s;
    if (x>=0 && x<=9) {
        return to_string(x);
    } 
    else {
        s.push_back(char(x+55));
        return s;
    }
}

string converter(string n, int startBase, int endBase) {
    string converted;
    int baseTen = 0;
    int q = 0;
    for (int i = 0;i< n.length();i++) {
        char a = n.at(i);
        if (a>57) {
            baseTen += (a-55)*pow(startBase,n.length()-i-1);
        }
        else {
            baseTen += (a-48)*pow(startBase,n.length()-i-1);
        }
    }
    while(baseTen!=0) { 
        converted.insert(0,convert(baseTen%endBase));
        baseTen /= endBase;
    }
    return converted;
}

int main (int argc, char **argv) {
    int x = stoi(argv[1]);
    cout << x << " has "<< count(x) << " bit(s)" << endl;
    cout << argv[2] << " (base " << argv[3] << ") = " << converter(argv[2],stoi(argv[3]),stoi(argv[4])) << " (base " << argv[4] << ")" << endl;
    return 0;
}



