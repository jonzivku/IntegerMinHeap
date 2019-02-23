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

//in progress, i'm tired
int *IntMinHeap::heapsort(){
  int *ASort = new int[size];
  for(int i = size - 1; i > 0 ; i--){
    
    swap(i,0);
    size--;
    heapify(0);
  }
  //sorts the heap into a new array which it returns. original heap is not altered
  
}

string IntMinHeap::toString(){
  //placeholder
}

// uses decreaseKey()
bool IntMinHeap::heapInsert(int x){
 // returns false if heap is full
  if(isFull())
    return false;
  // returns true on successful insert
  else{
    size++;
    A[size-1] = x+1; //must be greater than x for decreaseKey()
    decreaseKey(size-1, x);
    return true;
  }
}

int IntMinHeap::minimum(){
  if(size == 0)  //returns 0 on empty heap
    return 0;
  else  // returns the root A[0] of the heap
    return A[0];
}

int IntMinHeap::extractMin(){
  // returns 0 on empty heap
  if(isEmpty())
    return 0;
  // removes and returns the root A[0] of the heap
  int min = A[0];
  A[0] = A[size-1];
  size--;
  heapify(0);
  return min;
}

void IntMinHeap::decreaseKey(int i, int k){
  // decreases the value of  a key
  if(A[i] > k){
    A[i] = k;
    while (i > 0 && A[parent(i)] < A[i]){
      swap(i, parent(i));
      i = parent(i);
    }//while
  }//if
}

//finished
int IntMinHeap::indexOfMin(int p, int l, int r){
  int iOfMin = p;
  if(l < size && A[l] < A[iOfMin])
    iOfMin = l;
  if(r < size && A[r] < A[iOfMin])
    iOfMin = r;  
  return iOfMin;
}

// calls heapify()
//void IntMinHeap::buildHeap(){}

void IntMinHeap::heapify(int p){
  if (p < size){
    int n = indexOfMin(p, left(p), right(p));
    if(n != p){
      swap(n,p);
      heapify(n);
    }//if p <
  }//if n !=
}
void IntMinHeap::swap(int a, int b){
  if(a < size && b < size){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
  }  
}
