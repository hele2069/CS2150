#Yiwei He yh9vhg 10/17/2021 Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g

WORDPUZZLE: hashTable.o wordPuzzle.o timer.o
	$(CXX) $(DEBUG)  hashTable.o wordPuzzle.o timer.o
	
hashTable.o: hashTable.cpp hashTable.h

wordPuzzle.o: hashTable.h wordPuzzle.cpp timer.h

timer.o: timer.h timer.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out