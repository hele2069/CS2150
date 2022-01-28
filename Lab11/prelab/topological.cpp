// Yiwei He yh9vhg topological.cpp 11/28/2021

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "vertex.h"
using namespace std;

/**
 * @class vector class. 
 * @exception exception. 
 */
vector<vertex*> topsort(vector<vertex*> x){
    vector<vertex*> sorted;
        //vector<vertex*> zero;
    while(sorted.size()<x.size()){
        for (int i = 0; i<x.size();i++){
            if(x[i]->getIndegree() == 0){
                sorted.push_back(x[i]);
                x[i]->decDegree();
                //zero.push_back(x[i]);
                for (int j = 0;j<x.size();j++){
                    for (int k = 0; k<x[j]->getAdjacent().size();k++){
                        if (x[i]->getTitle() == (x[j]->getAdjacent())[k]){
                            x[j]->decDegree();
                        }
                    }   
                }
            }
        }
    }
    return sorted;
}

int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    vector<vertex*> vertices;
    while(true){
        string s1, s2;
        file >> s1;
        file >> s2;
        if (s1 == "0" && s2 == "0"){
            break;
        }
        bool found1 = false;
        bool found2 = false;
        for (int i = 0; i<vertices.size();i++){
            if (vertices[i]->getTitle() == s2){
                vertices[i]->incDegree();
                vertices[i]->addAdjacent(s1);
                found2 = true;
            }
            if (vertices[i]->getTitle() == s1){
                found1 = true;
            }
        }
        if(!found1){
            vertex * v = new vertex(s1);
            vertices.push_back(v);
        }
        if(!found2){
            vertex * v = new vertex(s2);
            v->addAdjacent(s1);
            v->incDegree();
            vertices.push_back(v);
        }
    }

    

    vector<vertex*> sorted = topsort(vertices);
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i]->getTitle() << " ";
    }
    cout<<endl;

    // close the file before exiting
    file.close();
}