//Yiwei He yh9vhg 10/04/2021 TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
    stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree->left != NULL && tree->right != NULL) {
        cleanTree(tree->left);
        cleanTree(tree->right);
        delete tree;
    }
    else if (tree->left != NULL) {
        cleanTree(tree->left);
        delete tree;
    }
    else if (tree->right != NULL) {
        cleanTree(tree->right);
        delete tree;
    }
    else {
        delete tree;
    }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// insert a value into the tree
void TreeCalc::insert(const string& val) {
    if (val==("+") || val==("-") || val==("*") || val==("/")) {
        TreeNode * sign = new TreeNode(val);
        sign->right = expressionStack.top();
        expressionStack.pop();
        sign->left = expressionStack.top();
        expressionStack.pop();
        expressionStack.push(sign);
    }
    else {
        TreeNode * num = new TreeNode(val);
        expressionStack.push(num);
    }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    if (tree != NULL){
        cout << tree->value << " ";
        printPrefix(tree->left);
        printPrefix(tree->right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    if (tree != NULL) {
        if (tree->value==("+") || tree->value==("-") || tree->value==("*") || tree->value==("/")) {
            cout << "(";
        }
        printInfix(tree->left);
        if (tree->value==("+") || tree->value==("-") || tree->value==("*") || tree->value==("/")) {
            cout << " " << tree->value << " ";
        }
        else {
            cout << tree->value;
        }
        printInfix(tree->right);
        if (tree->value==("+") || tree->value==("-") || tree->value==("*") || tree->value==("/")) {
            cout << ")";
        }   
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    if (tree != NULL) {
        printPostfix(tree->left);
        printPostfix(tree->right);
        cout << tree->value << " ";
    }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    if (tree->value == "+") { 
        return calculate(tree->left) + calculate(tree->right);
    }
    else if(tree->value == "-") {
        return calculate(tree->left) - calculate(tree->right);
    }
    else if (tree->value == "*") {
        return calculate(tree->left) * calculate(tree->right);
    }
    else if (tree->value == "/") {
        return calculate(tree->left) / calculate(tree->right);
    }
    else {
        return std::stoi(tree->value);
    }   
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    return calculate(expressionStack.top());
}
