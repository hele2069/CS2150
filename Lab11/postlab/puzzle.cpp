// Yiwei He yh9vhg puzzle.zpp 12/2/2021

#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iostream>
#include "puzzle.h"

using namespace std;
int DIRECTIONS[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int> > CORRECT  = {{1,2,3},{4,5,6},{7,8,0}};

/**
 * @class puzzle class. 
 * @exception exception. 
 */
puzzle::puzzle(vector<vector<int> > grid){
    p = grid;
    queue<pair<vector<vector<int> >, int> > q;
    set<vector<vector<int> > > vis;
}

void puzzle::addFirst(vector<vector<int>  > grid){
    q.push({grid,0});
}

void puzzle::addNeighbor(vector<vector<int> > grid, int len){
    int x = 0;
    int y = 0;
    int a = 0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (grid[i][j] == 0){
                x = i;
                y = j;
                break;
            }
        }
    }
    for (int i=0;i<4;i++){
        vector<vector<int> > newGrid = grid;
        if (DIRECTIONS[i][0]+x < 0 || DIRECTIONS[i][0]+x > 2 || DIRECTIONS[i][1]+y < 0 || DIRECTIONS[i][1]+y > 2){
            continue;
        }else{
            a = grid[x+DIRECTIONS[i][0]][y+DIRECTIONS[i][1]];
            newGrid[x][y] = a;
            newGrid[x+DIRECTIONS[i][0]][y+DIRECTIONS[i][1]] = 0;
            if (vis.find(newGrid) == vis.end()){
                q.push({newGrid,len+1});
                vis.insert(newGrid);
            }
        }
    }
}

bool puzzle::equals(vector<vector<int> > grid1,vector<vector<int> > grid2){
    bool equal = true;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (grid1[i][j] != grid2[i][j]){
                equal = false;
            }
        }
    }
    return equal;
}

int puzzle::BFS(){
    addFirst(p);
    vis.insert(p);
    while(!q.empty()){
        vector<vector<int> > first = q.front().first;
        int length = q.front().second;
        if (equals(first, CORRECT)){
            return length;
        }else{
            addNeighbor(first,length);
            q.pop();
        }
    }
}

bool puzzle::possible(){
    int inversion = 0;
    vector<int> test;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            test.push_back(p[i][j]);
        }
    }
    for (int i=0;i<8;i++){
        for (int j=i+1;j<9;j++){
            if (test[j] && test[i] &&  test[i] > test[j])
                  inversion++;
        }
    }
    return inversion %2 == 0;
}

int main(){
    cout<< "Enter puzzle"<<endl;
    string x;
    getline(std::cin,x);
    string token1 = x.substr(0,1);
    string token2 = x.substr(2,3);
    string token3 = x.substr(4,5);
    vector<int> vector1 = {};
    vector1.push_back(stoi(token1));
    vector1.push_back(stoi(token2));
    vector1.push_back(stoi(token3));
    getline(std::cin,x);
    string token4 = x.substr(0,1);
    string token5 = x.substr(2,3);
    string token6 = x.substr(4,5);
    vector<int> vector2 = {};
    vector2.push_back(stoi(token4));
    vector2.push_back(stoi(token5));
    vector2.push_back(stoi(token6));
    getline(std::cin,x);
    string token7 = x.substr(0,1);
    string token8 = x.substr(2,3);
    string token9 = x.substr(4,5);
    vector<int> vector3 = {};
    vector3.push_back(stoi(token7));
    vector3.push_back(stoi(token8));
    vector3.push_back(stoi(token9));
    vector<vector<int> > g;
    g.push_back(vector1);
    g.push_back(vector2);
    g.push_back(vector3);
    puzzle pu = puzzle(g);
    if (pu.possible()){
        int a = pu.BFS();
        cout<<"Solving puzzle"<<endl;
        cout<< a <<endl;
    }else{
        cout<<"Solving puzzle"<<endl;
        cout<<"IMPOSSIBLE"<<endl;
    }
}