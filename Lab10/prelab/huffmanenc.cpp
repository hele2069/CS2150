// Yiwei He yh9vhg huffmanenc.cpp 11/20/2021

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "heap.h"
#include "huffmanNode.h"
#include <cstdlib>
using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Must provide file name as parameter!" << endl;
        exit(1);
    }
     FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    vector<huffmanNode*> chars;
    char g;
    while((g = fgetc(file)) != EOF && g >= 0x20 && g <= 0x7e || g=='\n'){
        if (g == '\n'){
            continue;
        }
        bool found = true;
        for (int i = 0; i < chars.size(); i++){
            if (chars[i]->getChar() == g){
                chars[i]->incNum();
                found = false;
                break;
            }
        }
        if (found){
            huffmanNode * node = new huffmanNode(g);
            chars.push_back(node);
        }
    }
    heap* frequency = new heap(chars);

    int distinct = frequency->size();

    while (frequency->size()>1){
        huffmanNode* dummy = new huffmanNode();
        huffmanNode * left = frequency->findMin();
        left->setCode("0");
        dummy->setLeft(left);
        frequency->deleteMin();
        huffmanNode * right = frequency->findMin();
        right->setCode("1");
        dummy->setRight(right);
        frequency->deleteMin();
        dummy->setNum(dummy->getLeft()->getNum() + dummy->getRight()->getNum());
        frequency->insert(dummy);
    }

    int total = frequency->get(1)->getNum();

    frequency->get(1)->enCode("");

    cout << "----------------------------------------" << endl;

    rewind(file);
    int compressed = 0;
    while((g = fgetc(file)) != EOF && g >= 0x20 && g <= 0x7e || g == '\n') {
        if (g == '\n'){
            continue;
        }
        for(int i = 0; i < chars.size(); i++){
            if (g == chars[i]->getChar()){
                cout<< chars[i]->getCode() << " ";
                compressed += chars[i]->getCode().length();
            }
        }
    }
    cout << endl;

    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << total<< " symbols that are encoded." << endl;
    cout << "There are " << distinct<< " distinct symbols used." << endl;
    cout << "There were " << total * 8 << " bits in the original file." << endl;
    cout << "There were " << compressed << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (double)total*8/compressed<< "." << endl;
    cout << "The cost of the Huffman tree is " << (double)compressed/total << " bits per character." << endl;
    
  return 0;
}
