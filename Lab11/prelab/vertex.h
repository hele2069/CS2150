// Yiwei He yh9vhg vertex.h 11/28/2021
#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class vertex{
    public:
        vertex(string name);
        void decDegree();
        void incDegree();
        string getTitle();
        int getIndegree();
        void addAdjacent(string x);
        vector<string> getAdjacent();

    private:
        string title;
        int  indegree;
        vector<string> adjacent;
};

#endif