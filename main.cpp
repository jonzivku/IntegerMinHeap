// Jon Zivku, jzivku, jonzivku@me.com, main.cpp, A02
// Integer Minimum Heap and Priority Queue

/*
  This program demonstrates heapsort and storage of integers in a heap. 
  Status: working/tested

  notes: had a tricky time wrapping my brain around decreaseKey(), which led to
  an issue where i had a heap with heap property maintained, but that had a
  different output than the provided spec. Turns out that I had parent(i)=i/2,
  instead of (i-1)/2. 
  After the lecture on 2/27, I just had to implement the pair, mostly cause
  I had never used one. Also I overloaded the constructor for IntMinHeap
  per our email. This let me make an alternate main for more thorough testing 
  of heapsort (2400000 random numbers in, 2400000 sorted numbers out)
*/
#include <iostream>
#include <sstream>
#include "IntMinHeap.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
  IntMinHeap daHeap(2400000);
  
  int temp;
  while(cin >> temp){
    //if temp > 0, insert. print "insert: temp"
    if(temp > 0){
      daHeap.heapInsert(temp);
      cout << "insert: " << temp << endl;
    }
     
    if(temp == 0){
      // print "heap size 'size': daHeap.toString endl
      cout << daHeap.toString() << endl;
    }
    
    if(temp == -1){
      cout << "extract min: " << daHeap.extractMin() << endl;
    }
    
    if(temp == -2){
      std::pair<int*, int> sortDaHeap = daHeap.heapsort();
      //stringstream ss;
      cout << "sorted array: [";
      for(int i = 0; i < sortDaHeap.second; i++){
	cout << sortDaHeap.first[i];
	if(i < sortDaHeap.second - 1)
	  cout << ", ";
	
      }
      cout << "]" << endl;
      delete [] sortDaHeap.first;
    }
  }
  return 0;
}

