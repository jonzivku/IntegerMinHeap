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
  int indexOfMin(int parent, int left, int right); // with bounds check!
  //pre-cond: the index of the parent, and its left and right child
  //postcond: returns the index of the greatest element
  
  int left(int);
  //pre-cond: an index of the heap < size
  //postcond: returns the left child of the heap index
  int right(int);
  int parent(int);
  void buildHeap();  // convert array to a heap
  void heapify(int i);  // heapify at position i  
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
};
