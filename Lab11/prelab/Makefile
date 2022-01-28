# Yiwei He yh9vhg Makefile 11/28/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g

GRAPH: topological.o vertex.o
	$(CXX) $(DEBUG)  topological.o vertex.o
	
topological.o: topological.cpp vertex.h

vertex.o: vertex.h vertex.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out