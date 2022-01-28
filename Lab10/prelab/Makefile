# Yiwei He yh9vhg Makefile 11/20/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g

HUFF: heap.o huffmanenc.o huffmanNode.o
	$(CXX) $(DEBUG)  heap.o huffmanenc.o huffmanNode.o
	
heap.o: heap.cpp heap.h huffmanNode.h

huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h

huffmanNode.o: huffmanNode.cpp huffmanNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out