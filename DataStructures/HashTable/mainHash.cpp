#include "../../Common/Colors.hpp"
#include "../../Common/Utilities.cpp"
#include "HashTable.cpp"

#include <iostream>

using namespace std;

int main() {
  program_start_txt();
  
  HashTable h1(20);
  h1.insert(1).insert(2).insert(42).insert(4).insert(12).insert(14).insert(17)
    .insert(13).insert(37).insert(2);

  int64_t value = 37;
  int64_t position = h1.search(value);
  if ( position != -1) {
    std::cout << value << " found in the position " << position << std::endl;
  } else {
    std::cout << value << " not found" << std::endl;
  }
  h1.print_table();
  h1.delete_element(2);
  h1.print_table();
  
  return program_finish_txt();
}
