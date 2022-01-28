// Yiwei He yh9vhg puzzle.h 12/2/2021

#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>

using namespace std;

class puzzle{
    public:
        puzzle(vector<vector<int> > grid);
        void addFirst(vector<vector<int> > grid);
        void addNeighbor(vector<vector<int> > grid, int len);
        bool equals(vector<vector<int> > grid1,vector<vector<int> > grid2);
        int BFS();
        bool possible();

    private:
        vector<vector<int> > p;
        queue<pair<vector<vector<int> >, int> > q;
        set<vector<vector<int> > > vis;
};

#endif