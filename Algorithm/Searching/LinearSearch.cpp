#include <cstdlib>

#include <cinttypes>
#include <vector>

// procedure linear_search (vector, value)
template <typename T>
size_t linear_search(std::vector<T> vector, T elem) {

   // for each item in the vector
   for (size_t index = 0; index < vector.size(); ++index) {
      // if match item == value
      if (vector[index] == elem){
         // return the item's location
         return index;
      }  // end if
   }  // end for
   return -1;

}  // end procedure
