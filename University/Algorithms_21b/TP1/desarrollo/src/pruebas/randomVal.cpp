#include <iostream>
#include <random>

#include "Ordenador.h"

using namespace std;

int main() {
  int size = 50000;
  int A[size];
  random_device dev;
  mt19937 rng(dev());
  for (int i = 0; i < size; ++i) {
    uniform_int_distribution<mt19937::result_type> dist6(-size*10,size*10);
    A[i] = dist6(rng);
  }
  Ordenador ordenador;
  ordenador.mergesort(A,size);
  cout << A[0] << "  " << A[size/2] << "  "  << A[size-1];
  return 0;
}