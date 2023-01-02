#include <algorithm>
#include <cinttypes>
#include <cstdlib>
#include <vector>

// Procedure binary_search
size_t binary_search(std::vector<int> vector, int element) { 
   // Set lowerBound = 1
   int64_t inferior_limit = 1;
   // Set upperBound = n 
   int64_t superior_limit = vector.size();

   int64_t middle = -1;

   // while x not found
   while ( superior_limit >= inferior_limit ) {
      // set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      middle = inferior_limit + (superior_limit - inferior_limit) / 2;
      

      // if A[midPoint] < x
      if (vector[middle] < element){
         // set lowerBound = midPoint + 1
         inferior_limit = middle + 1;
      } else {
         // if A[midPoint] > x
         if (vector[middle] > element) {
            // set upperBound = midPoint - 1 
            superior_limit = middle - 1;
         } else {
            // EXIT: x found at location midPoint
            return middle;
         }
      }
   }  // end while   
   return -1;
}  // end procedure
