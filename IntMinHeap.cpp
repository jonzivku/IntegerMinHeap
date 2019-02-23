// Jon Zivku, jzivku, jonzivku@me.com, IntMinHeap.cpp
// Assignment 2: Integer Minimum Heap and Priority Queue

#include "IntMinHeap.h"

IntMinHeap::IntMinHeap(int c){
  capacity = c;
  size = 0;
  A = new int[capacity];
}

IntMinHeap::~IntMinHeap(){
  delete [] A;
}

int *IntMinHeap::heapsort(){
  //placeholder
}

string IntMinHeap::toString(){
  //placeholder
}

bool IntMinHeap::heapInsert(int x){
 // returns false if heap is full
  if(isFull())
    return false;
  // returns true on successful insert
  else
    //run heapInsert
    return true;
}

int IntMinHeap::minimum(){
  // returns the root A[0] of the heap
}

int IntMinHeap::extractMin(){
  // what happens with an empty heap? public function

  // removes and returns the root A[0] of the heap
  min = A[0];

}

void IntMinHeap::decreaseKey(int i, int k){
  // decreases a key 
}


int IntMinHeap::minOf3(int a, int b, int c){
  // must check bounds!
}

int IntMinHeap::left(int p){
  // does this need to check bounds? every child has a parent
  // but not every parent has a child

  return (2*p + 1);
}

int IntMinHeap::right(int p){
  return (2*p + 2);
}

int IntMinHeap::parent(int c){
  return 
}

void IntMinHeap::buildHeap(){
  // placeholder
}

void IntMinHeap::heapify(int p){
  // placeholder
}
