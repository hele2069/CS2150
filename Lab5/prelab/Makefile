# Yiwei He yh9vhg 10/04/2021 Makefile

CXXFLAGS=-Wall

CXX=clang++ $(CXXFLAGS)
DEBUG=-g

BST: TreeCalc.o TreeCalcTest.o TreeNode.o
		$(CXX) $(DEBUG) TreeCalc.o TreeCalcTest.o TreeNode.o

TreeCalc.o: TreeCalc.cpp TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean

clean:
	-rm -f *.o a.out
