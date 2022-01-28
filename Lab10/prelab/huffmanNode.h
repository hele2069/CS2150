// Yiwei He yh9vhg huffmanNode.h 11/20/2021

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <vector>
#include <string>
#include <map>
using namespace std;

class huffmanNode{
public:
  huffmanNode();
  huffmanNode(char x);
  ~huffmanNode();
  char getChar();
  void setChar(char x);
  int getNum();
  void incNum();
  huffmanNode* getLeft();
  huffmanNode* getRight();
  void setNum(int x);
  void setLeft(huffmanNode*& node);
  void setRight(huffmanNode*& node);
  string  getCode();
  void setCode(string x);
  void enCode(string s);
  bool isLeaf();

  
private:
  char chr;
  int num;
  string code;
  huffmanNode* left;
  huffmanNode* right;

  friend class heap;
  friend class huffmanenc;
};

#endif
