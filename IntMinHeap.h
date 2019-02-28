// Jon Zivku, jzivku, jonzivku@me.com, intMinHeap.h, A02 
// Integer Minimum Heap and Priority Queue
#include <string>
using std::string;

class IntMinHeap{
 public:
  IntMinHeap(int a);  // a > 0,empty heap wth this capacity
  ~IntMinHeap();  // clean up allocated memory  
  int *heapsort();
  //postcond: creates a new sorted array based on A. A is preserved 
  string toString();
  //pre-cond: none
  //postcond: returns a string of format "heap size 'size' : A[0], A[1], ...
  
  bool heapInsert(int); // add element to heap; return success
  //pre-cond: an integer, and !isFull()
  //postcond: returns true if the element is added to the heap
  int minimum();  // return value of A[root]
  //pre-cond: !isEmpty()
  //postcond: returns A[0]; returns 0 on empty heap.
  int extractMin(); // return and remove A[root]
  //pre-cond: !isEmpty()
  //postcond: returns A[0], element A[0] is removed, size--, heap maintained
  void decreaseKey(int i, int k);  // A[i] decreased to k
  //pre-cond: i < size, and an integer k
  //postcond: the value of A[i], is lowered to k, and the value is moved
  // so that heap property is maintained.
  bool isEmpty(){return size==0;}
  bool isFull(){return size==capacity;}
  int maxInd(){return size;}
 private:
  int indexOfMin(int p, int l, int r);
  //pre-cond: three array indecies. 0 <= p < size
  //postcond: returns the index of the least of three indexes in the argument
  int left(int p){return 2*p + 1;}
  int right(int p){return 2*p + 2;}
  int parent(int c){return (c-1)/2;}
  // unused here  void buildHeap();  // convert array to a heap
  void heapify(int i);// heapify at position i
  //pre-cond: 0 <= i < size
  //postcond: the heap is maintained
  void swap(int a,int b);
  //pre-cond: 0 <= [ab] < size
  //postcond: values at A[a] and A[b] have been swapped
  
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
  
};
