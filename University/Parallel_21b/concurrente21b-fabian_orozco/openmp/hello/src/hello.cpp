#include <iostream>

int main() {
  #pragma omp parallel
  {
    #pragma omp critical
    {
      std::cout << "Hello from secondary thread" << std::endl;
    }
  }
  #pragma omp parallel
  std::cout << "jiji\n";
}
