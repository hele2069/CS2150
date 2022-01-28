// Yiwei He yh9vhg vertex.cpp 11/28/2021
#include <vector>
#include <string>
#include "vertex.h"

using namespace std;

vertex::vertex(string name){
    title = name;
    indegree = 0;
    vector<string> adj;
    adjacent = adj;
}

void vertex::decDegree(){
    indegree--;
}

void vertex::incDegree(){
    indegree++;
}

int vertex::getIndegree(){
    return indegree;
}

void vertex::addAdjacent(string x){
    adjacent.push_back(x);
}

vector<string> vertex::getAdjacent(){
    return adjacent;
}

string vertex::getTitle(){
    return title;
}