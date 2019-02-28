// Jon Zivku, jzivku, jonzivku@me.com, IntMinHeap.cpp, A02
// Integer Minimum Heap and Priority Queue

#include <sstream>
#include <iostream>
#include <iomanip>
#include "IntMinHeap.h"

using std::stringstream;
using std::endl;
using std::cout;

IntMinHeap::IntMinHeap(int c){
  capacity = c;
  size = 0;
  A = new int[capacity];
}

//overloaded constructor for sort, print, quit
IntMinHeap::IntMinHeap(int *B, int c, int s){
  capacity = c;
  size = s;
  A = new int[capacity];
  for(int i = 0; i < size; i++){
    A[i] = B[i];
  }
  buildHeap();
  std::pair<int*,int> ASort = heapsort();
  //int *ASort = heapsort();
  for(int i = 0; i < size; i++)
    cout << std::setfill('0') << std::setw(9) << ASort.first[i] << endl;

  delete [] ASort.first;
}

IntMinHeap::~IntMinHeap(){
  delete [] A; A = NULL;
}

std::pair<int*, int> IntMinHeap::heapsort(){
  //this creates a new array ASort that is a copy of A
  //ASort is what will be returned.
  int *ASort = new int[size];
  //deep copy ASort = A
  for(int i = size - 1; i >= 0; i--){
    ASort[i] = A[i];
  }
  //now we are going to sort A
  int tempSize = size; //store size before running the sort
  for(int i = size - 1; i > 0 ; i--){
    swap(i,0);
    size--;
    heapify(0);
  }//A is now sorted, and ASort is unsorted
  
  size = tempSize; //return size to its original value
  //now time to swap pointers of A and ASort
  int *temp = ASort;
  ASort = A;
  A = temp; temp = 0;

  return std::make_pair(ASort, size);
}

//uses <sstream>
string IntMinHeap::toString(){
  // example spec: heap size 10: 1, 2, 4, 5, 3, 8, 6, 10, 9, 7
  stringstream ss;
  string str;
  ss << "heap size " << size << ":";
  for(int i = 0; i < size; i++){
    ss << " " << A[i] << ",";
  }
  str = ss.str();
  if(size > 0)
    str.pop_back();
  return str;
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
  if( i >= size || i < 0)
    return;
  // decreases the value of  a key
  if(A[i] > k){
    A[i] = k;
    while (i > 0 && A[parent(i)] > A[i]){
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
void IntMinHeap::buildHeap(){
  for(int i = (size/2) - 1; i >= 0; i--)
    heapify(i);
}

void IntMinHeap::heapify(int p){
  if (p < size && p >=0){
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
