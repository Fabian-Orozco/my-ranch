#include <algorithm>
#include <cinttypes>
#include <cstdlib>
#include <vector>
#include <iostream>

//procedure Interpolation_Search():
int64_t interpolation_search(std::vector<int> vector, const int element) {
  // set Lo  →  0
  int64_t inferior = 0;
  // set Mid → -1
  int64_t middle = -1;
  // set Hi  →  N-1
  int64_t superior = vector.size()-1;

  // while X does not match
  while (inferior <= superior) {
    // Set Mid = Lo + ((Hi - Lo) / (A[Hi] - A[Lo])) * (X - A[Lo])
    middle = inferior + (((superior - inferior) / (vector[superior] 
    - vector[inferior])) * (element - vector[inferior]));

    if(vector[middle] == element) {
      return middle;
    } else {
      if(vector[middle] < element) {
      // if data is larger, data is in upper half 
      inferior = middle + 1;
      } else {
      // if data is smaller, data is in lower half 
      superior = middle - 1;
      }
    }        
  }  // end while
  return -1;
}  // end procedure
