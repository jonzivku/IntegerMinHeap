# makefile for p2, for an integer minimum heap and heapsort

# defining target dependencies and files
p2: main.o IntMinHeap.o
	g++ -o p2 main.o IntMinHeap.o -Wall

# defining how each object file is to be built
main.o: main.cpp IntMinHeap.h
	g++ -c main.cpp -Wall

IntMinHeap.o: IntMinHeap.cpp IntMinHeap.h
	g++ -c -std=c++11 IntMinHeap.cpp -Wall

# clean up
clean:
	rm -f p2 *.o *~
