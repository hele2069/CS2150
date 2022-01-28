#Yiwei He yh9vhg 10/04/2021 Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g

BST: BSTPathTest.o BinarySearchTree.o BinaryNode.o
	$(CXX) $(DEBUG)  BSTPathTest.o BinarySearchTree.o BinaryNode.o
	
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o ./a.out