//Yiwei He yh9vhg 10/17/2021 wordPuzzle.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
hashTable *table = new hashTable();
int rows, cols;
string s;
vector<string> output;
int countfound = 0;

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

void solve(){
    string last_word;
    for(int col=0;col<cols;col++){
        for(int row=0;row<rows;row++){
            for(int dirc=0;dirc<8;dirc++){
                last_word = "";
                for(int l=3;l<=table->getMaxsize();l++){
                    string wordsearch = getWordInGrid(row,col,dirc,l,rows,cols);
                    if(wordsearch==last_word){
                        break;
                    }
                    last_word=wordsearch;
                    if(wordsearch.length()<3){
                        continue;
                    }
                        if(table->find(wordsearch)){
                            switch (dirc) { 
                                case 0:
                                    s  =  "N (" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 1:
                                    s  =  "NE(" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 2:
                                    s  =  "E (" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 3:
                                    s  =  "SE(" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 4:
                                    s  =  "S (" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 5:
                                    s  =  "SW(" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 6:
                                    s  =  "W (" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                                case 7:
                                    s  =  "NW(" + to_string(row) + ", " + to_string(col) + "):        " + wordsearch;
                                    output.push_back(s);
                                    break;
                            }
                            countfound++;
                        }
                    }
                }
            }
        }
}

int main (int argc, char **argv){
    timer *t = new timer();
    t->start();
    ifstream file(argv[1]);
    string word;
    while(getline(file,word)){
        table->insert(word);
    }
    readInGrid(argv[2],rows,cols);
    solve();
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }
    cout << countfound << " words found" << endl;
    t->stop();
    return 0;
}