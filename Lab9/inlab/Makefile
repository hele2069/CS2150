#Yiwei He yh9vhg 11/16/2021 Makefile

CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall 
DEBUG=-g

LL: linkedlist.o
	$(CXX) $(DEBUG)  linkedlist.o

linkedlist.o: linkedlist.c

.PHONY: clean
clean:
	-rm -f *.o a.out