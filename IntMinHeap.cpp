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
  
  //sorts the heap into a new array which it returns. original heap is not altered
  
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
  if(size == 0)  //returns 0 on empty heap
    return 0;
  else  // returns the root A[0] of the heap
    return A[0];
}

int IntMinHeap::extractMin(){
  // returns 0 on empty heap
  
  // removes and returns the root A[0] of the heap
  int min = A[0];

  return min;
}

void IntMinHeap::decreaseKey(int i, int k){
  // decreases a key 
}


int IntMinHeap::indexOfMin(int p, int l, int r){

  // must check bounds
  int temp;
  
  
}

//finished
int IntMinHeap::left(int p){
  int c = 2*p + 1;
  if (c >= size) // must return -1 if no left child
    return -1;
  else
    return c;
}

//finished
int IntMinHeap::right(int p){
  int c = 2*p + 2;
  if (c >= size) //must return -1 if no right child
    return -1;
  else
    return c;
}

int IntMinHeap::parent(int c){
  //every child has a parent
  return c/2;
}

// calls heapify()
void IntMinHeap::buildHeap(){
  
}

void IntMinHeap::heapify(int p){
  // placeholder
}
