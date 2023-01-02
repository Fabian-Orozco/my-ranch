#include "Colors.hpp"
#include "Utilities.cpp"

#include <cinttypes>
#include <iostream>
#include <vector>

int main() {
  program_start_txt();
  std::vector<int64_t> vctr(5);
  vctr.insert(vctr.begin(),5);
  std::cout << "elem: " << vctr[0] << std::endl;
  return program_finish_txt();
}
