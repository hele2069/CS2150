# Yiwei He yh9vhg Makefile 12/2/2021

CXX=g++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -std=c++11
DEBUG=-g
	
puzzle.o: puzzle.h puzzle.cpp
	$(CXX) $(DEBUG) puzzle.h puzzle.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out