# Yiwei He yh9vhg Makefile 11/30/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -std=c++11
DEBUG=-g

TRAVEL: middleearth.o traveling.o
	$(CXX) $(DEBUG)  middleearth.o traveling.o
	
middleearth.o: middleearth.cpp middleearth.h

traveling.o: middleearth.h traveling.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out