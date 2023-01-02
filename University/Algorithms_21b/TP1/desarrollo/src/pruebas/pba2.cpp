#include <iostream>
#include <math.h>
using namespace std;

void imprimir(int* array, int size) {
  for(int actual = 0; actual < size; ++actual) {
    cout << " " << array[actual];
  }
}

void print(int* array, int size) {
  cout << "[";
  imprimir(array, size);
  cout << " ]" << endl;
}

void imprimir2(int* array, int size) {
  for(int actual = 1; actual <= size; ++actual) {
    cout << " " << array[actual];
  }
}

void print2(int* array, int size) {
  cout << "[";
  imprimir(array, size);
  cout << " ]" << endl;
}



// ------------------------------------------------

// MAX-HEAPIFY(A, i)
void max_heapify(int* A, int i, int& length){
  // L = LEFT(i)
  int L = 2*i;
  // r = RIGHT(i)
  int r = 2*i+1;

  int largest = 0;
  // if L <= A.heap-size and A[L] > A[i]
  if (L <= length && A[L] > A[i]) {
    // largest = L
    largest = L;
  }
  // else largest = i
  else {
    largest = i;
  }
  // if r <= A.heap-size and A[r] > A[largest]
  if (r <= length && A[r] > A[largest]) {
    // largest = r
    largest = r;
  }
  // if largest ¡= i
  if(largest != i) {
    // exchange A[i] with A[largest]
    swap(A[i], A[largest]);
    // MAX-HEAPIFY(A, largest)
    max_heapify(A, largest, length);
  }
}

// BUILD-MAX-HEAP(A)
void build_max_heap(int* A, int& length) {
  // A.heap-size = A.length
  int A_heap_size = length;
  // for i = pisoA.length/2piso downto 1
  for(int i = floor(A_heap_size); i > 0; --i) {
    // MAX-HEAPIFY(A, i)
    max_heapify(A, i, length);
  }
}
// HEAPSORT(A)
void heapSort(int* A, int& length) {
  // BUILD-MAX-HEAP(A)
   build_max_heap(A, length);
  // for i = A.length downto 2
  for(int i = length; i > 1; --i) {
    // exchange A[1] with A[i]
    swap(A[1], A[i]);
    
    // A.heap-size = A.heap-size - 1
    --length;
    // MAX-HEAPIFY(A, 1)
    max_heapify(A,1, length);
  }
}

void heapsort(int* A, int n) {
    cout << "-----entra a HS-----" << endl;
    A--;
    heapSort(A,n);
}

int main() {
  int A[5] = {3,4,5,2,1};
  int size = sizeof(A)/sizeof(int);
  print(A,size);

  heapsort(A,size);
  print(A,size);


  return 0;
}