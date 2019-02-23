// Jon Zivku, jzivku, jonzivku@me.com, intMinHeap.h 
// Assignment 2: Integer Minimum Heap and Priority Queue

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
  int minOf3(int, int, int); // with bounds check!
  int left(int);
  int right(int);
  int parent(int);
  void buildHeap();  // convert array to a heap
  void heapify(int i);  // heapify at position i  
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
};
