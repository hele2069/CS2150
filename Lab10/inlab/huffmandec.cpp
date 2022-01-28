// Yiwei He yh9vhg huffmandec.cpp 11/23/2021

// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

string output = "";

huffmanNode* root = new huffmanNode();

void buildTree(huffmanNode* node, string character, string prefix){
    if (prefix.length() == 0){
        return;
    }else{
        if (prefix.substr(0,1) == "0" && prefix.length() == 1){
            huffmanNode*  left = new huffmanNode();
            left->setCode(node->getCode() + "0");
            left->setChar(character[0]);
            node->setLeft(left);
            return;
        }else if (prefix.substr(0,1) == "1" && prefix.length() == 1){
            huffmanNode*  right = new huffmanNode();
            right->setCode(node->getCode() + "1");
            right->setChar(character[0]);
            node->setRight(right);
            return;
        }else if (prefix.substr(0,1) == "1" ){
            if (node->getRight() == NULL){
            huffmanNode*  right = new huffmanNode();
            right->setCode(node->getCode() + "1");
            node->setRight(right);
            buildTree(right,character,prefix.substr(1,prefix.length()));
            }else{
                buildTree(node->getRight(),character,prefix.substr(1,prefix.length()));
            }
        }else if (prefix.substr(0,1) == "0" ){
            if (node->getLeft() == NULL){
            huffmanNode*  left = new huffmanNode();
            left->setCode(node->getCode() + "0");
            node->setLeft(left);
            buildTree(left,character,prefix.substr(1,prefix.length()));
            }else{
                buildTree(node->getLeft(),character,prefix.substr(1,prefix.length()));
            }
        }
    }
}

void decode(huffmanNode* node, string bits){
    if (bits.length() == 0){
        output = output+node->getChar();
        return;
    }
    if (node->isLeaf()){
        output = output+node->getChar();
        decode(root, bits);
    }else{
        if (bits[0] == '0'){
            decode(node->getLeft(),bits.substr(1,bits.length()));
        }else if (bits[0] == '1'){
            decode(node->getRight(),bits.substr(1,bits.length()));
        }
    }

}

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;

        buildTree(root, character, prefix);
        // do something with the prefix code
        /*if(root->getRight()!=NULL){
            if(root->getRight()->getLeft()!=NULL){
            cout<< root->getRight()->getLeft()->getLeft()->getChar()<<root->getRight()->getLeft()->getLeft()->getCode()<<endl;}
        }*/
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string output;
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    decode(root, allbits);
    // at this point, all the bits are in the 'allbits' string
    cout << output<<endl;
    // close the file before exiting
    file.close();
}