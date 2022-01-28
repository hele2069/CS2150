#Yiwei He yh9vhg 10/05/2021 Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g

AVL: AVLPathTest.o AVLTree.o AVLNode.o
	$(CXX) $(DEBUG)  AVLPathTest.o AVLTree.o AVLNode.o
	
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLNode.o: AVLNode.cpp AVLNode.h

.PHONY: clean
clean:
	-rm -f *.o ./a.out