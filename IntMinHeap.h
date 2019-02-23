// Jon Zivku, jzivku, jonzivku@me.com, intMinHeap.h 
// Assignment 2: Integer Minimum Heap and Priority Queue
#include <string>
using std::string;

class IntMinHeap{
 public:
  IntMinHeap(int);  // empty heap wth this capacity
  ~IntMinHeap();  // clean up allocated memory  
  int *heapsort();  // return sorted array from heap
  string toString();  
  bool heapInsert(int); // add element to heap; return success
  // min functions should return 0 in empty heaps 
  int minimum();  // return value of A[root]
  int extractMin(); // return and remove A[root]
  void decreaseKey(int i, int k);  // A[i] decreased to k
  bool isEmpty(){return size==0;}
  bool isFull(){return size==capacity;}  
 private:
  int indexOfMin(int p, int l, int r); // with bounds check!
  //pre-cond: p < size
  //postcond: returns the index of the least element at index in argument  
  int left(int p){return 2*p + 1;}
  int right(int p){return 2*p + 2;}
  int parent(int c){return c/2;}
  //  void buildHeap();  // convert array to a heap
  void heapify(int i);  // heapify at position i  
  void swap(int,int);
  //pre-cond: two valid 
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
  
};
