# Yiwei He yh9vhg Makefile 11/23/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g

HUFF: heap.o huffmandec.o huffmanNode.o
	$(CXX) $(DEBUG)  heap.o huffmandec.o huffmanNode.o
	
heap.o: heap.cpp heap.h huffmanNode.h

huffmandec.o: huffmandec.cpp heap.h huffmanNode.h

huffmanNode.o: huffmanNode.cpp huffmanNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out