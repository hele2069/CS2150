// Yiwei He yh9vhg huffmanNode.cpp 11/23/2021

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include "huffmanNode.h"
using namespace std;

huffmanNode::huffmanNode(){
    code = "";
    num = 0;
    chr = '\0';
    left = NULL;
    right = NULL;
}

huffmanNode::huffmanNode(char x){
    code = "";
    num = 1;
    chr = x;
    left = NULL;
    right = NULL;
}

huffmanNode::~huffmanNode(){
}

char huffmanNode::getChar(){
    return chr;
}

void huffmanNode::setChar(char x){
  chr = x;
}

int huffmanNode::getNum(){
    return num;
}

void huffmanNode::incNum() {
  num += 1;
}

huffmanNode* huffmanNode::getLeft(){
    return left;
}

huffmanNode* huffmanNode::getRight(){
  return right;
}

void huffmanNode::setNum(int x){
     num = x;
}

void huffmanNode::setLeft(huffmanNode*& node){
     left = node;
}

void huffmanNode::setRight(huffmanNode*& node){
     right = node;
}

string huffmanNode::getCode(){
  return code;
}

void huffmanNode::setCode(string x){
  code = x;
}

void huffmanNode::enCode(string s){
  s+=code;
  if (isLeaf()){
    setCode(s);
    cout << getChar() << " " << getCode() <<endl;
  }
  else{
    left->enCode(s);
    right->enCode(s);
  }
}

bool huffmanNode::isLeaf() {
  return (left == NULL && right == NULL && chr != '\0');
}
